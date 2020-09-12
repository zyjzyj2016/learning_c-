// permute.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> result;
    /*
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    vector<vector<int>> permute(vector<int> &nums) {
        // write your code here
		vector<int> choice;
		vector<int> trace;
		for(int i=0;i<nums.size();i++)
		{
			choice.push_back(0);
		}

		traceback(choice,trace,nums);
		return result;
    }

	void traceback(vector<int> &choice,vector<int> &trace,vector<int> &nums)
	{
		if(nums.size() == trace.size())
		{
			result.push_back(trace);
			return; 
		}
		else
		{
			//做决策
			for(int i=0;i<nums.size();i++)
			{
				//vector<int>::iterator it = find(choice.begin(),choice.end(),nums[i]);
				//选择列表中没有找到
				if(choice[i] != 1)
				{
					choice[i] = 1;
					trace.push_back(nums[i]);

					traceback(choice,trace,nums);
					choice[i] = 0;
					trace.pop_back();
				}
				
				
			}
				//撤回决策
		}
	}

};

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> nums;
	Solution test;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	test.permute(nums);
	return 0;
}

