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

#include <vector>  
#include <map>
#include <iostream>
using namespace std;


template <typename T1, typename T2>  
auto compose(T1 t1, T2 t2) -> decltype(t1 + t2)  
{  
	   return t1+t2;  
}  
int main(int argc, const char *argv[])
{
	auto  a = 10,b =100;
	auto c = compose(a,b);
	cout << c <<endl;
	
	
	std::map<int, std::string> hash_map = {{1, "c++"}, {2, "java"}, {3,"python"}};  
	for(auto it : hash_map) {  
		cout << it.first << "\t" << it.second << endl;  
	} 


	return 0;
}


/********************************** END **********************************************/

