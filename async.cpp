/*
 **************************************************************************************
 *       Filename:  async.cpp
 *    Description:   source file
 *
 *        Version:  1.0
 *        Created:  2018-09-28 10:43:47
 *
 *       Revision:  initial draft;
 **************************************************************************************
 */



#include <iostream>
#include <future>
#include <chrono>

bool is_prime(int x)
{
    std::cout << " $$$$$$$$  is prime" << x << std::endl;
    for(int i=2;i<x;i++)
    {
    	std::cout << " @@@@@@@@@@@@@@@@@@  is prime"<< std::endl;
        if(x%i==0){
            std::cout << "hahahhaa" <<std::endl;
		return false;
	}
	std::cout << "function" << std::endl;
        return true;
    }
    	std::cout << " @@@@@@@@@@@@@@@@@@  is prime"<< std::endl;
}

int main()
{
    std::future <bool> fut = std::async(is_prime,4554);

    std::cout<<"wait,Checking" << std::endl;
    std::chrono::milliseconds span(10);
    while(fut.wait_for(span)==std::future_status::timeout)
        std::cout<<'.'<<std::flush;
        bool x = fut.get();
        std::cout<<"\n4444444444444444443"<<(x?" is":"is not") << " prime.\n";
        return 0;
}







/********************************** END **********************************************/

