//
// Created by A on 2026/10/8.
//
//思路：既然是返回最大值，我的想法是弄一个m作为buffer，存当前最大;再用curr存当前值，可推得是全局最优；
//但我写的时候发现一个当前值不好存，写在循环里面不是外面也不是，想着用数组
//如果要O(n),就只能线性扫描，用一个指针记录当前位置
#include <iostream>
#include <vector>
using namespace std;

class solution
{
public:
    int consecutive_ones(const vector<int>& nums)
    {
        int m=nums[0]==0?0:1;
        const int n=nums.size();
        vector<int> curr(n);
        curr[0]=nums[0]==0?0:1;
        for (int i=1;i<n;i++)
        {
            if (nums[i]==1) curr[i]=curr[i-1]+1;
            else
            {
                curr[i]=0;
                continue;//优化了性能，不想做无用功
            }
            m=max(m,curr[i]);
        }
        return m;
    }
};
int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for (int& num:nums) cin>>num;
    solution s;
    cout<<s.consecutive_ones(nums);
    return 0;
}