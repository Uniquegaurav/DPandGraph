#include<bits/stdc++.h>
using namespace std;
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
//Function to remove duplicates from sorted linked list.
Node *removeDuplicates(Node *head){ 
    if(head==NULL){
        return head;
    }
    Node *t1 = head;
    Node *t2 =head;
    while(t2->next != NULL){
         t2 = t2->next;
        
        if(t2->data == t1->data){
            if(t2->next==NULL){
                t1->next =NULL;
            }
            Node * curr = t2;
            delete curr;
        }else{
            t1->next = t2;
            t1 = t2;
        }
    }
    return head;
}