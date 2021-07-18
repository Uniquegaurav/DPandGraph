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
// reverse inorder traversal until we reach count k
void kthLargest(Node *root, int K,int &count,int  &ans){   
       if(root==NULL||count>=K){
           return ;
       }
        kthLargest(root->right,K,count,ans);
       count +=1 ;
       if(count==K){
           ans = root->data;
           return ;
       }
        kthLargest(root->left,K,count,ans);
    }
int kthLargest(Node *root, int K){
       int count  = 0;
       int ans = 0;
       kthLargest(root,K,count,ans);
       return ans;
}