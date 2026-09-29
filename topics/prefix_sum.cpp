//
// Created by A on 2026/9/28.
//
#include <iostream>
#include <vector>
using namespace std;
class solution
{
public:
    vector<long long> build_prefix(vector<int>& nums)
    {
        vector<long long> prefix(nums.size()+1);
        prefix[0]=0;
        prefix[1]=nums[0];
        for (int i=2;i<prefix.size();i++)
        {
            prefix[i]=prefix[i-1]+nums[i-1];
        }
        return prefix;
    }
};

int main()
{
    int n,q;
    cin>>n>>q;
    vector<int> nums(n);
    vector<pair<int,int>> pairs(q);
    for (int& num:nums)
    {
        cin>>num;
    }
    for (auto& pair:pairs)
    {
        cin>>pair.first>>pair.second;
    }
    solution s;
    vector<long long> prefix=s.build_prefix(nums);
    for (auto& pair:pairs)
    {
        cout<<prefix[pair.second]-prefix[pair.first-1]<<endl;
    }
    return 0;
}