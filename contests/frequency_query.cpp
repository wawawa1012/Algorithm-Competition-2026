//
// Created by A on 2026/10/12.
//
//想到建哈希表，索引来求
#include <iostream>
#include  <vector>
#include <unordered_map>
using namespace std;

class solution
{
public:
    unordered_map<int,int> mp;
    void build_map(const vector<int>& nums)
    {
        mp.clear();
        for (int i=0;i<nums.size();i++)
        {
            mp[nums[i]]+=1;
        }
    }
    int frequent_query(int x)
    {
        if (!mp.count(x)) return 0;
        else return mp[x];
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
    s.build_map(nums);
    for (int i=0;i<q;i++)
    {
        int x;
        cin>>x;
        cout<<s.frequent_query(x) << '\n';
    }
    return 0;
}