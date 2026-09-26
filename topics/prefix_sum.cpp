//
// Created by A on 2026/9/26.
//
#include <vector>
#include <iostream>
using namespace std;

class solution
{
public:
    vector<long long> prefix_sum(const vector<int>& nums)
    {
        int size=nums.size();
        vector<long long> prefix(size+1);
        prefix[0]=0;
        prefix[1]=nums[0];
        for (int i=2;i<size+1;i++)
        {
            prefix[i]=nums[i-1]+prefix[i-1];
        }
        return prefix;
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
    vector<pair<int, int>> a(q);
    for (auto &p : a)
    {
        cin >> p.first >> p.second;
    }
    solution s;
    vector<long long> prefix=s.prefix_sum(nums);
    for (auto &p:a)
    {
        cout<<prefix[p.second]-prefix[p.first-1]<<endl;
    }
}