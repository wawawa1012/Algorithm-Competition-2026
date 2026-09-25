//
// Created by A on 2026/9/25.
//
#include <chrono>
#include <iostream>
#include <vector>
using namespace std;
class solution
{
public:
    vector<int> searchRange(vector<int> n,int t)
    {
        int start=-1,end=-1;

        int left=0,right=n.size()-1;
        while (left<=right)
        {
            int mid=left+(right-left)/2;
            if (t==n[mid])
            {
                start=mid;
                right=mid-1;
            }
            else if (t>n[mid])  left=mid+1;
            else right=mid-1;
        }
        left=0,right=n.size()-1;
        while (left<=right)
        {
            int mid=left+(right-left)/2;
            if (t==n[mid])
            {
                end=mid;
                left=mid+1;
            }
            else if (t>n[mid])  left=mid+1;
            else right=mid-1;
        }
        return {start,end};
    }
};
int main()
{
    int n,target;
    cin>>n>>target;
    vector<int> nums(n);
    for (int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    solution s;
    vector<int> v=s.searchRange(nums,target);
    for (int x : v)
    {
        cout<<x<<" ";
    }
    return 0;
}
