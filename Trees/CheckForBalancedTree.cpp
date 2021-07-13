#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};


// Method 1 
//Function to check whether a binary tree is balanced or not.

int height2(Node * root){
    if(root==NULL){
        return 0;
    }
    return 1 + max(height2(root->left),height2(root->right));
}
bool isBalanced(Node *root){   
    if(root==NULL){
        return true;
    }
    int h_diff = abs(height2(root->left)-height2(root->right));
    if((h_diff<2)&&(isBalanced(root->left))&&(isBalanced(root->right))){
        return true;
    }
    return false;
    //  Your Code here
}

// Efficient method

int isBalancedCheck(Node *root){
    
    if(root==NULL) return 0;
    int lh = isBalancedCheck(root->left); // finding left height
    if(lh == -1){                        // if it is returning -1 means left sub tree is not balanced
        return -1;
    }
    int rh = isBalancedCheck(root->right); // finding right height
    if(rh == -1){                     // if it is returning -1 means right sub tree is not balanced
        return -1;
    }
    if(abs(lh-rh) > 1){
        return -1;
    }else{
        return 1 + max(lh, rh);
    }
}

bool isBalanced(Node *root){
    if(isBalancedCheck(root) == -1){
        return false;
    }
    return true;
}
