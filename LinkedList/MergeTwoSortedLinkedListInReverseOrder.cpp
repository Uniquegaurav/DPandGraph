#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
};
Node * reverse(Node * head){
    Node * prev = NULL;
    Node * next = NULL;
    Node * curr = head;
    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
struct Node * mergeResult(Node *node1,Node *node2){
   Node *start = NULL, *end =NULL;
   if(node1->data<node2->data){
       start = end = node1;
       node1 = node1->next;
   }else{
       start = end  = node2;
       node2 = node2->next;
   }
   while(node1!=NULL&&node2!=NULL){
       
       if(node1->data<node2->data){
           end->next = node1;
           end = node1;
           node1 = node1->next;
       }else{
           end->next = node2;
           end = node2;
           node2 = node2->next;
       }
   }
   if(node1 != NULL){
        end->next = node1;
    }
    else{
        end->next = node2;
    }
    return reverse(start);
}