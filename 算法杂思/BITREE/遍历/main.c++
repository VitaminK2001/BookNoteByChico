#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
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

vector<TreeNode *> preOrder(TreeNode *root){ //前序遍历也可以用visit
    stack<TreeNode *> st;
    vector<TreeNode *> res;
    if(root != nullptr) st.push(root);
    while(!st.empty()){
        TreeNode *cur = st.top();
        st.pop();
        res.push_back(cur);
        if(cur->right != nullptr) st.push(cur->right);
        if(cur->left != nullptr) st.push(cur->left);
    }
    return res;
}

vector<TreeNode *> inOrder(TreeNode *root){
    stack<TreeNode *> st;
    vector<TreeNode *> res;
    unordered_map<TreeNode *, bool> visit; 
    if(root != nullptr) st.push(root);
    while(!st.empty()){
        TreeNode *cur = st.top();
        st.pop();
        if(visit[cur] == true) {
            // 如果这个结点已经被遍历过，则第二次取出来的时候不用考虑左右节点
            res.push_back(cur);
        }
        else {
            visit[cur] = true;
            if(cur->right != nullptr) st.push(cur->right);
            st.push(cur);
            if(cur->left != nullptr) st.push(cur->left);
        }
    }
    return res;
}

vector<TreeNode *> postOrder(TreeNode *root){
    stack<TreeNode *> st;
    vector<TreeNode *> res;
    unordered_map<TreeNode *, bool> visit; 
    if(root != nullptr) st.push(root);
    while(!st.empty()){
        TreeNode *cur = st.top();
        st.pop();
        if(visit[cur] == true) {
            // 如果这个结点已经被遍历过，则第二次取出来的时候不用考虑左右节点
            res.push_back(cur);
        }
        else {
            visit[cur] = true;
            st.push(cur);
            if(cur->right != nullptr) st.push(cur->right);
            if(cur->left != nullptr) st.push(cur->left);
        }
    }
    return res;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    vector<TreeNode *> res = postOrder(root);
    for(const TreeNode * node : res){
        cout << node->val << " ";
    }
    return 0;
}