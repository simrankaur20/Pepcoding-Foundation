#include <iostream>
using namespace std;
class myStack
{
    int *arr;
    int sz;
    int idx;
    public:
    myStack()
    {
        idx = -1;
        arr = new int[10];
        sz = 10;
    }
    myStack(int size)
    {
        idx = -1;
        arr = new int[size];
        sz = size;
    }

    void print()
    {
        for (int i = idx; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
    }

    void push(int val)
    {
        if (idx == sz)
        {
            cout << "Stack overflow";
        }
        else
        {
            idx++;
            arr[idx] = val;
        }
    }

    int pop()
    {
        if (idx == -1)
        {
            cout << "Underflow";
            return -1;
        }
        else
        {
            return arr[idx--];
        }
    }

    int getsize()
    {
        return idx + 1;
    }
    int top()
    {

        if (idx == -1)
        {
            return -1;
        }
        else
        {
            return arr[idx];
        }
    }
};