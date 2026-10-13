//
// Created by A on 2026/10/13.
//
#include <iostream>
#include <limits>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

class solution
{
public:
    unordered_map<int,int> mp;
    void build(const vector<int>& nums)
    {
        for (int i=0;i<nums.size();i++)
        {
            if (!mp.count(nums[i]))
            {
                mp[nums[i]]=i+1;
            }
        }
    }
    int query(int x)
    {
        if (!mp.count(x)) return -1;
        return mp[x];
    }
};

int main()
{
    int n,q;
    cin>>n>>q;
    vector<int> nums(n);
    for (int& num:nums)
    {
        cin>>num;
    }
    solution s;
    s.build(nums);
    for (int i=0;i<q;i++)
    {
        int x;
        cin>>x;
        cout<<s.query(x)<<endl;
    }
    return 0;
}