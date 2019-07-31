# LeetCode 第22题：Generate Parentheses

[个人网站](http://lgg2018.com)

题目来源于 LeetCode 上第 22题：Generate Parentheses。题目难度为 Medium，目前通过率为 55.99%

### 题目描述

 * Given n pairs of parentheses, write a function to generate all combination of well-formed parentheses.

给n对括号,写一个函数生成所有可能的组合.

**示例1 :**

```
 * For example, given n = 3, a solution set is:
 * 
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
```

### 题目解析

* 只输入一个n,输出一个字符串组
* 需要用到递归

### 代码实现
```
class Solution {
public:
    vector<string> generateParenthesis(int n) {
       vector<string>res;
	   addpair(res,"",n,0);
	   return res;
	
	}

	void addpair(vector<string>&res,string str,int n,int m)
	{
		if(n==0&& m==0)
		{
			res.push_back(str);
			return;
		}

		if(m>0)addpair(res,str+")",n,m-1);
		if(n>0)addpair(res,str+"(",n-1,m+1);
	}
};

```
