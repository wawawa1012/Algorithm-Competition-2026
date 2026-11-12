/*
 * ADPC 2026 春季赛 G — 骰子示数
 * 来源：ADPC 历届题，按参赛者保存的题面整理，未与官方 OJ 核对。
 * 题面及样例：https://me.yifeizhang.top/algorithms/WriteUp/adpc26sp/
 * 题号/题名交叉记录：
 * https://gitcode.csdn.net/6a1071cb662f9a54cb766af0.html
 * 2026-11-12 混合识别；仅给题面，不给解法或 IO 骨架。
 *
 * 输入两枚骰子的面值，各有 6 面，面值允许重复，均在 0..7 内。
 * 每枚任选一个面朝上，两个数字组成十位和个位；左右顺序可以交换。
 * 任意一枚骰子上的 6 都既能表示 6，也能表示 9。
 * 列出所有能得到的整数，去重后由小到大输出，数字之间用空格分隔。
 * 前导零按整数处理，例如 01 输出 1，00 输出 0。
 *
 * 输入：两行，每行 6 个整数，分别描述两枚骰子。
 * 原存档限制：1 秒，256 MB。
 *
 * 存档样例 1 输入：
 * 1 1 1 1 1 6
 * 1 1 1 1 1 1
 * 输出：
 * 11 16 19 61 91
 *
 * 存档样例 2 输入：
 * 1 2 0 0 0 0
 * 1 3 0 0 0 0
 * 输出：
 * 0 1 2 3 10 11 12 13 20 21 23 30 31 32
 *
 * 自己写完整程序，检查两个存档样例和至少两组边界。
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<int> g_dice(const vector<int> & a,const vector<int> & b)
{
    set<int> A,B;
    //去重
    for (int i=0;i<6;i++)
    {
        if (a[i]==6) A.insert(9);
        if (b[i]==6) B.insert(9);
        A.insert(a[i]);
        B.insert(b[i]);
    }
    set<int> res;
    for (auto& x: A)
    {
        for (auto& y:B)
        {
            res.insert(10*x+y);
        }
    }
    for (auto& x: B)
    {
        for (auto& y:A)
        {
            res.insert(10*x+y);
        }
    }
    vector<int> v(res.begin(),res.end());
    return v;
}

int main()
{
    int n;
    vector<int> a(6),b(6);
    for (int i=0;i<6;i++)
    {
        cin>>a[i];
    }
    for (int i=0;i<6;i++)
    {
        cin>>b[i];
    }
    vector<int> res=g_dice(a,b);
    for (int v:res) cout<<v<<" ";
}
