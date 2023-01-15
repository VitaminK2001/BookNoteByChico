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

// 判断是否是二叉搜索树
bool helper(TreeNode *root, int min, int max){
    if(!root) return true;
    if((root->val < max || (root->val == INT_MAX && root->right == NULL)) &&
       (root->val > min || (root->val == INT_MIN && root->left == NULL)) &&
       helper(root->left, min, root->val) &&
       helper(root->right, root->val, max))
    return true;

    return false;
}

bool isValidBST(TreeNode *root){
    return helper(root, INT_MIN, INT_MAX);
}

int main(){
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    isValidBST(root);
}