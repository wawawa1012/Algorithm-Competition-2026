//
// Created by A on 2026/9/26.
//
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;
class solution
{
public:
    int subarray_sum(const vector<int>& nums,int target)
    {
        int sum=0,res=0;
        unordered_map<long long, int> cnt;
        cnt[0]=1;
        for (int j=0;j<nums.size();j++)
        {
            sum+=nums[j];
            res+=cnt[sum-target];
            cnt[sum]+=1;
        }
        return res;
    }
};
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for (int& num:nums)
    {
        cin>>num;
    }

    solution s;
    cout<<s.subarray_sum(nums,k);
}