# LeetCode 第 16题：三数和closest

[个人网站](http://lgg2018.com)

题目来源于 LeetCode 上第 16题：三数和（closest）。题目难度为 Medium，目前通过率为 45.79% 

### 题目描述

 * Given an array nums of n integers and an integer target, find three integers
 * in nums such that the sum is closest to target. Return the sum of the three
 * integers. You may assume that each input would have exactly one solution.

给你一个数组，和一个目标值，从数组中找到三个数的和能最接近这个目标值，返回这个和即可。

**示例1 :**

```
输入： nums = [-1, 2, 1, -4], and target = 1.

输出：The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
```

### 题目解析

和15题类似

先随机取一个和sum,

1、输入小于三个直接返回0

2、对输入数组做排序

3、遍历数组中每一个数字，遇到相同的则递加，对于每一个数字都去从剩下的数字里，寻找另外的两个数并求和，目标值做比较，与当前的和比较谁比较接近，更新sum

4、如果遇到sum和target一致，则直接返回target.否则最后返回closet



### 代码实现
```
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
		if(nums.size()<3)return 0;
		int closest = nums[0] + nums[1] + nums[2];
		sort(nums.begin(),nums.end());
		for(int i=0; i<nums.size()-2;i++)
		{
			if(i>0 && nums[i] == nums[i-1])i++;
			int l = 1+1,r=nums.size()-1;
			while (l<r)
			{

			    int sum = nums[i] + nums[l] + nums[r];
				if(sum==target)return sum;
				if(abs(sum-target) < abs(closest-target))
				  closest = sum;
				if(sum>target)
				  r--;
				else
				  l++;
			}
		}
		return closest;

    }
};
```
