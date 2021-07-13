#include<bits/stdc++.h>
using namespace std;
class StackQueue{
private:   
    stack<int> s1;
    stack<int> s2;
public:
    void push(int);
    int pop();
}; 

//Function to push an element in queue by using 2 stacks.
void StackQueue :: push(int x){
    s1.push(x);
    // Your Code
}
//Function to pop an element from queue by using 2 stacks.
int StackQueue :: pop(){
    // we will  store elements in stack2 in reverse order
    // and in pop function we will pop it from second stack only
    // if second stack empty then we will transfer all the elements of first stack in second
    // if both empty then we will return -1;
    if(s1.empty()&&s2.empty()) return -1;
    if(s2.empty()){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int ele = s2.top();
        s2.pop();
        return ele;
    }else{
        int ans = s2.top();
        s2.pop();
        return ans;
    }
}
