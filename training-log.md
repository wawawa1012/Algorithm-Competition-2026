# 训练日志

等级：A 完全不会 / B 有思路写不出 / C 能写但需提示或 bug 多 / D 独立 AC / E 间隔 7 天仍能独立快速写出

| 日期 | 题目 | 来源 | 标签 | 用时 | 独立 | 等级 | 主要错误 | 复习日期 |
|---|---|---|---|---|---|---|---|---|
| 2026-09-25 | Find First and Last Position | LeetCode 34（旧 Arithmetic） | 二分 | 未记录 | 否·参考过答案 | C | 缺 return（未返回结果）；边界二分理解需看答案 | 09-28 / 10-02 |
| 2026-09-25 | 两数之和 | LeetCode 1（旧 Arithmetic） | 哈希 | ~30min | 否·提示 hash map | C | 兜底 return 缺失（重复错误）；误改 CMakeLists | 09-28 / 10-02 |
| 2026-09-25 | 删除有序数组中的重复项 | LeetCode 26（旧 Arithmetic） | 双指针·快慢 | ~35min | 否·Hint 2 | C | off-by-one；fast++ 顺序错误致越界读；range-for 值拷贝 | 09-28 / 10-02 |
| 2026-09-26 | sort 热身（升序/降序输出） | 自命题 | 排序·STL sort | ~10min | 是（降序参数有轻微提示） | D | 两行输出未加换行（已改） | 09-28 |
| 2026-09-26 | 盛最多水的容器 | LeetCode 11（旧 Arithmetic） | 双指针·相向 | ~40min | 否·给方向提示 | C | 参数值拷贝（已改 const&）；缺 include；正确性证明不会（已补讲） | 09-28 / 10-02 |
| 2026-09-26 | 有序数组两数之和 | LeetCode 167 | 双指针·相向 | ~30min | 否·给方向提示 | C | 首版非相向：right 重置致 O(n²)+漏解；兜底 return 缺失（第 3 次） | 09-28 / 10-02 |
| 2026-09-26 | 区间和查询 | 自命题 | 前缀和 | ~30min | 否·给方向提示 | C | 首次结构错误：每次查询重建前缀和（伪优化 O(nq)）；int 溢出（已改 long long） | 09-28 / 10-02 |

注：全部按竞赛 stdin/stdout 格式，多组测试验证通过。prefix_sum 实测 n=q=1e5 用时 816ms（O(n+q)）。

## 待复习队列

| 复习日期 | 题目 | 要求 |
|---|---|---|
| 2026-09-28 | search_range / two_sum / remove_duplicates / max_area / two_sum_ii / prefix_sum | 不看任何资料重写，各 10 分钟内 AC |
| 2026-10-02 | 上述六题 | 默写，通过则升 E |

## 已暴露待补的训练点

- 前缀和 + 哈希（subarray_sum 未完成，草稿方向：前缀和转化 ✓，滑窗前提 ✗）
- string 的使用（尚未接触）
- long long 习惯：结果可能超过 2×10^9 时一律 long long
- 预处理结构："一次构建，多次查询"（O(n+q)，不是每次重建）
- 双指针 vs 哈希 vs 滑窗的适用条件：滑窗要求元素非负（单调性）
- 函数参数：只读大容器用 `const T&`；原地修改用 `T&`
- 任何非 void 函数：所有路径必须有 return（已 3 次）
- 自测习惯：正例之外必须造反例（解在数组后部、边界输入）

## 环境备注

- 新增题目文件后：CLion → 右键 CMakeLists.txt → Reload CMake Project；不要手动改 CMakeLists
- 习惯：编译零警告再运行
