/*
 * 登神长阶：2026-10-26 独立复查通过，归档版本。
 * 来源：ADPC 第三届秋季赛 A 的公开教学整理版，非官方原始题面。
 * 整理者说明数据可能与原题不同。本轮是复查，不是新增 ADPC 原题。
 * 整理题面：
 * https://github.com/lr580/shannon_sources/blob/c31cb368b3dd38ec3e0af49cf8f52fa33e9fddd9/课件_时空复杂度/第二次课题单.md#登神长阶
 * 专题：备赛地图第 10 块，基础 DP / 递推。
 * 不看旧代码、题解或先前讲解，自行写完整程序。
 *
 * 题意：
 * 第 0 分钟位于第 0 级台阶，第 1、2、3 分钟均位于第 1 级。
 * 从第 4 分钟起，每分钟所在的台阶编号等于前三分钟编号之和。
 * 只在整数分钟更新位置，两个整数分钟之间保持原位。
 * 给定经过的秒数 t，输出此时台阶编号对 425 取模的结果。
 *
 * 输入：一个整数 t，0 <= t <= 100000000。
 * 输出：一个整数。
 * 上述范围沿用公开教学整理版，未与官方原始题面核对。
 *
 * 整理版样例输入：
 * 0
 * 输出：
 * 0
 *
 * 补充示例（教练构造）：
 * 输入：
 * 240
 * 输出：
 * 3
 *
 * 自测：样例 + 至少两组自己构造的边界反例。
 */

#include <iostream>
#include <vector>
using namespace std;

int ascension(int t)
{
    int m=t/60;
    if (m==0) return 0;
    if (m==1||m==2||m==3) return 1;
    vector<int> dp(m+1,0);
    dp[1]=dp[2]=dp[3]=1;
    for (int i=4;i<m+1;i++)
    {
        dp[i]=(dp[i-1]+dp[i-2]+dp[i-3])%425;
    }
    return dp[m];
}

int main()
{
    int t;
    cin>>t;
    cout<<ascension(t);
}