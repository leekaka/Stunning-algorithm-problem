# LeetCode 第 5题：最长回文子串

[欢迎关注个人公号：

![个](https://github.com/leekaka/github_pics/blob/master/wechat_public/qrcode_for_gh_2e9a528eb7b6_258.jpg?raw=true)

个人网站](http://lgg2018.com)

题目来源于 LeetCode 上第 5题：最长回文子串。题目难度为 Medium，目前通过率为 26.62% 。

### 题目描述

给定一个字符串，请你找出其中不最长的**回文子串**。

**示例 1:**

```
输入: "babad"
输出: "bab" 
注意: aba也是一个答案。
```

### 题目解析

1、剔除特殊输入，输入字符串为空，或者长度为1

2、遍历字符串：

​	2.1、先找相同的字符

​	2.2、找回文，记录回文长度，更新最大长度和起始位置

3、返回子串

### 代码实现

```c++
class Solution {
public:
    string longestPalindrome(string s) {
       if(s.empty())return "";
       if(s.size()==1)return s; //剔除特殊输入

       int start=0,maxlen=1;
       for(int i=0;i<s.size();)
       {
	   if(s.size()-i<=maxlen/2)break;//提前结束
	   int j=i,k=i;
	   while(k<s.size()-1 && s[k+1] == s[k]){k++;}// 找相同
	   i=k+1;
	   while(j>0 && k<s.size()-1 && s[j-1] == s[k+1]){j--;k++;}//找回文
	   int tmplen = k-j+1;
	   if(tmplen>=maxlen){maxlen=tmplen;start=j;}

       }
       return s.substr(start,maxlen);
    }
};
```

