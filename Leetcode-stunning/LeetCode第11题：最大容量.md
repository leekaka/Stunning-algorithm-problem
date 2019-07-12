# LeetCode 第 11题：最大容量

[个人网站](http://lgg2018.com)

题目来源于 LeetCode 上第 11题：翻转整数。题目难度为 Medium，目前通过率为 45.27% 

### 题目描述

给一个数组，他们表示垂直高度，结合他们间的距离，求最大容量。

**示例 :**

```
输入：[1,8,6,2,5,4,8,3,7]

输出：49
```
### 题目解析

1、建议画图，理清楚题目意思

2、最大容量aera = min_high * max_len

3、记录最大容量并返回

### 代码实现

```c++
class Solution {
public:
    int maxArea(vector<int>& height) {
       int aera = 0;
       for(int i=0,j=height.size()-1;i<j;height[i]<height[j]?i++:j--)
       {
	   aera = max(aera,min(height[i],height[j])*(j-i));
       }
       return aera;
    }
};
```

