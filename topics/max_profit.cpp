//
// Created by A on 2026/10/17.
//
#include <iostream>
#include <vector>
using namespace std;

class solution
{
public:
    int max_profit(const vector<int>& nums)
    {
        int maxProfit=0;
        int currMin=nums[0];
        for (int i=1;i<nums.size();i++)
        {
            maxProfit=max(maxProfit,nums[i]-currMin);
            currMin=min(currMin,nums[i]);
        }
        return maxProfit;
    }
};

int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for (int& num: nums)
    {
        cin>>num;
    }
    solution s;
    cout<<s.max_profit(nums);
    return 0;
}