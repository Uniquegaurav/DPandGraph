// Given a BST and an integer K. Find the Kth Smallest element in the BST. 
// https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1
#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
// method 1
// inorder traversal until we reach count k 
int ans;
void  kthSmallest(Node * root,int K,int &count){
        if(!root) return;
        kthSmallest(root->left,K,count);
        count += 1;
        if(count==K){
           ans = root->data;
           return ;
        }
        kthSmallest(root->right,K,count);
}
int KthSmallestElement(Node *root, int K){
       if(!root) return -1;
       int count =0;
       ans = -1;
       kthSmallest(root,K,count);
       return ans;
}

// method 2
int KthSmallestElement(Node *root, int K){
           int k =0;
           stack<Node *> s;
           Node * curr = root;
           int  ans =-1;
           s.push(curr);
           while(!s.empty()){
              if(curr==NULL){
                  Node * top = s.top();
                  k += 1;
                  if(k==K){
                      ans = top->data;
                      break;
                  }
                  s.pop();
                  if(top->right){
                      s.push(top->right);
                  }
                  curr = top->right;
              }else{
                  curr= curr->left;
                  if(curr!=NULL)
                    s.push(curr);
              }
           }
         return ans;
}