#include <iostream>
#include <deque>
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
    // 采用遍历的方法判断
    // 首先判断一层结点的个数是否是偶数
    // 然后判断对应位置结点的值是否相等，注意空节点的特判
    // 然后将下一层的所有节点入队(非空节点才能调用left right)
    // 然后将这一层节点全部出队
    bool isSymmetric(TreeNode* root) {
        deque<TreeNode *> s;
        s.push_back(root);
        TreeNode *cur = s.front();
        s.pop_back();
        if(root->left == nullptr && root->right == nullptr) return true;
        else if(root->left == nullptr || root->right == nullptr) return false;
        else {
            s.push_back(root->left);
            s.push_back(root->right);
        }
        while(!s.empty()) {
            int size = s.size();
            if(size % 2 != 0) return false;
            for(int i = 0, j = size-1; i < j; ++i, --j) {
                if(s[i] == nullptr && s[j] != nullptr || s[i] != nullptr && s[j] == nullptr) return false;
                else if(s[i] == nullptr && s[j] == nullptr) continue;
                else if(s[i]->val != s[j]->val) {
                    return false;
                }
            }
            for(int i = 0; i < size; ++i) {
                cur = s[i];
                if(cur == nullptr) continue;
                s.push_back(cur->left);
                s.push_back(cur->right);
            }
            for(int i = 0; i < size; ++i) {
                s.pop_front();
            }
        }
        return true;
    }

    // 也可以采用递归的比较方式
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        dfs(root->left, root->right);
    }
    bool dfs(TreeNode *left, TreeNode *right) {
        if(left == nullptr && right == nullptr) {
            return true;
        }
        if(left == nullptr || right == nullptr) return false;
        if(left->val != right->val) return false;
        // 递归比较左孩子的左孩子和右孩子的右孩子 左孩子的右孩子和右孩子的左孩子
        return dfs(left->left, right->right) && dfs(left->right, right->left);
    }
};
