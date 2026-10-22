// AtCoder ABC040 C - 柱柱柱柱柱（中文转述：跳柱子）
// 来源分类：其他赛事原题（AtCoder），不是 ADPC 历届原题。
// 官方题面：https://atcoder.jp/contests/abc040/tasks/abc040_c
// N 根柱子从左到右编号 1..N，高度为 a[i]。
// 从第 1 根出发，每次只能向右跳 1 根或 2 根，到达第 N 根。
// 从 i 跳到 j 的代价为两根柱子高度差的绝对值。
// 求所有跳跃代价之和的最小值。
// 2 <= N <= 100000，0 <= a[i] <= 10000。
// 输入 N，随后 N 个高度；输出最低总费用。
// 官方样例 1：4 / 100 150 130 120，输出 40。
// 官方样例 2：4 / 100 125 80 110，输出 40。
// 官方样例 3：9 / 314 159 265 358 979 323 846 264 338，输出 310。

#include <iostream>
#include <vector>
using namespace std;

int pillars(const vector<int>& heights)
{
    int n=heights.size();
    vector<int> dp(n+1,0);
    dp[2]=abs(heights[1]-heights[0]);
    for (int i=3;i<n+1;i++)
    {
        int height=heights[i-1];
        dp[i]=min(dp[i-1]+abs(heights[i-2]-height),dp[i-2]+abs(heights[i-3]-height));
    }
    return dp[n];
}

int main() {
    int n;
    cin >> n;
    vector<int> heights(n);
    for (auto& height : heights) cin >> height;

    // TODO：计算并输出到最后一根柱子的最低总费用。
    cout<<pillars(heights);
    return 0;
}
