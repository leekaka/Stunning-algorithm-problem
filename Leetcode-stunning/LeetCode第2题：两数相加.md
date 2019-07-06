# LeetCode 第 2 题：两数相加

> [个人网站](https://lgg2018.com)

题目来源于 LeetCode 上第 2 题：两数相加。题目难度为 Medium，目前通过率为 33.9% 。

### 题目描述

给出两个 **非空** 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 **逆序** 的方式存储的，并且它们的每个节点只能存储 **一位** 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

**示例：**

```
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
```

### 题目解析

设立一个表示进位的变量`carried`，建立一个新链表，把输入的两个链表从头往后同时处理，每两个相加，将结果加上`carried`后的值作为一个新节点到新链表后面。

### 代码实现

```
// 不用指针
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	    ListNode prehead(0), *p = &prehead;   // 一个指向 链表的指针
	    int extra = 0;
	    while(l1||l2||extra)   // 三者有一个即可
	    {
	     int sum = (l1?l1->val:0) + (l2?l2->val:0) + extra;  // 常用的相加进位方法
	     extra = sum / 10;
	     p->next = new ListNode(sum % 10);
	     p = p->next;
	     l1 = l1?l1->next:l1;               // 链表的迭代 如果有，则下一个链表，否则 则是 本身即可(没有)
	     l2 = l2?l2->next:l2;
	    }
	   return prehead.next; 
        
    }
};
```

