#include<bits/stdc++.h>
using namespace std;
template< typename T>
class BinaryTreeNode{
    public :
     T data;
     BinaryTreeNode * left;
     BinaryTreeNode * right;
     BinaryTreeNode(T data){
         this->data = data;
         left = NULL;
         right = NULL;
     }
     ~BinaryTreeNode(){
         delete left;
         delete right;
     }
};
void printTree(BinaryTreeNode<int> * root){   
    if(root==NULL){
        return;
    }
    cout<<root->data<<endl;
    printTree(root->left);
    printTree(root->right);
}
// print level wise
void printLevelWise(BinaryTreeNode<int> * root){
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        BinaryTreeNode<int> * front = pendingNodes.front();
        cout<<front->data<<":";
        pendingNodes.pop();
        cout<<"L:";
        if(front->left){
            cout<<front->left->data<<",";
            pendingNodes.push(front->left);
        }else{
            cout<<-1<<",";
        }
        cout<<"R:";
        if(front->right){
            cout<<front->right->data;
            pendingNodes.push(front->right);
        }else{
            cout<<-1;
        }
        cout<<endl;
    }
}
BinaryTreeNode<int> * takeInput(){
    int rootData;
    cin>>rootData;
    if(rootData==-1){
        return NULL;
    }
    BinaryTreeNode<int> * root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int> * left = takeInput();
    BinaryTreeNode<int> * right = takeInput();
    root->left = left;
    root->right = right;
    return root;
}
// input level wise
BinaryTreeNode<int> * takeInputLevelWise(){
    int rootData;
  //  cout<<"Enter Root Data"<<endl;
    cin>>rootData;
    if(rootData==-1){
        return NULL;
    }
    BinaryTreeNode<int> * root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        BinaryTreeNode<int> * front = pendingNodes.front();
        pendingNodes.pop();
      //  cout<<"Enter left child of"<<front->data<<endl;
        int leftChildData;
        cin>>leftChildData;
        if(leftChildData!=-1){
            BinaryTreeNode<int> * child = new BinaryTreeNode<int>(leftChildData);
            pendingNodes.push(child);
            front->left = child;
        }
       // cout<<"Enter right child of"<<front->data<<endl;
        int rightChildData;
        cin>>rightChildData;
        if(rightChildData!=-1){
            BinaryTreeNode<int> * child = new BinaryTreeNode<int>(rightChildData);
            pendingNodes.push(child);
            front->right = child;
        }
    }
    return root;
}
// find a node

bool isNodePresent(BinaryTreeNode<int> * root ,int x){
    if(root==NULL){
        return false;
    }
    if(root->data==x){
        return true;
    }
    if(left){
        if(isNodePresent(root->left,x)){
            return true;
        }
    }
    if(right){
        if(isNodePresent(root->right,x)){
            return true;
        }
    }
    return false;
}
// height of a binary tree

int height(BinaryTreeNode<int> * root){
    if(root==NULL){
        return 0;
    }
    int h = 0;
    if(left){
        h = max(h,height(root->left));
    }
    if(right){
        h = max(h,height(root->right));
    }
    return h +1;
}
// mirror of a binary tree
void mirrorBinaryTree(BinaryTreeNode<int> * root){
    if(root==NULL){
        return;
    }
    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);
    BinaryTreeNode<int> * temp = root->left;
    root->left = root->right;
    root->right = temp;
}
void inOrder(BinaryTreeNode<int> * root){
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
// preorder Binary Tree
void preOrder(BinaryTreeNode<int> * root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);

}
// post order BinaryTree
void postOrder(BinaryTreeNode<int> * root){
    if(root==NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

// sum of nodes
int getSum(BinaryTreeNode<int> * root){
    if(root==NULL){
        return 0;
    }
    int sum = root->data;
    if(left){
        sum += getSum(root->left);
    }
    if(right){
        sum += getSum(root->right);
    }
    return sum;
}
// check balanced
int height2(BinaryTreeNode<int> * root){
    if(root==NULL){
        return 0;
    }
    return 1 + max(height2(root->left),height2(root->right));
}
bool isBalanced(BinaryTreeNode<int> * root){
        if(root==NULL){
            return true;
        }
        int h_diff = abs(height2(root->left)-height2(root->right));
        if((h_diff<2)&&(isBalanced(root->left))&&(isBalanced(root->right))){
            return true;
        }
        return false;
}
// Level Order Traversal

void printLevelWise2(BinaryTreeNode<int> * root){
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        while(n--){
            BinaryTreeNode<int> * front = q.front();
            q.pop();
            cout<<front->data<<" ";
            if(front->left){
                q.push(front->left);
            }
            if(front->right){
                q.push(front->right);
            }
        }
        cout<<endl;
    } 
}
// Remove Leaf Nodes
BinaryTreeNode<int> * removeLeafNodes(BinaryTreeNode<int> * root){
    if(root->left==NULL&&root->right==NULL){
        return NULL;
    }
    BinaryTreeNode<int> * left = NULL ;
    BinaryTreeNode<int> * right =NULL;
    if(left->left){
        left = removeLeafNodes(root->left);
    }
    if(root->right){
        right = removeLeafNodes(root->right);
    }
    root->left  =left;
    root->right = right;
    return root;
}
template<typename T>
class Node{
    public :
    T data;
    Node<T> * next;
    Node(T data){
        this->data = data;
        this->next = NULL;
    }
};

vector<Node<int> * > constructLinkedListForEachLevel(BinaryTreeNode<int> * root){

    vector<Node<int> *> ans;
    if(root==NULL){
        return ans;
    }
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        Node<int> * head= NULL;
        while(n--){
            BinaryTreeNode<int> * front = q.front();
            Node<int> * newNode = new Node<int>(front->data);
            if(head==NULL)
               head= newNode;
            else
               head->next = newNode;
            q.pop();
            if(front->left)
                q.push(front->left);
            if(front->right)
                q.push(front->right); 
            
        }
        ans.push_back(head);
    }
    return ans;
}
void zigzagOrder(BinaryTreeNode<int> * root){
    if(root==NULL){
        return;
    }
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    int i =1;
    while(!q.empty()){
        int n = q.size();
        vector<int> temp;
        while(n--){
            BinaryTreeNode<int> * front = q.front();
            temp.push_back(front->data);
            q.pop();
            if(front->left)
                q.push(front->left);
            if(front->right)
                q.push(front->right); 
            
        }
        if(i%2==0){
            for(int j =temp.size()-1;j>=0;j--){
                cout<<temp[j]<<" ";
            }
        }else{
            for(auto j : temp){
                cout<<j<<" ";
            }
        }
         i += 1;
         temp.clear();
         cout<<endl;
        
    }
}
void printNodesWithoutSibling(BinaryTreeNode<int> * root){
    if(root==NULL){
        return;
    }
    if(root->left!=NULL&&root->right!=NULL){
        printNodesWithoutSibling(root->left);
        printNodesWithoutSibling(root->right);
    }else if(root->left){
        cout<<root->left->data<<" ";
        printNodesWithoutSibling(root->left);
    }else if(root->right){
        cout<<root->right->data<<" ";
        printNodesWithoutSibling(root->right);
    }
}

// build tree from inorder and preorder
BinaryTreeNode<int> * buildTree1(int * preorder, int prelength,int * inorder ,int inLength){
    
}
// build tree from postorder and inorder
BinaryTreeNode<int>* buildTree2(int * postorder, int postLength,int *inorder,int inLength){

}
int main(){
    BinaryTreeNode<int> * root = takeInputLevelWise();
    //printLevelWise(root);
   // printTree(root);
  // cout<<height(root);
  // cout<<height(root->left);
   //cout<<isNodePresent(root,5);
  // cout<<isNodePresent(root,9);
  // cout<<isNodePresent(root,6);
  //cout<<getSum(root)<<endl;
  printLevelWise2(root);

}