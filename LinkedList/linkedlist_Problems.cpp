 #include<bits/stdc++.h>
    using namespace std;
    class Node{
    public :
    int data;
    Node * next;

        Node(int data){
            this->data =data;
            next = NULL;
        }
    };

//  function to print the linked list in a reverse order

void printReverse(Node *head){

    if(head==NULL){
        return;
    }
    printReverse(head->next);
    cout<<head->data<<" ";
}

// reverse lin
int main(){

}
