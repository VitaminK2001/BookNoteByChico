#include <iostream>
#include <queue>
#include <vector>
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

class Solution{
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode *> s;
        vector<vector<int> > res;
        if(root == nullptr) return res;
        s.push(root);
        while(!s.empty()){
            int size = s.size(); 
            vector<int> level;
            for(int i = 0; i < size; ++i){
                TreeNode * cur = s.front();
                s.pop();
                level.push_back(cur->val);
                if(cur->left != nullptr) s.push(cur->left);
                if(cur->right != nullptr) s.push(cur->right);
            }
            res.push_back(level);
        }
        return res;
    }
};