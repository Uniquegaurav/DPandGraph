// Given a linked list of N nodes such that it may contain a loop.
// A loop here means that the last node of the link list is connected to the node at position X.
// If the link list does not have any loop, X=0.
// Remove the loop from the linked list, if it is present
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
class Solution
{
    public:
    void removeLoop(Node* head){

        /*
        if(head==NULL){
            return;
        }
        unordered_set<Node *> s;
        bool loop_found = false;
        Node * curr =head->next;
        Node * prev = head;
        s.insert(head);
        while(curr!=NULL){
            if(s.find(curr)!=s.end()){
                loop_found = true;
                break;
            }else{
                s.insert(head);
            }
            head = head->next;
            prev = prev->next;
        }
        if(loop_found){
            curr->next = NULL;
        }
        // code here
        // just remove the loop without losing any nodes
        */
       // first we are trying to detect the loop 
        Node *slow=head;
        Node *fast = head;
        if(head == NULL || head->next == NULL)
                return;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                // if slow is equals to fast then there exists a loop nd we will break
                break;
            }
        }
        // after detecting the loop we will remove it
        if(slow==head){
            // if slow is equal to head it means loop starting point is head only
            // now we will go to last node and last->next  = NULL and break the loop
            while(slow->next!=head){
                slow=slow->next;
            }
            slow->next = NULL;
        }
        if(slow == fast){
            // if slow == fast then we found the loop and now we keep fast as it is but
            // we  will point slow to head 
            slow = head;
            // now we will keep on incrementing slow and fast by one till we found loop
            // start point which will be at slow->next == fast->next
            while(slow->next != fast->next){
                if(slow == fast->next){
                    fast->next == NULL;
                }
                slow = slow->next;
                fast = fast->next;
            }
             // before (loop start node) point fast will be point to (loop start node) and now we will just break that
            fast->next=NULL;
        }
    }
    
};