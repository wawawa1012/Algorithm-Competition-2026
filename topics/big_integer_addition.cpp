/*
 * 高精度加法
 * 来源：教练自命题，非 ADPC 历届原题。
 * 专题：备赛地图第 12 块，基础数学 / 高精度整数。
 * 目标：用多个位置保存一个整数，完成精确加法及进位。
 *
 * 题目：
 * 输入两个非负十进制整数 A、B，每个数有 1～1000 位。
 * 求 A+B 的完整、精确结果，不取模。
 * 输入允许有前导零；输出不得有多余前导零，结果为零时输出 0。
 *
 * 输入：
 * 第一行 A，第二行 B。
 *
 * 输出：
 * 一行，一个整数，表示 A+B。
 *
 * 样例输入：
 * 99999999999999999999
 * 1
 * 样例输出：
 * 100000000000000000000
 *
 * 本题训练约束：
 * 使用 C++，自行写完整程序与输入输出。
 * 不把完整输入转为 int/long long，不使用现成高精度库。
 * 时间复杂度要求 O(|A|+|B|)，|A|、|B| 表示输入位数。
 * 自测：样例 + 至少两组边界；考虑 0、位数不同、连续进位和前导零。
 */

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class solution
{
public:
    vector<int> big_integer_addition(string a,string b)
    {
        int sizeA=a.size(),sizeB=b.size();
        int size=max(sizeA,sizeB);//统一数组大小
        vector<int> numA(size+1,0);
        vector<int> numB(size+1,0);
        for (int i=0;i<sizeA;i++)
        {
            numA[i]=a[sizeA-i-1]-'0';
        }
        for (int i=0;i<sizeB;i++)
        {
            numB[i]=b[sizeB-i-1]-'0';
        }
        vector<int> sum(size+1,0);
        vector<int> carry(size+1,0);
        for (int i=0;i<size+1;i++)
        {
            int digitSum=numA[i]+numB[i];
            if (digitSum+carry[i]<10) sum[i]=digitSum+carry[i];
            else
            {
                carry[i+1]=1;
                sum[i]=digitSum+carry[i]-10;
            }
        }
        int currLocation=size;
        while (currLocation>0&&sum[currLocation]==0)
        {
            sum.pop_back();
            currLocation--;
        }
        return sum;
    }
};
int main()
{
    string a,b;
    cin>>a>>b;
    solution s;
    vector<int> res=s.big_integer_addition(a,b);
    for (int i=0;i<res.size();i++)
    {
        cout<<res[res.size()-i-1];
    }
}
