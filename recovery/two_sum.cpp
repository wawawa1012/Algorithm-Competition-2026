//
// Created by A on 2026/9/25.
//
#include <algorithm>
#include <iostream>
#include  <vector>
#include <unordered_map>
using namespace std;

class solution
{
public:
    vector<int> two_sum(vector<int>& nums,int target)
    {
        unordered_map<int,int> map;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (map.count(target - nums[i]))
            {
                return {map[target-nums[i]],i};
            }
            map[nums[i]]=i;
        }
        return {-1,-1};
    }
};
int main()
{
    int n,target;
    cin>>n>>target;
    vector<int> nums(n);
    for (int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    solution s;
    vector<int> res=s.two_sum(nums,target);
    for (int val:res)
    {
        cout<<val<<" ";
    }
    return 0;
}