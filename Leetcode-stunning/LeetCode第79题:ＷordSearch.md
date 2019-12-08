# LeetCode 第79题：Word Search

[个人网站](http://lgg2018.com)

题目来源于 LeetCode 上第 79题：Word Search。题目难度为 Medium，目前通过率为 30.07%

### 题目描述

 *  Given a 2D board and a word, find if the word exists in the grid
 * The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

给一组二维字母，和一个单词，判断单词是否在二维字母里，可通过垂直和水平两个方向找相邻的字母，相同的格子只能用一次．



**示例1 :**

```
 board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 * 
 * Given word = "ABCCED", return true.
 * Given word = "SEE", return true.
 * Given word = "ABCB", return false.
```

### 题目解析

* 遍历二维数组里的每一个字母，做BFS
* 把当前的字母标记为'\0';退出时需要恢复原字母

### 代码实现
```
class Solution {
public:
    int m,n;
    bool exist(vector<vector<char>>& board, string word) {
	m = board.size(),n = board[0].size();
	if (m<0||n<0)return false;
	for (int i=0;i<m;i++)　{
	    for (int j=0;j<n;j++)　{
		if(find(board,word.c_str(),i,j))
		    return true;
	    }
	}
	　　　return false;
    }
    
    bool find(vector<vector<char>>& board,const char* w,int i, int j)　{
	if(i<0||i>m-1||j<0||j>n-1||board[i][j]!=*w||board[i][j]=='\0')
	    return false;
	if(*(w+1)=='\0')
	    return true;
	char t = board[i][j];
	board[i][j] = '\0';
	if(find(board,w+1,i+1,j)||find(board,w+1,i-1,j)||find(board,w+1,i,j-1)||find(board,w+1,i,j+1))
	    return true;
	board[i][j]=t;
	return false;
    }
};

```
