# LeetCode 第129题：叶节点的和

[个人网站](http://lgg2018.com)

题目来源于 LeetCode 上第129题：Sum Root to Leaf Numbers。题目难度为 Easy，目前通过率为 40.99%

### 题目描述

- Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

每根树叶都表示一个数字,求所有数字的和.



**示例1 :**

```
Input: [1,2,3]
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   3
 * Output: 25
 * Explanation:
 * The root-to-leaf path 1->2 represents the number 12.
 * The root-to-leaf path 1->3 represents the number 13.
 * Therefore, sum = 12 + 13 = 25.
 * 
 * Example 2:
 * 
 * 
 * Input: [4,9,0,5,1]
 * ⁠   4
 * ⁠  / \
 * ⁠ 9   0
 * / \
 * 5   1
 * Output: 1026
 * Explanation:
 * The root-to-leaf path 4->9->5 represents the number 495.
 * The root-to-leaf path 4->9->1 represents the number 491.
 * The root-to-leaf path 4->0 represents the number 40.
 * Therefore, sum = 495 + 491 + 40 = 1026.
```

### 题目解析

- 深度优先的经典题,必须到根部才加和

### 代码实现

```
class Solution {
public:
    int sum = 0;
    int sumNumbers(TreeNode* root) {
	    int tmp = 0;
	    if(!root)return sum;
	    dfs(root,tmp);
	    return sum;
    }

    void dfs(TreeNode* node,int tmp) {
	    tmp = tmp*10 + node->val;   // 经典算式
	    if(node->left==NULL && node->right == NULL)
	        sum +=tmp;
	    if(node->left!=NULL)
	        dfs(node->left,tmp);
	    if(node->right!=NULL)
	        dfs(node->right,tmp);
    }
};
```

