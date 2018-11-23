/*
 **************************************************************************************
 *       Filename:  try_catch.cpp
 *    Description:   source file
 *
 *        Version:  1.0
 *        Created:  2018-11-23 17:51:05
 *
 *       Revision:  initial draft;
 **************************************************************************************
 */

#include <iostream>
#include <exception>

#include <execinfo.h>
#include <stdlib.h>

using namespace std;
/* 保存用户信息于message_;
 * 将堆栈信息存于stack_;*/
class Exception : public std::exception
{		  
	public:
		explicit Exception(const char* msg)
			: message_(msg)
		{
			fillStackTrace();
		}

		explicit Exception(const string& msg)
			: message_(msg)
		{
			fillStackTrace();
		}

                virtual ~Exception() throw ()
		{
		}

		virtual const char* what() const throw()
		{
			return message_.c_str();
		}

		const char* stackTrace() const throw()
		{
			return stack_.c_str();
		}
	private:
		std::string message_;
		std::string stack_; 
		void fillStackTrace()
		{
			const int len = 200;
			void* buffer[len];
			int nptrs = ::backtrace(buffer, len);
			char** strings = ::backtrace_symbols(buffer, nptrs);
			if (strings)
			{
				for (int i = 0; i < nptrs; ++i)
				{
					// TODO demangle funcion name with abi::__cxa_demangle
					stack_.append(strings[i]);
					stack_.push_back('\n');
				}
				free(strings);
			}
		}
		//
};
int main(int argc, const char *argv[])
{
	try
	{
		auto ret = [](int a) -> bool {
			cout << "lamda : " << a << std::endl;
			//throw runtime_error("in lamda\n");
			throw Exception("oops");
			//return true;
		}(999);
		//int* myarray= new int[100000];
	}
	catch (const Exception& e)
	{
		cout << "Standard exception: ------------------" << e.what() << endl;
		cout << "Standard exception: ------------------" << e.stackTrace() << endl;
	}
	return 0;
}



/********************************** END **********************************************/

