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
    vector<long long> range_addition(vector<pair<int,int>>& events,vector<long long>& nums)
    {
        vector<long long> diff(nums.size()+1);
        for (auto& event:events)
        {
            int begin=event.first;
            int index=begin-1;
            int val=event.second;
            diff[index]+=val;
        }
        long long add=0;
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
    vector<long long> nums(N);
    for (long long& num:nums)
    {
        cin>>num;
    }
    vector<pair<int,int>> events;
    for (int i=0;i<Q;i++)
    {
        int l,r,x;
        cin>>l>>r>>x;
        events.push_back({l,x});
        events.push_back({r+1,-x});
    }
    solution s;
    vector<long long> res=s.range_addition(events,nums);
    for (long long& val:res)
    {
        cout<<val<<" ";
    }
}
