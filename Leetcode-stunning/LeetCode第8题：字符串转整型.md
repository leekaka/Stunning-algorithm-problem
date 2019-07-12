# LeetCode 第 8题：翻转整数
<<<<<<< HEAD

欢迎关注个人公号：

![个](https://github.com/leekaka/github_pics/blob/master/wechat_public/qrcode_for_gh_2e9a528eb7b6_258.jpg?raw=true)
=======
>>>>>>> 7492ee69e71aee6141ed13b3009b552c34d453c0

[个人网站](http://lgg2018.com)

欢迎关注个人公号：《一群Zz的小故事》

题目来源于 LeetCode 上第 8题：翻转整数。题目难度为 Medium，目前通过率为 14.16% 

### 题目描述

给一个字符串，输出相应的整型数据。

**示例 1:**

```
输入：“42”

输出：42
```
**示例 2:**

```
输入： “-42”

输出： -42
```

**示例 3:**

```
输入： “words and 987”

输出： 0
```

### 题目解析

1、经典方法：base = base*10 + value
2、注意负号的实现，且字符只有在0~9才有效果
3、注意超过最大或最小时，需要输出最大值INT_MAX 和INT_MIN

### 代码实现

```c++
class Solution {
public:
    int myAtoi(string str) {
	int base = 0,sign = 1,i=0;
	while(str[i] == ' ')i++; // 剔除空字符
	if(str[i] == '+' || str[i] == '-')
	{
	    sign = sign - 2*(str[i++] == '-');
	}
	while(str[i]>='0' && str[i] <= '9' )
	{
	    if(base > INT_MAX/10 || base == INT_MAX/10 && str[i] > '7') // INT_MAX = 2147483647
		return sign == -1? INT_MIN:INT_MAX;
	    base = base*10 + (str[i++] - '0');
	}
        
	return sign*base;
    }
};
```

