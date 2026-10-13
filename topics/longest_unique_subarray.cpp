//
// Created by A on 2026/10/13.
//
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class solution
{
public:
    int longest_unique_subarray(const vector<int>& nums)
    {
        int longest=0;
        unordered_map<int,int> mp;
        int left=0,right=0;
        for (int i = 0; i < nums.size(); ++i)
        {
            mp[nums[i]]+=1;
            while(mp[nums[right]]>1)
            {
                mp[nums[left]]--;
                left++;
            }
            longest=max(longest,right-left+1);
            right++;
        }
        return longest;
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
    cout<<s.longest_unique_subarray(nums);
    return 0;
}