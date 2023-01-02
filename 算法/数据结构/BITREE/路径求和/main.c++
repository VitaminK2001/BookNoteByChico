#include <iostream>
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

void pathSumHelper(vector<int> path, vector<vector<int>> &answer, TreeNode *root, int sum){
    if(root == nullptr) return;
    path.push_back(root->val);
    if(root->val = sum) answer.push_back(path);
    pathSumHelper(path, answer, root->left, sum-root->val);
    pathSumHelper(path, answer, root->right, sum-root->val);
}

vector<vector<int> > pathSum(TreeNode *root, int sum){
    vector<int> path;
    vector<vector<int> > answer;
    pathSumHelper(path, answer, root, sum);
    return answer;
}