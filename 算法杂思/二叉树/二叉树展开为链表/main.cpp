#include <iostream>
#include <stack>
using namespace std;

struct TreeNode{
    TreeNode *left;
    TreeNode *right;
    int val;
    TreeNode () : val(0), left(nullptr), right(nullptr) {}
    TreeNode (int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        // 将左子树节点变成右子树节点
        // 原来的右子树节点接到左子树节点的最右结点
        while(root != nullptr){
            if(root->left == nullptr){
                root = root->right;
            }else {
                TreeNode *rightest = new TreeNode();
                if(root->left != nullptr){ //如果左子树不为空
                    // 找到左子树的最右边的结点
                    rightest = findRightest(root->left);
                }
                // 找到最右结点之后，将最右结点的右节点挂上原来的左子树
                rightest->right = root->right;
                // 将原来左子树变成右子树
                root->right = root->left;
                // 将原来的左子树变为空
                root->left = nullptr;
                root = root->right;
            }
        }
    }
    TreeNode* findRightest(TreeNode* head){
        while(head->right != nullptr){
            head = head->right;
        }
        return head;
    }
};

int main() {
    Solution s;
    TreeNode *head = new TreeNode(1);
    head->left = new TreeNode(2);
    head->right = new TreeNode(5);
    head->right->right = new TreeNode(6);
    head->left->left = new TreeNode(3);
    head->left->right = new TreeNode(4);
    s.flatten(head);
}

class Solution2{
public:
    void flatten(TreeNode* root) {
        // 每次遍历一个结点，就将上一个节点的右指针指向当前的节点
        
    }
};