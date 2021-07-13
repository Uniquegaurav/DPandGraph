#include<bits/stdc++.h>
using namespace std;
class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};
void QueueStack :: push(int x){
    q1.push(x);
}
int QueueStack :: pop()
{   
    if(q1.empty()) return -1;
    // transfering all the q1 data to q2 until 1 element left
    while(q1.size()>1){
        q2.push(q1.front());
        q1.pop();
    }
    int e = q1.front(); 
    q1.pop();
    // the one last element will be our ans which we have to pop
    // now tranfering all data back to q1
    while(!q2.empty()){
        q1.push(q2.front());
        q2.pop();
    }
    // and returning the last element
    return e;
    
}