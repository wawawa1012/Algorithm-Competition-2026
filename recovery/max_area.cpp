//
// Created by A on 2026/9/26.
//
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class solution
{
public:
    int max_area(const vector<int>& nums)
    {
        int left=0,right=nums.size()-1;
        int maxArea=min(nums[left],nums[right])*(right-left);
        {
            while (right>left)
            {
                if (nums[right]>nums[left]) left++;
                else right--;
                maxArea=max(maxArea,min(nums[left],nums[right])*(right-left));
            }
            return maxArea;
        }
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