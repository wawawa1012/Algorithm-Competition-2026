// 恰好 K 个奇数的子数组数量（自命题）
// 给定 N 个非负整数，统计恰好含 K 个奇数的非空连续子数组数量。
// 按下标区间区分，不同起止位置分别计数。
// 1 <= N <= 200000，0 <= K <= N，0 <= a[i] <= 1000000000。
// 输入第一行 N K，第二行 N 个整数；输出一个整数。
// 样例输入：
// 5 2
// 1 2 1 2 1
// 样例输出：4

#include <iostream>
#include <vector>
using namespace std;

long long count_exact_odds(const vector<int>& nums,int k)
{
    int l=0;
    int odd_count=0;
    long long k_res=0;
    for (int r=0;r<nums.size();r++)
    {
        if (nums[r]%2==1) odd_count++;
        while (odd_count>k)
        {
            if (nums[l]%2==1)
            {
                odd_count--;
            }
            l++;
        }
        k_res+=r-l+1;
    }
    int m=k-1;
    long long m_res=0;
    if (m<0) m_res=0;
    else
    {
        odd_count=0,l=0;
        for (int r=0;r<nums.size();r++)
        {
            if (nums[r]%2==1) odd_count++;
            while (odd_count>m)
            {
                if (nums[l]%2==1)
                {
                    odd_count--;
                }
                l++;
            }
            m_res+=r-l+1;
        }
    }
    long long res=k_res-m_res;
    return res;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (auto& value : nums) cin >> value;
    cout<<count_exact_odds(nums,k);
    // TODO：计算并输出答案。
    return 0;
}
