/*
 * 登神长阶
 * 来源：ADPC 第三届秋季赛 A 的公开教学整理版（非官方原始题面）。
 * 整理者标注：2021-2022 年度第三届全国大学生算法设计与编程挑战赛
 *             （秋季赛）正式赛 A；不保证数据与原题完全一致。
 * GitHub 题面：
 * https://github.com/lr580/shannon_sources/blob/c31cb368b3dd38ec3e0af49cf8f52fa33e9fddd9/课件_时空复杂度/第二次课题单.md#登神长阶
 *
 * 今日专题：递推 / 基础 DP。目标：独立处理状态、初值、单位与取模。
 *
 * 题意转述：
 * 第 0 分钟位于第 0 级台阶，第 1、2、3 分钟均位于第 1 级。
 * 从第 4 分钟起，每分钟所在的台阶编号等于前三分钟的编号之和。
 * 只在整数分钟更新位置，两个整数分钟之间保持原位。
 * 给定经过的秒数 t，求此时所在台阶编号对 425 取模的结果。
 *
 * 输入：一个整数 t，0 <= t <= 100000000。
 * 输出：一个整数，表示所求结果。
 * 上述范围采用教学整理版，尚未与官方原始题面核对。
 *
 * 整理版样例：
 * 输入：
 * 0
 * 输出：
 * 0
 *
 * 请自行写完整程序：头文件、main、读入、算法、输出。
 * 自测：样例 + 至少两组自己构造的边界。
 */

#include <iostream>
#include <vector>
using namespace std;

class solution
{
public:
    int ascension(int t)
    {
        int m=t/60;

        // m == 0,1,2 直接返回，避免访问下标1/2/3越界
        if (m == 0) return 0;
        if (m == 1 || m == 2 || m == 3) return 1;
        vector<int> currState(m+1,0);
        currState[1]=currState[2]=currState[3]=1;
        for (int i=4;i<m+1;i++)
        {
            currState[i]=(currState[i-1]+currState[i-2]+currState[i-3])%425;
        }
        return currState[m];
    }
};

int main()
{
    int t;
    cin>>t;
    solution s;
    cout<<s.ascension(t);
}