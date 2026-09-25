# 缺失函数返回值

**出现次数：2**（2026-09-25 `searchRange`、`two_sum`）——重复错误，重点盯防

## 症状

- 编译警告：`no return statement in function returning non-void` / `control reaches end of non-void function`
- 运行时：崩溃（如 exit code `0xC000001D`）或输出乱码/垃圾值

## 原因

非 void 函数存在"执行到函数末尾却没有 return"的路径（通常在所有循环结束之后）。

## 防御习惯

1. 写完函数先自问：**所有路径都有 return 吗？** 尤其是循环全部走完的那条路
2. 竞赛代码兜底写法：函数末尾 `return {-1, -1};` 或 `return 0;`
3. 编译必须**零警告**再运行，警告就是免费的错误提示
