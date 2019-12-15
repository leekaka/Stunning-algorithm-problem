# LeetCode 第90题：SubsetsII

[个人网站](http://lgg2018.com)

题目来源于 LeetCode 上第 790：Subsets II。题目难度为 Medium，目前通过率为 39.52%

### 题目描述

 * Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

    *  Note: The solution set must not contain duplicate subsets.

   给一个整数的几何,可能含有重复的,返回所有可能的子几何,相当于求组合

 *  给一组二维字母，和一个单词，判断单词是否在二维字母里，可通过垂直和水平两个方向找相邻的字母，相同的格子只能用一次．



**示例1 :**

```
Input: [1,2,2]
 * Output:
 * [
 * ⁠ [2],
 * ⁠ [1],
 * ⁠ [1,2,2],
 * ⁠ [2,2],
 * ⁠ [1,2],
 * ⁠ []
 * ]
 * 
```

### 题目解析

* 遍历一遍,做DFS
* 

### 代码实现
```
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       int len = nums.size();
       vector<vector<int>>res;
       if(len<1)return res;
       vector<int>tmp;
       res.push_back(tmp);  //空集
       sort(nums.begin(),nums.end());
       for(int i=1;i<=len;i++) {
	       dfs(nums,res,tmp,i,0);
       }
       return res;
    }

    void dfs(vector<int>&nums,vector<vector<int>>&result,vector<int>&tmp,int depth,int start) {
	if(tmp.size()==depth) {
	    result.push_back(tmp);
	    return;
	}

	for(int i=start;i<nums.size();i++) {
	    if(i!=start && nums[i]==nums[i-1])continue;
	        tmp.push_back(nums[i]);
	        dfs(nums,result,tmp,depth,i+1);
	        tmp.pop_back();
	    }
    }
};

```
