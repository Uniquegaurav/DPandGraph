// Given a linked list of N nodes. The task is to check if the linked list has a loop.
// Linked list can contain self loop.
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};
// detect loop in linked list first method 
bool detectLoop(Node* head)
{
        unordered_set<Node *> s;
        while(head->next!=NULL){
            if(s.find(head)!=s.end()){
                return true;
            }else{
                s.insert(head);
            }
            head = head->next;
        }
        return false;
        // your code here
}
// detect loop in linked list best method
bool detectLoop(Node* head){
       Node * slow = head;
       Node * fast = head;
       while(fast!=NULL&&fast->next!=NULL){
           slow =  slow->next;
           fast  = fast->next->next;
           if(slow==fast) return true;
       }
       return false;
}