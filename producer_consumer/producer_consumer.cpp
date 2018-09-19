/*
 **************************************************************************************
 *       Filename:  producer_consumer.cpp
 *    Description:   source file
 *
 *        Version:  1.0
 *        Created:  2018-09-19 13:44:10
 *
 *       Revision:  initial draft;
 **************************************************************************************
 */
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>


#include <iostream>           // std::cout
#include <thread>             // std::thread, std::this_thread::yield
#include <mutex>              // std::mutex, std::unique_lock
#include <condition_variable> // std::condition_variable

#include <unistd.h>
using namespace std;
sem_t blank_count;
sem_t data_count;

std::mutex mtx;
int cycle_queue[20];
void* producer_running(void* arg)
{
	int step = 0;
	while(1)
	{
		sem_wait(&blank_count);
		{
			std::unique_lock<std::mutex> lck(mtx);
			int data = rand()%1000;
			cycle_queue[step] = data;
			step++;
			step %= 20;
			printf("the producter is %d\n",data);
		}
		sem_post(&data_count); 
	}
}
void* consumer_running(void* arg)
{
	int step =0;
	while(1)
	{
		sleep(1);
		sem_wait(&data_count);
		{
			std::unique_lock<std::mutex> lck(mtx);
			int data = cycle_queue[step];
			step++;
			step %= 20;
			printf("the consumer is %d\n",data);
		}
		sem_post(&blank_count);
	}
}

int main(int argc, const char *argv[])
{
	sem_init(&blank_count,0,5);
	sem_init(&data_count,0,0);   
	std::thread producer_thread(producer_running,nullptr);
	std::thread consumer_thread(consumer_running,nullptr);
	producer_thread.join();
	consumer_thread.join();
	return 0;
}


/********************************** END **********************************************/

