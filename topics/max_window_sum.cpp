//
// Created by A on 2026/10/11.
//
//用一个滑动的sum记录当前最大和,初始化为极小值
#include <iostream>
#include <vector>
using namespace std;

class solution
{
public:
    long long max_window_sum(const vector<int>& nums,int k)
    {
        long long sum=INT_MIN;
        int n=nums.size();
        vector<long long> currSum(n-k+1);
        for (int i=0;i<k;i++)
        {
            currSum[0]+=nums[i];
            sum=currSum[0];
        }
        for (int i=k;i<n;i++)
        {
            currSum[i-k+1]=currSum[i-k]-nums[i-k]+nums[i];
            sum=max(sum,currSum[i-k+1]);
        }
        return sum;
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
    cout<<s.max_window_sum(nums,k);
    return 0;
}