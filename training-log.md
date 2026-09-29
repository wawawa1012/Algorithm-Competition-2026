# 训练日志

等级：A 完全不会 / B 有思路写不出 / C 能写但需提示或 bug 多 / D 独立 AC / E 间隔 7 天仍能独立快速写出

| 日期 | 题目 | 来源 | 标签 | 用时 | 独立 | 等级 | 主要错误 | 复习日期 |
|---|---|---|---|---|---|---|---|---|
| 09-25 | search_range | LeetCode 34 | 二分 | — | 曾参考 | **D**（09-27 复习升） | 初学缺 return；边界二分需理解 | 10-02 复查 |
| 09-25 | two_sum | LeetCode 1 | 哈希 | ~30min | 曾提示 | **D**（09-27 复习升） | 初学兜底 return 缺失 | 10-02 复查 |
| 09-25 | remove_duplicates | LeetCode 26 | 双指针·快慢 | ~35min | 否 | C | off-by-one；复习时抄写、main 漏 `nums(n)` | 09-30 重写 |
| 09-26 | sort_warmup | 自命题 | STL sort | ~10min | 是 | **D** | 输出未分行（已改） | — |
| 09-26 | max_area | LeetCode 11 | 双指针·相向 | ~40min | 曾提示 | **D**（09-28 复习升） | 初学值拷贝；正确性证明不会 | 10-03 复查 |
| 09-26 | two_sum_ii | LeetCode 167 | 双指针·相向 | ~30min | 曾提示 | **D**（09-28 复习升） | 初学 right 重置 O(n²)；复习漏 const | 10-03 复查 |
| 09-26 | prefix_sum | 自命题 | 前缀和 | ~30min | 曾提示 | C | 复习忘 long long（int 溢出） | 09-30 重写 |
| 09-27 | subarray_sum | LeetCode 560 | 前缀和+哈希 | — | 伪代码 | B | 等价变形不懂；哈希表存什么不懂 | 09-30 重写 |
| 09-27 | valid_parentheses | LeetCode 20 | 栈 | ~30min | 语法速查 | C | 空栈 top 崩溃；漏最刁钻反例 | 09-30 重写 |
| 09-27 | eval_rpn | LeetCode 150 | 栈 | — | 工具 | B | main 没调用函数；"写的时候乱" | 09-30 重写 |
| 09-28~29 | maze_bfs | 自命题 | BFS·队列 | 很长 | 否 | B | 用递归当 BFS（概念错）；漏 dist==-1 访问检查 | 10-04 重写 |

注：全部按竞赛 stdin/stdout 格式，多组测试验证通过。已归档的 v2 文件即最新版本。

## 待复习队列

| 复习日期 | 题目 | 要求 |
|---|---|---|
| 2026-09-30 | subarray_sum / valid_parentheses / eval_rpn / remove_duplicates / prefix_sum | 不看任何资料重写，各 10 分钟内 AC |
| 2026-10-02 | search_range / two_sum | 复查（通过升 E） |
| 2026-10-03 | max_area / two_sum_ii | 复查（通过升 E） |
| 2026-10-04 | maze_bfs / prefix_sum / remove_duplicates | 复查 |

## 已暴露待补的训练点

- **BFS 标准结构**：队列 + while + dist 数组 + 入队前检查未访问；递归 = DFS，≠ BFS
- **"写的时候乱"**：落笔前先用 3-5 行注释/伪代码列步骤（当前最大短板）
- 死代码残留：写完扫一眼"有没有没用到的东西"（int res、多余的 prefix 数组）
- long long：结果可能超过 2×10^9 时一律 long long（复习时又忘）
- string / stack / queue / unordered_map 的使用（已接触，需巩固）
- 自测习惯：造反例，最短输入往往最刁钻（`)`、n=1、全相同、封死的 E）
- 任何非 void 函数：所有路径必须有 return（已 3 次）

## 环境备注

- 新增题目文件后：CLion → 右键 CMakeLists.txt → Reload CMake Project；不要手动改 CMakeLists
- 习惯：编译零警告再运行
