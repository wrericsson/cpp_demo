/*
 **************************************************************************************
 *       Filename:  vector.cpp
 *    Description:   source file
 *
 *        Version:  1.0
 *        Created:  2018-10-17 16:44:43
 *
 *       Revision:  initial draft;
 **************************************************************************************
 */
#include <vector>
#include <iostream>
#include <string>


using namespace std;

int main(int argc, const char *argv[])
{
	std::string str ("index_112230");
	    std::string str1 ("index");
	vector<pair<int,int>> vec{{1,2},{2,3},{3,4}};
	//cout << vec[0].first << std::endl; 
	//cout << vec.size() << std::endl; 
	std::size_t found = str.find(str1);
	if( found!= std::string::npos ){
		cout << "found str in pool : "<< found << std::endl;
		std::string sub = str.substr(6,str.length());
		cout << "cut : " <<sub << std::endl;
		cout << "cut int : " <<std::stoi(sub) << std::endl;
	}
	return 0;
}



/********************************** END **********************************************/

