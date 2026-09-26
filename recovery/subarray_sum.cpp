//
// Created by A on 2026/9/26.
//
#include <vector>
#include <iostream>
using namespace std;
class solution
{
public:
    int subarray_sum(const vector<int>& nums,int target)
    {
        int res=0;
        vector<int> prefix_sum(nums.size()+1);
        prefix_sum[0]=0;
        prefix_sum[1]=nums[0];
        for (int i=2;i<nums.size()+1;i++)
        {
            prefix_sum[i]=nums[i-1]+prefix_sum[i-1];
        }
        int l=0,r=0,sum=prefix_sum[r+1]-prefix_sum[l];
        while (sum<target)
        {
            r++;
            sum=prefix_sum[r+1]-prefix_sum[l];
        }
        l++;
        if (sum==target) res++;
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

}