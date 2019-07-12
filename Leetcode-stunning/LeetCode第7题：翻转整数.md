# LeetCode 第 7题：翻转整数

欢迎关注个人公号：

![个](https://github.com/leekaka/github_pics/blob/master/wechat_public/qrcode_for_gh_2e9a528eb7b6_258.jpg?raw=true)

[个人网站](http://lgg2018.com)

题目来源于 LeetCode 上第 7题：翻转整数。题目难度为 Easy，目前通过率为 25.38% 。

### 题目描述

给定一个整数，翻转输出。

**示例 1:**

```
输入：123

输出：321
```
**示例 2:**

```
输入： 120

输出： 21
```

### 题目解析

1、经典方法：使用求余%即可

2、注意超过最大或最小时，需要输出0

### 代码实现

```c++
class Solution {
public:
    int reverse(int x) {
	long long ret = 0;
    while(x)
    {
        ret = ret*10 + x%10;
        x = x/10;
    }
    return (ret>INT_MAX || ret<INT_MIN)? 0:ret;

    }
};
```

