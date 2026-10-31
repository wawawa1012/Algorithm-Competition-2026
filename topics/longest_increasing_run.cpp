/*
 * 最长连续递增段
 * 来源：教练自命题，非 ADPC 原题。
 * 2026-10-31 重启最小日：唯一一题，15–20 分钟找回状态。
 * 专题：备赛地图第 1 块，基础实现与数组扫描。
 *
 * 给定 n 个整数，求最长的连续严格递增段的长度。
 * 连续：不能跳过元素，也不能重新排序。
 * 严格递增：段中每个数都大于它前面的数；相等不算递增。
 * 单个元素也算长度为 1 的合法段。
 *
 * 输入：第一行 n，第二行 n 个整数 a[i]。
 * 范围：1 <= n <= 200000，-1000000000 <= a[i] <= 1000000000。
 * 输出：最长连续严格递增段的长度。
 *
 * 样例输入：
 * 8
 * 1 2 2 3 4 -1 0 1
 * 样例输出：
 * 3
 * 说明：[2,3,4] 和 [-1,0,1] 都是长度为 3 的合法段。
 *
 * 自行写完整 main、读入、算法及输出。
 * 自测样例与至少两组边界：例如单元素、全部相等。
 */

#include <vector>
#include <iostream>
using namespace std;

int longest_increasing_run(vector<int>& nums)
{
    int n=nums.size();
    if (n==0) return 0;
    int res=1;
    int curr_increasing_run=1;
    for (int r=1;r<n;r++)
    {
        if (nums[r]>nums[r-1]) curr_increasing_run++;
        else
        {
            curr_increasing_run=1;
        }
        res=max(curr_increasing_run,res);
    }
    return res;
}

int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for (int& num:nums)
    {
        cin>>num;
    }
    cout<<longest_increasing_run(nums);
}