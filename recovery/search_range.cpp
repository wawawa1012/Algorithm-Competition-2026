//
// Created by A on 2026/9/27.
//
#include <iostream>
#include <vector>
using namespace std;
class solution
{
public:
    vector<int> search_range(const vector<int>& nums,int target)
    {
        int start=-1,end=-1;
        int l=0,r=nums.size()-1;
        while (l<=r)
        {
            int mid=l+(r-l)/2;
            if (nums[mid]==target)
            {
                start=mid;
                r=mid-1;
            }
            else if (nums[mid]>target) r=mid-1;
            else l=mid+1;
        }
        l=0,r=nums.size()-1;
        while (l<=r)
        {
            int mid=l+(r-l)/2;
            if (nums[mid]==target)
            {
                end=mid;
                l=mid+1;
            }
            else if (nums[mid]>target) r=mid-1;
            else l=mid+1;
        }
        return {start,end};
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
    vector<int> res=s.search_range(nums,target);
    for (int& val:res) cout<<val<<" ";
    return 0;
}