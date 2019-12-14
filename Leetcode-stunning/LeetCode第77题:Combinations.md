# LeetCode 第79题：Word Search

[个人网站](http://lgg2018.com)

题目来源于 LeetCode 上第 77题：Word Search。题目难度为 Medium，目前通过率为 43.50%.

### 题目描述

 *   Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

给两个整数n和k返回所有1到n的数的组合,其中每组不能超过2个



**示例1 :**

```
* Input: n = 4, k = 2
 * Output:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
```

### 题目解析

* 从1到n做遍历,使用深度优先算法
* 每完成一次深搜,都需要退出当前的值,再进行下一次

### 代码实现
```
class Solution {
public:
    vector<vector<int>>res;
    vector<vector<int>> combine(int n, int k) {
	if(n<=0||k>n||k<0)return res;
        vector<int>tmp;
	dfs(n,k,1,tmp);
	return res;
    }

    void dfs(int n, int k, int start, vector<int>&tmp) {
	if(tmp.size() == k) {
	    res.push_back(tmp);
	    return;
	}
	for (int i=start;i<=n;i++) {
	    tmp.push_back(i);
	    dfs(n,k,i+1,tmp);
	    tmp.pop_back();
	   }
    }
};

```
