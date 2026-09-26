//
// Created by A on 2026/9/26.
//
#include <iostream>
#include <vector>
using namespace std;
class solution{
public:
    vector<int> two_sum(const vector<int>& nums,int target)
    {
        int left=0,right=nums.size()-1;
        while (left<right)
        {
            int sum=nums[left]+nums[right];
            if (sum==target) return {left,right};
            else if (sum>target) right--;
            else left++;
        }
        return {-1,-1};
    }
};
int main()
{
    int n,target;
    cin>>n>>target;
    vector<int> nums(n);
    for (int& num:nums)
    {
        cin>>num;
    }
    solution s;
    vector<int> res=s.two_sum(nums,target);
    for (int num:res)
    {
        cout<<num<<" ";
    }
    return 0;
}