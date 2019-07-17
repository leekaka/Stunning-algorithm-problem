# LeetCode 第 12题：整数转罗马

[个人网站](http://lgg2018.com)

题目来源于 LeetCode 上第 12题：翻转整数。题目难度为 Medium，目前通过率为 51.36% 

### 题目描述

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

把整数转成罗马数字

**示例1 :**

```
输入：3

输出："III"
```

**示例2 :**

```
输入：4

输出："IV"
```
**示例3 :**

```
输入：1994

输出："MCMXCIV"
```
### 题目解析

1、写两个数组，一个整数数组，一个罗马数组，两者可以一一对应
2、对于整数数组，用输入去挨个求除数，在对应的罗马数组里加上即可

### 代码实现
```
class Solution {
public:
    string intToRoman(int num) {
	int sint[13] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
	string drom[13] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
	string res = "";
	for(int i=0;i<13;i++)
	{
	    int n = num/sint[i];
	    num = num - sint[i]*n;
	    for(int k=0;k<n;k++)
	    {
		res += drom[i];
	    }
	}
	return res;
    }
};

```