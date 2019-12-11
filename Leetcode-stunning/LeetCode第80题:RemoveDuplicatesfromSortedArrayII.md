# LeetCode 第80题：从排好序的数组中移除重复的

[个人网站](http://lgg2018.com)

题目来源于 LeetCode 上第 80题： Remove Duplicates from Sorted Array II。题目难度为 Medium，目前通过率为  39.26%

### 题目描述

 *  Given a sorted array nums, remove the duplicates in-place such thatduplicates appeared at most twice and return the new length

    * Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
   
      

给你拍好序的数组,从中剔除出现超过两次的数字,返回此时数组的长度,注意不能使用原数组外的额外数组



**示例1 :**

```
Example 1:
 *
 * 
 * Given nums = [1,1,1,2,2,3],
 * 
 * Your function should return length = 5, with the first five elements of nums
 * being 1, 1, 2, 2 and 3 respectively.
 * 
 * It doesn't matter what you leave beyond the returned length.
 * 
 * Example 2:
 * 
 * 
 * Given nums = [0,0,1,1,1,1,2,3,3],
 * 
 * Your function should return length = 7, with the first seven elements of
 * nums being modified to 0, 0, 1, 1, 2, 3 and 3 respectively.
 * 
 * It doesn't matter what values are set beyond the returned length.
```

### 题目解析

* 如果没有额外数组的限制,直接在新数组中把符合条件的老数依次摘下来就行
*  不能新数组的话,就用后填新就行.

### 代码实现
```
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
	    int len = nums.size();
	    if (len<3)return len;
	    int first=1,second=1,count=1;
	    while(second<len) {
	        if(nums[second-1]!=nums[second]) { // 不同count直接赋为1
		        count=1;
		        nums[first++]=nums[second];
		    } else {
		        if(count<2) {
		            nums[first++]=nums[second];
		            count++;     // 相同则计数
		        }
	        }
	        second++;
	    }
	    return first;
    }
};

```
