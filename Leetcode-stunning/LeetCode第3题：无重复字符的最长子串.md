# LeetCode 第 3 号问题：无重复字符的最长子串

[个人网站](http://lgg2018.com)

题目来源于 LeetCode 上第 3 题：无重复字符的最长子串。题目难度为 Medium，目前通过率为 29.0% 。

### 题目描述

给定一个字符串，请你找出其中不含有重复字符的 **最长子串** 的长度。

**示例 1:**

```
输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
```

### 题目解析

1、建立一个256位大小的整型数组 dict ，用来建立字符和其出现位置之间的映射,记录字符第一次出现的位置
2、每次出现重复的字符，则记录他们之间的长度，选择最大的保留下来
3、返回最大的长度（i-start）初始值start=-1;极端情况i=size()-1，则最大是size

### 代码实现

```c++
class Solution {
public:
    int lengthOfLongestSubstring(string s) {	
	int maxlen = 0,start = -1;
	vector<int>dict(255,-1);  // 创建一个数组 记录字符s出现的位置

	for(int i = 0;i<s.size();i++)
	{
	    if(dict[s[i]] > start)    //核心:当重复出现（只有出现才会大于-1）时，出现过的记录在dict里
		start = dict[s[i]];
	    dict[s[i]] = i;
	    maxlen = max(maxlen,i-start);
	}
	return maxlen;
        
    }
};
```

