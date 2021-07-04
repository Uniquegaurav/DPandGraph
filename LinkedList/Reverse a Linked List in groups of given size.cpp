 #include<bits/stdc++.h>
 using namespace std;
 
 struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;

    class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        node * prev = NULL;
        node * next = NULL;
        node * curr = head;
        int count  =0 ;
        while(curr!=NULL&&count<k){
            next  = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count += 1;
        }
        if(curr!=NULL){
            head->next = reverse(curr,k);
        }
        return prev;
        // Complete this method
    }
};