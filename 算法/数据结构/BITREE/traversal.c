//
// Created by #Vitamink on 2022/12/15.
//
#include <stdio.h>
#include <stdlib.h>
typedef int myType;

typedef struct Node{
    struct Node* left;
    struct Node* right;
    myType val;
    int color;
}*tree, node;

typedef struct Stack{
    node* arr[200];
    int top;
}stack;

void createStack(stack** st){
    *st = (stack*) malloc(sizeof(stack));
    (*st)->top = -1;
}

void push(stack* s, node* node){
    s->arr[++s->top] = node;
}

node* pop(stack* s){
    node* node = s->arr[s->top--];
    return node;
}

//递归遍历
void postOrder(node* root, int* res, int* returnSize){
    if(root == NULL){
        return;
    }
    postOrder(root->left, res, returnSize);
    postOrder(root->right, res, returnSize);
    res[(*returnSize)++] = root->val;
}

//迭代遍历
int* traversal(node* root, int* returnSize){
    *returnSize = 0;
    int* res = (myType*)malloc(sizeof(myType)*200);
    stack* s = NULL;
    createStack(&s);
    root->color = 0;
    push(s, root);
    while(s->top > -1){
        node* node = pop(s);
        if(node->color == 1){
            res[(*returnSize)++] = node->val;
        }else {
            if(node->right){
                push(s, node->right);
            }
            if(node->left){
                push(s, node->left);
            }
            node->color = 1;
            push(s, node);
        }
    }
    return res;
}

void createTree(node** t){
    myType data;
    scanf("%d", &data);
    if(data == -1){
        t = NULL;
    }else {
        *t = (node*)malloc(sizeof(node));
        (*t)->val = data;
        printf("请输入%d的左孩子节点: ", data);
        createTree(&(*t)->left);
        printf("请输入%d的右孩子节点: ", data);
        createTree(&(*t)->right);
    }
}

int arrlen(int* p){
    int len = 0;
    while(*p){
        p++;
        len++;
    }
    return len;
}

int main(){
    node *t = NULL;
    createTree(&t);
    int* returnSize = (int*)malloc(sizeof(int));
    int* res = traversal(t, returnSize);
    for(int i = 0; i < arrlen(res); ++i){
        printf("%d ", res[i]);
    }
}
