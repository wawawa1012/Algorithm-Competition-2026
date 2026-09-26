//
// Created by A on 2026/9/26.
//
#include  <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class solution
{
public:
    vector<int> vec_sort(vector<int>& nums)
    {
        sort(nums.begin(),nums.end());
        return nums;
    }
    vector<int> vec_sort_reverse(vector<int>& nums)
    {
        sort(nums.begin(),nums.end(),greater<int>());
        return nums;
    }
};
int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for (int& num : nums)
    {
        cin>>num;
    }
    solution s;
    for (int num:s.vec_sort(nums))
    {
        cout<<num<<" ";
    }
    cout<<"\n";
    for (int num:s.vec_sort_reverse(nums))
    {
        cout<<num<<" ";
    }
    return 0;
}

