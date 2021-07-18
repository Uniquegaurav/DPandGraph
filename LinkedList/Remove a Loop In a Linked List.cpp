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
    void removeLoop(Node* head)
    {
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
        Node *slow=head;
       Node *fast = head;
        if(head == NULL || head->next == NULL)
                return;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                break;
            }
        }
        if(slow==head){
            while(slow->next!=head){
                slow=slow->next;
            }
            slow->next = NULL;
        }
        if(slow == fast){
        slow = head;
        while(slow->next != fast->next){
            if(slow == fast->next){
                fast->next == NULL;
            }
            slow = slow->next;
            fast = fast->next;
        }

        fast->next=NULL;
        }
    }
    
};