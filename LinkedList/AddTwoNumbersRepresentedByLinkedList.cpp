#include<bits/stdc++.h>
using namespace std;

// Given two numbers represented by two linked lists of size N and M. The task is to return a sum list.
//  The sum list is a linked list representation of the addition of two input numbers from the last
// https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1#
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    Node * reverse(Node *head){
        Node * prev =NULL;
        Node * next =NULL;
        Node * curr = head;
        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev =curr;
            curr = next;
        }
        return prev;
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second){
      first  = reverse(first);
      second = reverse(second);
      int c = 0;
      Node * curr = NULL;
      Node * start =NULL;
      while(first!=NULL||second!=NULL){
          int s = c + (first?first->data:0) + (second?second->data:0);
          if(s>=10) c = 1;
          else c = 0;
          s = s%10;
          Node * temp = new Node(s);
          if(curr==NULL){
              curr = temp;
              start = temp;
          } 
          else {
              curr->next  = temp;
              curr = temp;
          }
          if(first) first = first->next;
          if(second) second = second->next;
      }
      if(c>0){
          Node * temp = new Node(1);
          curr->next  = temp;
          curr = temp;
      }
      Node * last = reverse(start);
      return curr;
    }
};