# LeetCode 第 15题：三数和

[个人网站](http://lgg2018.com)

题目来源于 LeetCode 上第 15题：三数和。题目难度为 Medium，目前通过率为 22.73% 

### 题目描述

Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.

给你一个数组，找到所有三个整数和为0的三数组集合。

**示例1 :**

```
输入：[-1,9,2,3,-1,-4]

输出：
[
	[-1,0,1],
	[-1,-1,2]
]
```

### 题目解析

1、输入小于三个||排序后的第一个数字大于0||排序后的最后一个数字小于0，直接返回空

2、对输入数组做排序

3、遍历数组中每一个数字，遇到相同的则递加，对于每一个数字都去从剩下的数字里，寻找OK的另外的两个数

4、当遍历的数出现大于0的时候，则可以直接break

5、因为数组排好序，所以可以使用前后两指针来实现找数，找数过程中遇到相同的需要排除

### 代码实现
```
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>>res;
		sort(nums.begin(),nums.end());
		if(nums.size()<3 || nums.front() > 0 || nums.back() < 0)return {};  
		for (int i=0;i<nums.size()-2;i++)
		{
			if(nums[i]>0)break;
			if(i>0 && nums[i]==nums[i-1])continue;
			int tmp = -nums[i],start=i+1,end=nums.size()-1;
			while (start<end)
			{
				if(nums[start] + nums[end] == tmp)
				{
					res.push_back({nums[i],nums[start],nums[end]});
					while (start<end && nums[start]==nums[start+1])start++; // 遇到相同的给排除掉
					while (start<end && nums[end] == nums[end-1])end--;
					start++;  //每找到一组，则需要更新一次
					end--;

				}
				else if(nums[start] + nums[end]>tmp)
				{
					end--;
				}
				else
				  start++;

			}

		}
		return res;

    }
};
```