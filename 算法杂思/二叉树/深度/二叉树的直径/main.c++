#include <iostream>
using namespace std;

class TreeNode{
public:
    TreeNode *left;
    TreeNode *right;
    int val;
    TreeNode() : val(0) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int ans;
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 0;
        level(root);
        return ans-1; // ans一直算的都是经过节点的数量，而不是路径的长度
    }
    int level(TreeNode *root){
        if(root == nullptr) return 0;
        int l = level(root->left);
        int r = level(root->right);
        ans = max(ans, l+r+1);  // 左右子树的结点数量之和 + 根节点
        return max(l, r)+1; // max(l, r) 指的是左右子树中最大的结点数量
    }
};