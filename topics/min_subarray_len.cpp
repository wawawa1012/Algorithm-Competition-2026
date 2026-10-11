//
// Created by A on 2026/10/11.
//总和>=S最小子数组长度.元素都是非负，可以用滑动窗口
//想法是先扩张，再缩短，直到右边到末尾。双指针
#include <iostream>
#include <vector>
using namespace std;

class solution
{
public:
    int min_subarray_len(const vector<int>& nums,long long S)
    {
        int min_len=INT_MAX;
        int left=0;
        const int n=nums.size();
        long long sum=0;
        for (int right=0;right<n;right++)
        {
            sum+=nums[right];
                while (sum>=S)
                {
                    min_len=min(min_len,right-left+1);
                    sum-=nums[left];
                    left++;
                }
        }
        if (min_len==INT_MAX) return 0;
        return min_len;
    }
};

int main()
{
    int n;
    long long S;
    cin>>n>>S;
    vector<int> nums(n);
    for (int& num:nums)
    {
        cin>>num;
    }
    solution s;
    cout<<s.min_subarray_len(nums,S);
    return 0;
}