/*
 * 大整数乘普通整数
 * 来源：教练自命题，非 ADPC 原题。
 * 专题：第 12 块基础数学 / 高精度，今天第二道专题新题。
 * 目标：把刚完成的多位存储迁移到乘法，处理进位和中间运算的范围。
 *
 * 输入一个非负十进制整数 A 和一个普通非负整数 B，求 A*B 的
 * 完整精确结果，不取模。
 * A 有 1..1000 位，可以有前导零；0 <= B <= 1000000000。
 * 输出不得有多余前导零，结果为零时输出一个 0。
 *
 * 输入：
 * 第一行 A。
 * 第二行 B。
 *
 * 输出：
 * 一行，一个整数，表示 A*B。
 *
 * 样例输入：
 * 12345678901234567890
 * 3
 * 样例输出：
 * 37037036703703703670
 *
 * 本题训练约束：
 * 使用 C++，自行写完整 main、输入、计算及输出。
 * 不把完整 A 转换为机器整数，不使用现成高精度库。
 * 时间要求 O(|A|)，B 的范围固定如上。
 * 可以复用自己上一题已完成的输入、数字存储与规范输出方式。
 * 自测：样例 + 至少两组边界，考虑零、前导零、大 B、连续进位。
 */

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class solution
{
public:
    vector<long long> big_integer_multiply(string a,int b)
    {
        int sizeA=a.size();
        vector<int> numA(sizeA+9,0);
        for (int i=0;i<sizeA;i++)
        {
            numA[i]=a[sizeA-i-1]-'0';
        }
        vector<long long> carry(sizeA+9,0);
        vector<long long> res(sizeA+9,0);
        for (int i=0;i<sizeA+9;i++)
        {
            long long currDigit=1LL*numA[i]*b;
            long long m=currDigit+carry[i];
            if (m>=10)
            {
                carry[i+1]+=m/10;
                res[i]=m%10;
            }
            else res[i]=m;
        }
        int currSize=res.size()-1;
        while (currSize>0&&res[currSize]==0)
        {
            res.pop_back();
            currSize-=1;
        }
        return res;
    }

};

int main()
{
    string a;
    int b;
    cin>>a>>b;
    solution s;
    vector<long long> res=s.big_integer_multiply(a,b);
    for (int i=0;i<res.size();i++)
    {
        cout<<res[res.size()-i-1];
    }
}
