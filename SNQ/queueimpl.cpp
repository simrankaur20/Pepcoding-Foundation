#include<bits/stdc++.h>
#include"myqueue.h"
using namespace std;
int main()
{
    myqueue q;
    q.push(10);
    
    q.push(20);
    
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.push(100);
    q.print();
}