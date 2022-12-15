#include <iostream>
using namespace std;

typedef struct Node{
    struct Node* left;
    struct Node* right;
    int data;
    Node(int d){
        left = nullptr;
        right = nullptr;
        data = d;
    }
}*tree, node;

void create_tree(tree &t){
    char ch;
    cin >> ch;
    if(ch == '#'){
        t = nullptr;
    }else {
        t = (node*)malloc(sizeof(node*));
        t->data = ch;
        t->left = nullptr;
        t->right = nullptr;
        create_tree(t->left);
        create_tree(t->right);
    }
}

void preorder_tree(tree t){
    if(t == nullptr) cout << " ";
    else {
        cout << t->data << " ";
        preorder_tree(t->left);
        preorder_tree(t->right);
    }
}

void inorder_tree(tree t){
    if(t == nullptr) cout << " ";
    else {
        preorder_tree(t->left);
        cout << t->data << " ";
        preorder_tree(t->right);
    }
}

void preorder_tree_iterative(tree t){
    
}
