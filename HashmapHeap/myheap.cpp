#include<bits/stdc++.h>
using namespace std;
class myheap{
    vector<int> arr;
    bool ismax;
    public:
    myheap()
    {
        ismax = true;
    }
    int compare(int ar1, int ar2)
    {
        if(ismax)
        {
            return ar1-ar2;
        }
        else
        {
            return ar2-ar1;
        }
        
    }

    myheap(vector<int> &ar)

};
int main()
{

}