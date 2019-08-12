# LeetCode 第21题：合并两个队列

[个人网站](http://lgg2018.com)

题目来源于 LeetCode 上第 21题：Merge Two Sorted Lists。题目难度为 Medium，目前通过率 44.07%.

### 题目描述

 * Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

合并两个队列.

**示例1 :**

```
   * Input: 1->2->4, 1->3->4
   * Output: 1->1->2->3->4->4

```

### 题目解析

* 输入两个队列,输出一个队列,且输出的队列是排好序的
* 使用递归合并

### 代码实现
```
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if(l1==NULL)return l2;
		if(l2==NULL)return l1;
		return (l1->val < l2->val)? (l1->next=mergeTwoLists(l1->next,l2),l1):(l2->next = mergeTwoLists(l1,l2->next),l2);
        
    }
};

```
