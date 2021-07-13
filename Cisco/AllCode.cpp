#include<bits/stdc++.h>
using namespace std;
template <typename T>
	class BinaryTreeNode {
    	public : 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this -> data = data;
        	left = NULL;
        	right = NULL;
    	}
};
class TreeNode{
    public : 
      int data;
      vector<TreeNode * > children;
      TreeNode(int data){
          this->data = data;
      }
};

void printLevelWise(BinaryTreeNode<int> *root) {
	queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while(!q.empty()){
        BinaryTreeNode<int> * top = q.front();
        q.pop();
        cout<<top->data<<endl;
        if(top->left){
            q.push(top->left);
        }
        if(top->right){ 
            q.push(top->right);
        }

    }
}
int main(){

}