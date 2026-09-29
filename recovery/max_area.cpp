//
// Created by A on 2026/9/28.
//
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class solution
{
public:
    int max_area(const vector<int>& nums)
    {
        int left=0,right=nums.size()-1;
        int res=(right-left)*min(nums[left],nums[right]);
        while (left<right)
        {
            if (nums[left]<nums[right])
            {
                left++;
            }
            else right--;
            res=max((right-left)*min(nums[left],nums[right]),res);
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
    cout<<s.max_area(nums);
    return 0;
}