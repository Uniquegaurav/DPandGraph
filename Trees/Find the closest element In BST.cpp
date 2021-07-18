// Given a BST and an integer. Find the least absolute difference between any 
//node value of the BST and the given integer.
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000
// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
int minDiff(Node *root, int K)
    {
        if(root==NULL){
            return INT_MAX;
        }
        int currMin = abs(root->data - K);
        if(root->data==K){
            return currMin;
        }
        if(K<root->data){
            currMin = min(currMin,minDiff(root->left,K));
            return currMin;
        }
        if(K>root->data){
            currMin = min(currMin,minDiff(root->right,K));
            return currMin;
        }
        //Your code here
    }