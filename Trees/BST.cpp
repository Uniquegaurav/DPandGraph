#include<bits/stdc++.h>
using namespace std;
template <typename T>
class BinaryTreeNode {
    	public: 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this->data = data;
        	left = NULL;
        	right = NULL;
    	}
};
class BST {
    BinaryTreeNode<int> * root;  
   public:
    BST() { 
        root =NULL;
        // Implement the Constructor
    }
	~BST(){
        delete root;
    }
	/*----------------- Public Functions of BST -----------------*/
    private :
    BinaryTreeNode<int> * removeNode(int data,BinaryTreeNode<int> * node){
        if(node==NULL){
            return node;
        }
        if(node->data==data){
            if(node->left==NULL&&node->right==NULL){
                delete node;
                return NULL;
            }else if(node->left==NULL){
                BinaryTreeNode<int> * temp = node->right;
                node->right = NULL;
                delete node;
                return temp;
            }else if(node->right==NULL){
                BinaryTreeNode<int> * temp = node->left;
                node->left = NULL;
                delete node;
                return temp;
            }else{
                BinaryTreeNode<int> * minNode = node->right;
                while(minNode->left !=NULL){
                    minNode  = minNode->left;
                }
                node->data = minNode->data;
                node->right  = removeNode(minNode->data,node->right);
                return node;

            }
        }
        if(data<node->data){
            BinaryTreeNode<int> * left = removeNode(data,node->left);
            node->left = left;
            return node;
        }
        if(node->data<data){
            BinaryTreeNode<int> * right = removeNode(data,node->right);
            node->right = right;
            return node;
        }
    }
    public :
    void remove(int data) { 
        // Implement the remove() function 
        root = removeNode(data,root);
    }
    private : 
        void print(BinaryTreeNode<int>* root) {
            if (root == NULL) {
                return;
            }
            cout << root->data << ":";
            if (root->left != NULL) {
                cout << "L" << root->left->data;
            }

            if (root->right != NULL) {
                cout << "R" << root->right->data;
            }
            cout << endl;
            print(root->left);
            print(root->right);
        }  
    public :
    void print() { 
        print(root);
        // Implement the print() function
    }
	
    private :
    BinaryTreeNode<int> * insertHelp(int data,BinaryTreeNode<int> * node){
        if(node==NULL){
			BinaryTreeNode<int> * newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }
        if(data<=node->data){
            BinaryTreeNode<int> * left = insertHelp(data,node->left);
            node->left = left;
            return node;
        }
        if(data>node->data){
            BinaryTreeNode<int> * right = insertHelp(data,node->right);
            node->right = right;
            return node;
        }
    }
    public :
    void insert(int data) {
        root = insertHelp(data,root);
    }
	private :
    bool searchHelp(int data ,BinaryTreeNode<int> * node){
        if(node==NULL){
            return false;
        }
        if(node->data== data){
            return true;
        }
        if(node->data>data){
            return searchHelp(data,node->left);
        }
        if(node->data<data){
            return searchHelp(data,node->left);
        }
    }
    public :
    bool search(int data) {
        searchHelp(data,root);
		// Implement the search() function 
    }
};
int main(){

}