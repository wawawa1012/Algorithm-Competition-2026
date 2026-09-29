//
// Created by A on 2026/9/27.
//
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class solution
{
public:
    vector<int> two_sum(const vector<int>& nums,int target)
    {
        unordered_map<int,int> mp;
        for (int i=0;i<nums.size();i++)
        {
            if (mp.count(target-nums[i]))
            {
                return {mp[target-nums[i]],i};
            }
            else mp[nums[i]]=i;
        }
        return {-1,-1};
    }
};

int main()
{
    int n,target;
    cin>>n>>target;
    vector<int> nums(n);
    for (int& num:nums)
    {
        cin>>num;
    }
    solution s;
    vector<int> res=s.two_sum(nums,target);
    for (int& val:res) cout<<val<<" ";
    return 0;
}