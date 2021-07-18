
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
/* Should return data of intersection point of two linked
   lists head1 and head2.
   If there is no intersecting point, then return -1. */
int intersectPoint(Node* head1, Node* head2)
{   
    if(head1==NULL||head2==NULL){
        return -1;
    }
    Node * p1 = head1;
    Node * p2 = head2;
    while(p1!=p2){
        if(p1==NULL){
            p1 =head2;
        }else{
            p1 = p1->next;
        }
        if(p2==NULL){
            p2 = head1;
        }else{
            p2 = p2->next;
        }
    }
    if(p1==NULL&&p2==NULL){
        return -1;
    }else{
        return p1->data;
    }
    // Your Code Here
}