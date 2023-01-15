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


// 判断是否满足平衡二叉树

/**
 * @brief 
 * 条件是左右子树高度相差不超过1 而且左右子树都得是平衡二叉树
 */

int level(TreeNode *root){
    // 从叶子结点开始算高度，左右子树中最大高度+1就是该树节点高度 叶子结点高度为0
    if(root == nullptr) return 0;
    int leftHeight = level(root->left);
    int rightHeight = level(root->right);
    return max(leftHeight, rightHeight) + 1;
}

bool isBalanced(TreeNode *root){
    // 空树也是一颗平衡二叉树
    if(root == nullptr) return true;
    int left = level(root->left);
    int right = level(root->right);
    return abs(left-right) < 2 && isBalanced(root->left) && isBalanced(root->right);
}

/**
 * @brief 
 * 将求左右子树的高度融入到判断是否平衡之中
 */

bool isBalanced(TreeNode *root){
    return (isBalancedHelper(root) != -1);
}

int isBalancedHelper(TreeNode *root){
    // 叶子结点高度为0
    if(root == nullptr) return 0;

    // 如果左右子树中只要有一个不平衡就会返回不平衡
    int leftHeight = isBalancedHelper(root->left);
    if(leftHeight == -1){
        return -1;
    }
    int rightHeight = isBalancedHelper(root->right);
    if(rightHeight == -1){
        return -1;
    }
    if(abs(leftHeight - rightHeight) > 1){
        return -1;
    }
    // 如果左右子树平衡才会返回这个树结点的高度
    return max(leftHeight, rightHeight) + 1;
}

int main(){

}