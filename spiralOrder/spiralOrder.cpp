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

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) 
            return {};
        int m = matrix.size(), n = matrix[0].size();
        vector<int> spiral;
	//cout << "size : " << << endl
        int u = 0, d = m - 1, l = 0, r = n - 1, k = 0;
        while (true) {
            
            for (int col = l; col <= r; col++) 
                spiral.push_back(matrix[u][col]);
            if (++u > d) 
                break;
      
            
            for (int row = u; row <= d; row++) 
                spiral.push_back(matrix[row][r]);
            if (--r < l) 
                break;
         
            
            for (int col = r; col >= l; col--) 
                spiral.push_back(matrix[d][col]);
            if (--d < u) 
                break;
       
            
            for (int row = d; row >= u; row--) 
                spiral.push_back(matrix[row][l]);
            if (++l > r) 
                break;
        }
        return spiral;
    }
};
int main(int argc, const char *argv[])
{
	Solution s;
	std::vector<int> ivec0 = {1,2,3,4}; //不使用列表初始化用构造函数难以实现
	std::vector<int> ivec1 = {5,6,7,8}; //不使用列表初始化用构造函数难以实现
	std::vector<int> ivec2 = {5,6,7,8}; //不使用列表初始化用构造函数难以实现
	std::vector<int> ivec3 = {5,6,7,8}; //不使用列表初始化用构造函数难以实现
	std::vector<int> ivec4 = {5,6,7,8}; //不使用列表初始化用构造函数难以实现
	std::vector<int> ivec5 = {9,10,11,12}; //不使用列表初始化用构造函数难以实现
        std::vector<std::vector<int>> vec = {ivec0,ivec1,ivec2,ivec3,ivec4,ivec5};
	auto v = s.spiralOrder(vec);
	cout << "size" << v.size() << endl;
	for(auto a:v){
		cout <<"element : " << a << endl;
	}


	return 0;
}


/********************************** END **********************************************/

