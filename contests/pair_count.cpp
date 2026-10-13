//
// Created by A on 2026/10/13.
//
//看了一眼感觉类似前缀和，尝试这样做
//发现要用一个hashmap存当前下标后面每个元素多少个，不然超时
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class solution
{
public:
    long long pair_count(const vector<int>& nums,int target)
    {
        long long res=0;
        int size=nums.size();
        unordered_map<int,int> mp; //初始化hashmap
        vector<int> need(size);
        for (int i=0;i<size;i++)
        {
            mp[nums[i]]+=1;
            need[i]=target-nums[i];
        }

        for (int i=0;i<size;i++)
        {
            mp[nums[i]]-=1;
            res+=mp[need[i]];
        }
        return res;
    }
};

int main()
{
    int n,T;
    cin>>n>>T;
    vector<int> nums(n);
    for (int& num:nums)
    {
        cin>>num;
    }
    solution s;
    cout<<s.pair_count(nums,T);
    return 0;
}