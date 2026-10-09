//
// Created by A on 2026/10/9.
//
//这个题有印象，应该是贪心的思想。
//直觉是用数组存,和连续1那个题异曲同工
//一开始尝试用currBest存，发现行不通。决定存当前最小

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class solution
{
public:
    int max_profit(const vector<int>& nums)
    {
        int maxProfit=0;
        const int size=nums.size();
        vector<int> currMin(size);
        currMin[0]=nums[0];
        for (int i=1;i<size;i++)
        {
            currMin[i]=min(currMin[i-1],nums[i]);
            maxProfit=max(maxProfit,nums[i]-currMin[i-1]);
        }
        return maxProfit;
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
    cout<<s.max_profit(nums);
    return 0;
}