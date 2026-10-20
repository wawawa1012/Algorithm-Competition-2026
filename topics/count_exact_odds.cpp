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

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (auto& value : nums) cin >> value;

    // TODO：计算并输出答案。
    return 0;
}
