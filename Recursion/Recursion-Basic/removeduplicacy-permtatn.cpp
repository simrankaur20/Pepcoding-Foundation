#include<bits/stdc++.h>
using namespace std;
void permu(string ip, string ans)
{
    if(ip.length() == 0)
    {
        return ;
    }
    bool out[26] = {};
    for(int i=0 ; i  < ip.length(); i++ )
    {
        string np = ip.substr(0,i) + ip.substr(i+1);
        if(!out[ip[i]])
        {
            permu()
        }
    }


}
int main()
{

}