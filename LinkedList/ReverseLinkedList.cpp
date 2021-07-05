#include<iostream>
using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x){
        data = x;
        next = NULL;
    }
};
// Reverse Linked List Iterative
class Solution
{
    public:
    struct Node* reverseList(struct Node *head)
    {   
        Node * curr = head;
        Node * prev =NULL;
        Node * next = NULL;
        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        return head;
    }
    
};

// Reverse a Doubly Linked List Iterative
struct Node{
    int data;
    Node * next;
    Node * prev;
    Node (int x){
        data=x;
        next=NULL;
        prev=NULL;
    }
};
Node* reverseDLL(Node * head)
{
     Node * prev= NULL;
     Node * next =NULL;
     Node * curr =head;
     while(curr!=NULL){
         next = curr->next;
         curr->next = prev;
         curr->prev= next;  // just added this line for doubly linked list
         prev = curr;
         curr = next;
     }
     return prev;
}