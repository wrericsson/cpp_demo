/*
 **************************************************************************************
 *       Filename:  hashm.cpp
 *    Description:   source file
 *
 *        Version:  1.0
 *        Created:  2017-03-10 10:45:45
 *
 *       Revision:  initial draft;
 **************************************************************************************
 */
#include <map>
#include <unordered_map>
#include <vector>
#include <stdio.h>
#include <iostream>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target);
	vector<int> twoSum_o(vector<int>& nums, int target);
};
vector<int> Solution::twoSum(vector<int>& nums, int target){
	vector<int> v;
	vector<int>::iterator it = nums.begin(),it_aux = nums.begin();
	for (it = nums.begin(); it < nums.end(); it++) {
		for (it_aux = nums.begin() + 1; it_aux < nums.end(); it_aux++) {
			if ( (*it_aux) == (target - *it)) {
				v.push_back(*it_aux);
				v.push_back(*it);
				return v;
			}
		}
	}    
}

vector<int> Solution::twoSum_o(vector<int>& nums, int target){
	unordered_map<int, int> hash;
	vector<int> result;
	for (int i = 0; i < nums.size(); i++) {
		int numberToFind = target - nums[i];

		//if numberToFind is found in map, return them
		if (hash.find(numberToFind) != hash.end()) {
			//+1 because indices are NOT zero based
			result.push_back(hash[numberToFind] + 1);
			result.push_back(i + 1);			
			return result;
		}

		//number was not found. Put it in the map.
		hash[nums[i]] = i;
	}
	return result;
}
int main(int argc, const char *argv[])
{
	vector<int> v3;
	vector<int> sum;
	sum.push_back(2);	
	sum.push_back(7);	
	sum.push_back(11);	
	sum.push_back(15);	
	sum.push_back(105);	
	Solution so;
	v3 = so.twoSum_o(sum,9);	
	for(int i=0;i<v3.size();i++)
	{
		cout << v3[i] << endl;
	}
return 0;
}


/********************************** END **********************************************/

