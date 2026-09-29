//
// Created by A on 2026/9/27.
//
#include <iostream>
#include <vector>
using namespace std;
class solution
{
public:
    vector<int> remove_duplicates(vector<int>& nums)
    {
        int slow=0,fast=1;
        while (fast<nums.size())
        {
            if (nums[slow]!=nums[fast])
            {
                slow++;
                nums[slow]=nums[fast];
            }
               fast++;
        }
       nums.resize(slow+1);
        return nums;
    }
};

int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for (int& num:nums)
    {
        cin>>num;
    }
    solution s;
    vector<int> res=s.remove_duplicates(nums);
    for (int& val:res) cout<<val<<" ";
}