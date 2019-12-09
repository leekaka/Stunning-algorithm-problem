# LeetCode 第104题：二叉树的最大深度

[个人网站](http://lgg2018.com)

题目来源于 LeetCode 上第 104题：Maximum Depth of Binary Tree。题目难度为 Easy，目前通过率为 45.05%

### 题目描述

 * Given a binary tree, find its maximum depth.

   The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

给你一个二叉树,让你求最大深度



**示例1 :**

```
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its depth = 3.
```

### 题目解析

* 使用递归
*  使用queue层序遍历,每一层都加1

### 代码实现
```
class Solution {
public:
    int maxDepth(TreeNode* root) {
       queue<TreeNode*>que;    // 使用queue层序遍历
       if(!root)return 0;
       que.push(root);
       int res = 0;
       while(!que.empty()) {
	       int size = que.size();
	       while(size--) {
	           auto tmp = que.front();
	           que.pop();
	           if(tmp->left)que.push(tmp->left);
	           if(tmp->right)que.push(tmp->right);
	       }
	       res++;
       }
       return res;
    }
};



//增加 递归的写法
int maxDepth(TreeNode* root) {
    if(!root)return 0;
    return max(maxDepth(root->left),maxDepth(root->right)) + 1;
}

```
