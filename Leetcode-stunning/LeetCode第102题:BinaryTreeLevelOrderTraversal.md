# LeetCode 第102题：二叉树的层级遍历

[个人网站](http://lgg2018.com)

题目来源于 LeetCode 上第 102题：Binary Tree Level Order Traversal。题目难度为 Medium，目前通过率为 45.05%

### 题目描述

 * Given a binary tree, return the level order traversal of its nodes' values.

   (ie, from left to right, level by level).

给一个二叉树,返回一个层级遍历每个节点的值,(从左到右,一层一层)



**示例1 :**

```
 Given binary tree [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 
 * return its level order traversal as:
 * 
 * [
 * ⁠ [3],
 * ⁠ [9,20],
 * ⁠ [15,7]
 * ]
 * 
```

### 题目解析

* 使用队列,将每层节点放进去时,记录此时队列深度,再依次取出.
* 取出时将下一层节点放进队列

### 代码实现
```
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
	    vector<vector<int>> res;
	    queue<TreeNode*> que;
	    if (!root)return res;
	    else que.push(root);
	
	    while(!que.empty()) {
	        int size = que.size();
	        vector<int>tmp;
	        for (int i=0;i<size;i++) {
		        auto node = que.front();
		        que.pop();
		        tmp.push_back(node->val);
		        if(node->left)que.push(node->left);
		        if(node->right)que.push(node->right);
	        }
	        res.push_back(tmp);
	    }
	    return res;
    }
};

```
