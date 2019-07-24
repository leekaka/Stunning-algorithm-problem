# LeetCode 第 17题：手机按键的单词组成

[个人网站](http://lgg2018.com)

题目来源于 LeetCode 上第 17题：手机按键的单词组成）。题目难度为 Medium，目前通过率为 42.04% 

### 题目描述

 * Given a string containing digits from 2-9 inclusive, return all possibl letter combinations that the number could represent.
* A mapping of digit to letters (just like on the telephone buttons) is give below. Note that 1 does not map to any letters.

给你一个字符串数组，里面只包含2到9的数字，返回手机上按键所有可能的单词组合。（功能机上的按键，这应该是一个很老的题）

**示例1 :**

```
输入： "23"

输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
```

### 题目解析

* 看懂题目，首先得知道手机上按键的字母和数字的对应关系

* {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"}对应到0到9如左vector所示

* 对于输入的处理，遍历时取出，转成数字，这样能对应到上述vector里的字符串
* 对于每个取出来的字符串都要和后面取出来的字符串一一对应的加上，则需要用遍历。
* 每次取完一个字符串时，更新res字符串组即可



### 代码实现
```
class Solution {
public:
    vector<string> letterCombinations(string digits) {
	    vector<string>res;
	    if(digits.empty())return res;
	    res.push_back("");
	    static const vector<string>v = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
	    for(int i = 0;i<digits.size();i++)
	    {
		    int num = digits[i] - '0';
		    if(num<2||num>9)break;
		    const string&cand = v[num];
		    if(cand.empty())continue;
		    vector<string>tmp;
		    for(int k = 0;k<res.size();k++)
		    {
			    for(int j =0;j<cand.size();j++)
			    {
				    tmp.push_back(res[k] + cand[j]);
			    }
		    }
		    res.swap(tmp);
	    }

	    return res; 
    }
};
```
