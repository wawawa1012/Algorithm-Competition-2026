# 训练日志

等级：A 完全不会 / B 有思路写不出 / C 能写但需提示或 bug 多 / D 独立 AC / E 间隔 7 天仍能独立快速写出

| 日期 | 题目 | 来源 | 标签 | 用时 | 独立 | 等级 | 主要错误 | 复习日期 |
|---|---|---|---|---|---|---|---|---|
| 2026-09-25 | Find First and Last Position | LeetCode 34（旧 Arithmetic） | 二分 | 未记录 | 否·参考过答案 | C | 缺 return（未返回结果）；边界二分理解需看答案 | 09-28 / 10-02 |
| 2026-09-25 | 两数之和 | LeetCode 1（旧 Arithmetic） | 哈希 | ~30min | 否·提示 hash map | C | 兜底 return 缺失（重复错误）；误改 CMakeLists | 09-28 / 10-02 |
| 2026-09-25 | 删除有序数组中的重复项 | LeetCode 26（旧 Arithmetic） | 双指针·快慢指针 | ~35min | 否·Hint 2 | C | off-by-one（fast<size-1 丢末尾）；fast++ 顺序错误致越界读；range-for 值拷贝 | 09-28 / 10-02 |

注：三题均按竞赛 stdin/stdout 格式重写并本地多组测试通过。

## 待复习队列

| 复习日期 | 题目 | 要求 |
|---|---|---|
| 2026-09-28 | search_range / two_sum / remove_duplicates | 不看任何资料重写，各 10 分钟内 AC |
| 2026-10-02 | 同上三题 | 默写，通过则升 E |

## 已暴露待补的训练点

- vector 的 `sort(v.begin(), v.end())` 基本用法（下次热身）
- pre-sort + 双指针解法（two_sum 第二解，sort 熟悉后做）
- signed/unsigned 比较警告 `int i < v.size()`
- 自己设计边界测试的习惯：n=1 / 全部相同 / 完全没有重复
- 快慢指针的固定节奏：先读、再写、后移动指针

## 环境备注

- 新增题目文件后：CLion → 右键 CMakeLists.txt → Reload CMake Project；不要手动改 CMakeLists 的 add_executable
- 习惯：编译零警告再运行
