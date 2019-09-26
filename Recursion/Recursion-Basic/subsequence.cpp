#include<bits/stdc++.h>
using namespace std;
void printsubseq(string s, string ans)
{
    if(s.length() == 0)
    {
        cout<<ans<<" ";
        return;
    }

    printsubseq(s.substr(1) , s[0] + ans);
    printsubseq(s.substr(1) , ans);
}
int main()
{
    printsubseq("abc" , "");
}