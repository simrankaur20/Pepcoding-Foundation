#include<iostream>
using namespace std;
class myqueue{
    int front, rear, sz , totalsize;
    int * arr;
    public:
    myqueue()
    {
        front = -1;
        rear = -1;
        sz = 0;
        arr = new int[10];
        totalsize = 10;
    }
    void push(int val)
    {
        if(sz == totalsize)
        {
            cout<<"overflow";
            return ;
        }
         rear = (rear+1) % totalsize;
        arr[rear] = val;
        sz++;
    }

    int pop()
    {
        if(sz == 0)
        {
            cout<<"Underflow";
            return -1; 
        }
        front = (front+1) %totalsize;
        sz--;
        return arr[front];

    }

    bool isEmpty()
    {
        return sz == 0;
    }

    void print()
    {
        for(int i = front+1; i!= rear+1 ; i = (i+1) % totalsize)
        {
            cout<<arr[i]<<" ";
        }
    }


};