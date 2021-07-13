#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
vector<int> rightView(Node *root){
        vector<int> res;
    queue<Node *> q;
    if(root==NULL){
        return res;
    }
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        Node * front;
        while(size--){
            front =q.front();
            q.pop();
            if(front->left)
             q.push(front->left);
            if(front->right)
            q.push(front->right);
        }
         res.push_back(front->data);
    }
    return res;
}