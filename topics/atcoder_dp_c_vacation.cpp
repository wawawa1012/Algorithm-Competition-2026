/*
 * C - Vacation（假期安排）
 * 来源：其他赛事原题，AtCoder Educational DP Contest C，2019-01-06。
 * 官方题面：https://atcoder.jp/contests/dp/tasks/dp_c?lang=en
 * 不是 ADPC 历届题；作为今日第二道专题新题。
 * 专题：备赛地图第 10 块，基础 DP；练习确定状态需要保留的信息。
 *
 * 题意转述：
 * 假期共 n 天，每天必须从 A、B、C 三种活动中选择一种。
 * 第 i 天选择 A/B/C，分别获得 a[i]/b[i]/c[i] 点幸福值。
 * 相邻两天不能选择相同的活动。
 * 求 n 天能够获得的最大幸福值总和。
 *
 * 输入：
 * 第一行整数 n。
 * 接下来 n 行，第 i 行为 a[i] b[i] c[i]。
 * 范围：1 <= n <= 100000，1 <= a[i], b[i], c[i] <= 10000。
 * 官方限制：2 秒，1024 MiB。
 * 输出：最大总幸福值，一个整数。
 *
 * 官方样例 1 输入：
 * 3
 * 10 40 70
 * 20 50 80
 * 30 60 90
 * 输出：
 * 210
 * 说明：依次选择 C、B、C，得到 70+50+90=210。
 *
 * 官方样例 2 输入：
 * 1
 * 100 10 1
 * 输出：
 * 100
 *
 * 官方样例 3 输入：
 * 7
 * 6 7 8
 * 8 8 3
 * 2 5 2
 * 7 8 6
 * 4 6 8
 * 2 3 4
 * 7 5 1
 * 输出：
 * 46
 *
 * 自行写完整 main、读入、算法和输出。
 * 自测：官方样例和至少两组自己构造的边界反例。
 */
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int validation(const vector<int>& a,const vector<int>& b,const vector<int>& c)
{
    int n = a.size() - 1;
    vector<vector<int>> dp(n + 1, vector<int>(3, 0));

    dp[1][0] = a[1];
    dp[1][1] = b[1];
    dp[1][2] = c[1];
    for (int i=2;i<n+1;i++)
    {
        dp[i][0]=max(dp[i-1][1],dp[i-1][2])+a[i];
        dp[i][1]=max(dp[i-1][0],dp[i-1][2])+b[i];
        dp[i][2]=max(dp[i-1][1],dp[i-1][0])+c[i];
    }
    return max(dp[n][0],max(dp[n][1],dp[n][2]));
}

int main()
{
    int n;
    cin>>n;
    vector<int> a(n+1,0),b(n+1,0),c(n+1,0);
    for (int i=1;i<n+1;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
    }
    cout<<validation(a,b,c);
}