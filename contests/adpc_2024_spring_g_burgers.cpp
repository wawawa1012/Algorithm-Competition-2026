/*
 * G 随机汉堡店
 * 赛事：2024 年度第五届全国大学生算法设计与编程挑战赛（春季赛）。
 * 来源：ADPC 往届赛题，依据参赛者保存的题面截图及同页样例、范围整理。
 * 不是教练自命题；来源是个人公开存档，当前未登录官方 OJ 核对。
 * GitHub 存档（含题解，做题时只看本文件的题面即可）：
 * https://github.com/z01prime/z01prime.github.io/blob/86597054e31a7963f88403045a6c2a413e14e44e/2024/03/31/2024年度第五届全国大学生算法设计与编程挑战赛（春季赛）/index.html
 * 题面截图：
 * https://s2.loli.net/2024/03/31/ZXjtgbI7rdLJ4Qi.png
 *
 * 专题：备赛地图第 10 块，基础 DP；练习从规则建立状态与转移。
 *
 * 题意转述：
 * 有 n 个排成一行的食材，第 i 个的种类为 t[i]，美味值为 d[i]。
 * 一次可以取走当前队列中的一段连续食材，组成一个汉堡，条件是：
 * 1. 这段食材的首尾种类相同。
 * 2. 这段至少包含 p 个食材。
 * 汉堡的美味值为其中全部食材的美味值之和。
 * 取走一段后，两侧剩余食材会靠拢，原来不相邻的食材可能变为相邻。
 * 可以重复操作，也可以留下不用的食材；求全部汉堡美味值总和的最大值。
 * 若一个汉堡都做不了，答案为 0。
 *
 * 输入：
 * 第一行 n k p，k 为食材种类数量。
 * 第二行 n 个整数 t[1]..t[n]。
 * 第三行 n 个整数 d[1]..d[n]。
 *
 * 范围（同页存档）：
 * 2 <= p <= n <= 1000000，1 <= k <= 1000000。
 * 1 <= t[i] <= k，1 <= d[i] <= 1000000000。
 *
 * 输出：一个整数，表示最大美味值总和。
 *
 * 样例 1 输入：
 * 5 5 2
 * 2 2 5 5 2
 * 2 1 10 9 9
 * 样例 1 输出：
 * 31
 *
 * 样例 2 输入：
 * 5 5 2
 * 5 1 2 4 4
 * 7 9 8 5 6
 * 样例 2 输出：
 * 11
 *
 * 自行写完整程序，不预填 IO 或算法。
 * 自测：两个样例 + 至少两组自己构造的边界反例。
 */
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long make_burgers(const vector<int>& t,const vector<int>& d,int p,int k)
{
    int n=t.size()-1;
    vector<long long> dp(n+1,0);
    vector<long long> pre_sum(n+1,0);
    for (int i=1;i<n+1;i++)
    {
        pre_sum[i]=pre_sum[i-1]+d[i];
    }
    const long long NEG = -(1LL << 60);
    vector<long long> best(k+1,NEG);
    for (int i=p;i<n+1;i++)
    {
        int j=i-p+1;
        best[t[j]]=max(best[t[j]],dp[j-1]-pre_sum[j-1]);
        dp[i]=dp[i-1];
        if (best[t[i]]!=NEG)
        {
            dp[i]=max(dp[i],best[t[i]]+pre_sum[i]);
        }
    }
    return dp[n];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k,p;//n个食材，k表示食材种类数，p表示汉堡最少的食材要求
    cin>>n>>k>>p;
    vector<int> t(n+1);
    vector<int> d(n+1);
    for (int i=1;i<n+1;i++)
    {
        cin>>t[i];
    }
    for (int i=1;i<n+1;i++)
    {
        cin>>d[i];
    }
    cout<<make_burgers(t,d,p,k);
}
