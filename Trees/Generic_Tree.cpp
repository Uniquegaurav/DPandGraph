#include<bits/stdc++.h>
using namespace std;
template <typename T >
class TreeNode{
    public :
        T data;
        vector<TreeNode *> children;
        TreeNode(T data){
            this->data = data;
        }
        ~TreeNode(){
            for(int i =0;i<children.size();i++){
                delete children[i];
            }
        }
};
void printTree(TreeNode<int> * root){
    cout<<root->data<<":";
    for(int i =0;i<root->children.size();i++){
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++){
        printTree(root->children[i]);
    }
}
// take input recursion wise
TreeNode<int> * takeInput(){
    int rootData;
    cout<<"Enter Data"<<endl;
    cin>>rootData;
    TreeNode<int> * root = new TreeNode<int>(rootData);
    int n;
    cout<<"Enter number of children of"<<rootData<<endl;
    cin>>n;
    for(int i =0;i<n;i++){
        TreeNode<int> * child = takeInput();
        root->children.push_back(child);
    }
    return root;
}
// take input level wise
TreeNode<int> * takeInputLevelWise(){
    int rootData;
   // cout<<"Enter root Data"<<endl;
    cin>>rootData;
    TreeNode<int> * root = new TreeNode<int>(rootData);
    queue<TreeNode<int> *> pendinNodes;
    pendinNodes.push(root);
    while(!pendinNodes.empty()){
        TreeNode<int> * front = pendinNodes.front();
        pendinNodes.pop();
        int n;
      //  cout<<"Enter number of children of"<<front->data<<endl;
        cin>>n;
        for(int i =0;i<n;i++){
            int childData;
         //   cout<<"Enter"<<i<<"th child of"<<front->data<<endl;
            cin>>childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendinNodes.push(child);
        }
    }
    return root;
}
void printLevelWise(TreeNode<int> * root){
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        TreeNode<int> * front = pendingNodes.front();
        cout<<front->data<<":";
        pendingNodes.pop();
        for( int i = 0;i<front->children.size();i++){
            if(i==(front->children.size()-1)){
                cout<<front->children[i]->data;
            }else{
            cout<<front->children[i]->data<<",";
            }
            pendingNodes.push(front->children[i]);
        }
        cout<<endl;
    }
}
bool isPresent(TreeNode<int> * root ,int x){
    if(root->data==x){
        return true;
    }
    for(int i=0;i<root->children.size();i++){
        if(isPresent(root->children[i],x)){
            return true;
        }
    }   
    return false;
}
int getLargeNodeCount(TreeNode<int> * root,int x){
    int count = 0;
    if(root->data>x){
        count =1;
    }
    for(int i =0;i<root->children.size();i++){
        count += getLargeNodeCount(root->children[i],x);
    }
    return count;
}
// Node with maximum child sum
TreeNode<int> * maxSumNode(TreeNode<int> *root){
    TreeNode<int> * maxNode = root;
    int max_data = root->data;
    for(int i =0;i<root->children.size();i++){
        max_data += root->children[i]->data;
    }
    for(int i =0;i<root->children.size();i++){
        TreeNode<int> * curr_node = maxSumNode(root->children[i]);
        int curr_data = curr_node->data;
        for(int i =0;i<curr_node->children.size();i++){
            curr_data += curr_node->children[i]->data;
        }
        if(curr_data>max_data){
            max_data = curr_data;
            maxNode = curr_node;
        }
    }
    return maxNode;
}
// Structurally identical
bool areIdentical(TreeNode<int> *root1,TreeNode<int> *root2){
    if(root1->data!=root2->data){
        return false;
    }
    if(root1->children.size()!=root2->children.size()){
        return false;
    }
    for(int i =0;i<root1->children.size();i++){
        if(!areIdentical(root1->children[i],root2->children[i])){
            return false;
        }
    }
    return true;
}
// next larger
TreeNode<int> * getNextLargerElement(TreeNode<int> * root,int x){
    TreeNode<int> * ele = NULL;
    if(root->data>x){
        ele = root;
    }
    for(int i =0;i<root->children.size();i++){
        TreeNode<int> * curr = getNextLargerElement(root->children[i],x);
        if(curr!=NULL){
            if(ele==NULL){
                ele = curr;
            }else if(curr->data<ele->data){
                ele = curr;
            }
        }
    }
    return ele;
}
//second largest element in tree
pair<TreeNode<int> * , TreeNode<int> *> maxSecondmax(TreeNode<int> * root){
    pair<TreeNode<int>*,TreeNode<int> *> ans;
    pair<TreeNode<int> * ,TreeNode<int> *> temp;
    if(root==NULL){
        return ans;
    }
    ans.first =root; // first maximum
    ans.second = root; // second maximum
    for(int i =0;i<root->children.size();i++){
        temp = maxSecondmax(root->children[i]);
        TreeNode<int> * maxval2node = temp.first;
        if(temp.first->data>ans.first->data){
            maxval2node= ans.first;
            ans.first = temp.first;

        }
        if(temp.second->data>ans.second->data){
            ans.second = temp.second;
        }
        if(maxval2node->data>ans.second->data){
            ans.second = maxval2node;
        }
    }
    return ans;
}
TreeNode<int> *getSecondLargestNode(TreeNode<int> * root){
    return maxSecondmax(root).second;
}
//Replace with depth
void replaceWithDepth(TreeNode<int>*root){
    queue<TreeNode<int> *> q;
    int depth =0 ;
    q.push(root);
    while(!q.empty()){   
        int n = q.size();
        while(n--){
            TreeNode<int> * front  = q.front();
            front->data = depth;
            q.pop();
            cout<<front->data<<" ";
            for(int i =0;i<front->children.size();i++){
                q.push(front->children[i]);
            }
        }
        depth += 1;
        cout<<endl;
    }
}
int main(){
    // 1: 2 3 4
    // 2 : 5 6
    // 3 : 7
    // 4 : 8
    TreeNode<int> * root = takeInputLevelWise();
    //TreeNode<int> *root2 = takeInputLevelWise();
    //printTree(root);
    //printLevelWise(root);
    //cout<<isPresent(root,9);
    //cout<<getLargeNodeCount(root,9);
    //cout<<maxSumNode(root)->data<<endl;
    //cout<<areIdentical(root1,root2);
   // cout<<getNextLargerElement(root,7)->data;
   /*
    TreeNode<int> * ans = getNextLargerElement(root,9);
    if(ans){
        cout<<ans->data;
    }else{
        cout<<"No data exists";
    }
    */
   //replaceWithDepth(root);
   cout<<getSecondLargestNode(root)->data;
}
