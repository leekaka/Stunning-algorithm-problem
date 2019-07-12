# LeetCode 第 6题：之字形转换

[个人网站](http://lgg2018.com)

题目来源于 LeetCode 上第 6题：之字形转换。题目难度为 Medium，目前通过率为 28.87% 。

### 题目描述

给定一个字符串行数num，转换字符串为之字型字符串。

**示例 1:**

```
 输入："PAYPALISHIRING"\n3'	排成三行
 The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
输出： "PAHNAPLSIIGYIR"
```
**示例 2:**
```

 * 输入: s = "PAYPALISHIRING", numRows = 4
 * 输出: "PINALSIGYAHRPI"
 * 解释:
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
```

### 题目解析

1、遍历字符串，将其放置在字符串数组中

2、每一行都是一个字符串数组

3、输出的字符串就是数组的拼接即可

### 代码实现

```c++
s Solution {
public:
    string convert(string s, int numRows) {
	if(numRows<=1)return s;
	string* str = new string[numRows];  // 字符串数组
	int row = 0,step = 1;
	for(int i = 0;i<s.size();i++)
	{
	    str[row].push_back(s[i]);

	    if(row==0)                      // 变更步长
		step = 1;
	    else if(row==numRows-1)
		step = -1;

	    row +=step;
	}

	s.clear();                 
	for(int i =0;i<numRows;i++)
	{
	    s.append(str[i]);
	}
	delete[] str;                       // 清除内存

	return s;
```

