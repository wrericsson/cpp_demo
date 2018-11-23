/*
 **************************************************************************************
 *       Filename:  hash.cpp
 *    Description:   source file
 *
 *        Version:  1.0
 *        Created:  2018-09-19 20:16:31
 *
 *       Revision:  initial draft;
 **************************************************************************************
 */


#include <iostream>  
#include <string>  
#include <unordered_set>  
using namespace std; 

int main(int argc, const char *argv[])
{
	
  std::unordered_set<std::string> myset = {"red","green","blue"};  
  
  std::string input;  
  std::cout << "color? " << endl;  
  getline (std::cin,input);  
  
  if(myset.count(input)){

    std::cout << input << " is in myset";  
  }else
    std::cout << "not found in myset";  
  //std::unordered_set<std::string>::const_iterator got = myset.find (input);  
  
  //if ( got == myset.end() )  
    //std::cout << "not found in myset";  
  //else  
    //std::cout << *got << " is in myset";  
  
  std::cout << std::endl;  
  
  return 0;  
}  


/********************************** END **********************************************/

