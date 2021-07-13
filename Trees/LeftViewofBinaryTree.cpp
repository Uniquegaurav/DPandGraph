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
vector<int> leftView(Node *root){
    vector<int> res;
    queue<Node *> q;
    if(root==NULL){
        return res;
    }
    q.push(root);
    while(!q.empty()){
        res.push_back(q.front()->data); 
        int size = q.size();
        while(size--){
            Node * front =q.front();
            q.pop();
            if(front->left)
            q.push(front->left);
            if(front->right)
            q.push(front->right);
        }
    }
    return res;
   // Your code here
}

