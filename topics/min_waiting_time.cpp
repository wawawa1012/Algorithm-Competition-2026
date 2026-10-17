//
// Created by A on 2026/10/17.
//
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class solution
{
public:
    long long sjf(vector<int>& nums)
    {
        sort(nums.begin(),nums.end(),[](const int a,const int b)
        {
            return a<b;
        });
        vector<int> waitingTime(nums.size());
        long long sum=0;
        waitingTime[0]=0;
        for (int i=1;i<nums.size();i++)
        {
            waitingTime[i]=waitingTime[i-1]+nums[i-1];
            sum+=waitingTime[i];
        }
        return sum;
    }
};

int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for (int& num:nums)
    {
        cin>>num;
    }
    solution s;
    cout<<s.sjf(nums);
}