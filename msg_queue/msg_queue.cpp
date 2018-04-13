/*
 **************************************************************************************
 *       Filename:  c11.cpp
 *    Description:   source file
 *
 *        Version:  1.0
 *        Created:  2017-04-10 11:37:58
 *
 *       Revision:  initial draft;
 **************************************************************************************
 */

#include <queue>
#include <mutex>
#include <thread>
#include <chrono>
#include <memory>
#include <condition_variable>

using namespace std;


#define FUNCTION_SCOPE()  auto __scope_logger__ = create_scope_logger(__FUNCTION__)

std::shared_ptr<char> create_scope_logger(const char* functionName)
{
        char* pText = const_cast<char*>(functionName);
        printf("[%s] E \n", pText);
        return std::shared_ptr<char>(pText, [](char* p){ printf("[%s] X \n", p); });
}



typedef struct task_tag
{
	int data;
	task_tag( int i ) : data(i) { }
} Task, *PTask;

class MessageQueue
{
public:
	MessageQueue(){}
	~MessageQueue()
	{
		if ( !m_queue.empty() )
		{
			PTask pRtn = m_queue.front();
			delete pRtn;
		}

	}

	void PushTask( PTask pTask )
	{
		std::unique_lock<std::mutex> lock( m_queueMutex );
		m_queue.push( pTask );
		m_cond.notify_one();
	}

	PTask PopTask()
	{
		PTask pRtn = NULL;
		std::unique_lock<std::mutex> lock( m_queueMutex );
		while ( m_queue.empty() )
		{
			m_cond.wait_for( lock, std::chrono::seconds(1) );
		}

		if ( !m_queue.empty() )
		{
			pRtn = m_queue.front();
			if ( pRtn->data != 0 )
				m_queue.pop();
		}

		return pRtn;
	}

private:
	std::mutex m_queueMutex;
	std::condition_variable m_cond;
	std::queue<PTask> m_queue;
};

void thread_fun( MessageQueue *arguments )
{
	while ( true )
	{
		PTask data = arguments->PopTask();

		if (data != NULL)
		{
		    FUNCTION_SCOPE();
			printf( "Thread is: %d\n", std::this_thread::get_id() );
			printf("   %d\n", data->data );
			if ( 0 == data->data ) //Thread end.
				break;
			else
				delete data;
		}
	}

	return;
}

int main( int argc, char *argv[] )
{
    FUNCTION_SCOPE();
	MessageQueue cq;

#define THREAD_NUM 3
	std::thread threads[THREAD_NUM];

	for ( int i=0; i<THREAD_NUM; ++i )
		threads[i] = std::thread( thread_fun, &cq );

	int i = 100000;
	while( i > 0 )
	{
		Task *pTask = new Task( --i );
		cq.PushTask( pTask );
	}

	for ( int i=0; i<THREAD_NUM; ++i)
		threads[i].join();

	//system( "pause" );
	return 0;
}

/********************************** END **********************************************/

