//
// Created by A on 2026/10/18.
//
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class solution
{
public:
    vector<int> range_addition(vector<pair<int,int>>& events,vector<int>& nums)
    {
        vector<int> diff(nums.size());
        for (auto& event:events)
        {
            int begin=event.first;
            int index=begin-1;
            int val=event.second;
            diff[index]+=val;
        }
        int add=0;
        for (int i=0;i<nums.size();i++)
        {
            add+=diff[i];
            nums[i]+=add;
        }
        return nums;
    }
};

int main()
{
    int N,Q;
    cin>>N>>Q;
    vector<int> nums(N);
    for (int& num:nums)
    {
        cin>>num;
    }
    vector<pair<int,int>> events;
    for (int i=0;i<Q;i++)
    {
        int r,l,x;
        cin>>r>>l>>x;
        events.push_back({r,x});
        events.push_back({l,-x});
    }
    solution s;
    vector<int> res=s.range_addition(events,nums);
    for (int& val:res)
    {
        cout<<val<<" ";
    }
}