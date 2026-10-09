//
// Created by A on 2026/10/9.
//
//思路是小于0的
#include <iostream>
#include <vector>
using namespace std;
class solution
{
public:
    vector<int> sorted_squares(const vector<int>& nums)
    {
        vector<int> res;
        int n=nums.size();
        vector<int> a;
        int pos=n;
        for (int i=0;i<n;i++)
        {
            if (nums[i]<0)
            {
                a.push_back(nums[i]);
            }
            else
            {
                pos=i;
                break;
            }
        }
        int i=pos,j=pos-1;
        while (j>=0&&i<n)
        {
            if (nums[i]<=abs(a[j]))
            {
                res.push_back(nums[i]*nums[i]);
                i++;
            }
            else
            {
                res.push_back(a[j]*a[j]);
                j--;
            }
        }
        if (j>=0)
        {
            for (;j>=0;j--)
            {
                res.push_back(a[j]*a[j]);
            }
        }
        if (i<n)
        {
            for (;i<n;i++)
            {
                res.push_back(nums[i]*nums[i]);
            }
        }
        return res;
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
    vector<int> res=s.sorted_squares(nums);
    for (int& val:res)
    {
        cout<<val<<" ";
    }
}