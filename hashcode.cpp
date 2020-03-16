#include<bits/stdc++.h>
using namespace std;

class libdetails{
public:
    int books, signdays, perday;
    vector<int> availbooks;
};

class mycomp{
    public:
    bool operator()(libdetails i1, libdetails i2)
    {
        return i1.signdays > i2.signdays;
    }
};

int calc(vector<libdetails> &l, int totdays, int libr)
{
    priority_queue<libdetails, vector<libdetails> , mycomp> pg;

    for(int i =0; i < l.size() ;i++)
    {
        pq.push(l[i]);
    }
    int c =0;
    vector<int> ans(totdays);
    int score = 0;
    while(!pq.empty() && c <  totdays)
    {
       libdetails lcurr = pq.pop();
       int j = 0;
       for(int r= c+lcurr.signdays;r < totdays; r++ )
       {
           for(int y =0; y< lcurr.perday; y++)
           {
               score += lcurr.availbooks[j++];
               if(j == lcurr.availbooks.size())
               {
                   break;
               }
           }
           if(j == lcurr.availbooks.size())
            {
                   break;
            }
       }

        c++;
    }
    return score;
}
int main()
{

    int b, l , d;
    cin>>b>>l>>d;
    vector<int> scores(b);
    for(int i =0;i< b;i++)
    {
        cin>> scores[i];
    }
    vector<libdetails> v;
    for(int i=0;i<l;i++)
    {
        int a, b, c;
        cin>>a>>b>>c;
        libdetails l1;
        l1.books = a;
        l1.signdays = b;
        l1.perday = c;
        for(int i=0;i<a;i++)
        {
            int x;
            cin>>x;
            l1.availbooks.push_back(x);
        }
        v.push_back(l1);
    }

    cout<<calc(v, d , l);

}
