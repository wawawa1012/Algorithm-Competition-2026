// 和不超过 S 的子数组数量（自命题）
// 给定 N 个非负整数，统计和 <= S 的非空连续子数组数量。
// 按下标区间区分：即使元素相同，不同起止位置也分别计数。
// 1 <= N <= 200000，0 <= a[i] <= 1000000000，0 <= S <= 100000000000000。
// 输入第一行 N S，第二行 N 个整数；输出数量。
// 样例输入：
// 5 4
// 1 2 1 3 0
// 样例输出：11

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    long long s;
    cin >> n >> s;
    vector<long long> nums(n);
    for (auto& value : nums) cin >> value;

    // TODO：计算并输出答案。
    return 0;
}
