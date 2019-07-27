# LeetCode 第 18题：4sum

[个人网站](http://lgg2018.com)

题目来源于 LeetCode 上第 18题：4sum。题目难度为 Medium，目前通过率为 28.18% 

### 题目描述

 * Given an array nums of n integers and an integer target, are there elements
    * a, b, c, and d in nums such that a + b + c + d = target? Find all unique
    * quadruplets in the array which gives the sum of target.

给你一个数组,找到所有和为target的四个数,组成一个集合vector返回.注意unique表示不能重复

**示例1 :**

```
输入： Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

输出:
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
```

### 题目解析

* 看懂题目，和两数及三数求和一致
* 保持前两数不变时,遍历后数.



### 代码实现
```
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>>res;
		int n= nums.size();
		if(n < 4)return res;
		sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++)
		{
			if(i<0 && nums[i] == nums[i-1])continue;
			if(nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target)break;
			if(nums[i] + nums[n-3]+nums[n-2]+nums[n-1]<target)continue;
			for(int j=i+1;j<n-2;j++)
			{
				if(j > 0 && nums[j] == nums[j-1])continue;
				if(nums[i] + nums[j] + nums[j+1] + nums[j+2] > target)break;
				if(nums[i] + nums[j] + nums[n-2] + nums[n-1] < target)continue;
				int l = j+1,r = n-1;
				while (l<r)
				{
					int sum = nums[i] + nums[j] + nums[l] + nums[r];
					if(sum > target)r--;
					else if(sum < target) l++;
					else
					{

					  res.push_back(vector<int>{nums[i],nums[j],nums[l],nums[r]});
					  do{r--}while (l<r && nums[r] == nums[r+1]);
					  do{l++}while(l<r && nums[l] == nums[l-1]);

					}

				}

			}
		}
		return res;
    }
};
```
