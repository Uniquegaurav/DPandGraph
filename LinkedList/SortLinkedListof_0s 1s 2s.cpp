#include <bits/stdc++.h>
using namespace std;
/* Link list Node */
// Given a linked list of N nodes where nodes can contain values 0s, 1s, and 2s only.
// The task is to segregate 0s, 1s, 
// and 2s linked list such that all zeros segregate to head side, 2s at the end of the linked list, 
// and 1s in the mid of 0s and 2s.
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
      int arr[3] = {0};
      for(Node * it = head ;it !=NULL;it = it->next){
          arr[it->data] += 1;
      }
      int i =0 ;
      for(Node * it = head ;it !=NULL;it = it->next){
          while(arr[i]==0) i += 1;
          it->data = i;
          arr[i] -= 1;
      } 
      return head;
    }
};