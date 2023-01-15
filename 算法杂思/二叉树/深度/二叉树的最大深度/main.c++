#include <iostream>
#include <queue>
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

// 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数
class Solution {
public:
    // 深度优先搜索
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return max(left, right) + 1;
    }
    // 广度优先搜索
    int maxDepth(TreeNode *root){
        if(root == nullptr) return 0;
        queue<TreeNode *> q;
        q.push(root);
        int ans = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz > 0){
                TreeNode *cur = q.front();
                q.pop();
                if(cur->left != nullptr) q.push(cur->left);
                if(cur->right != nullptr) q.push(cur->right);
                sz -= 1;
            }
            ans += 1;
        }
        return ans;
    }  
};