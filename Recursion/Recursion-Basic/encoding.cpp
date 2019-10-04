#include<bits/stdc++.h>
using namespace std;
int encode(string ques , string ans)
{
    if(ques.length() == 0)
    {
        cout<< ans<<endl;
        return 1;
    }

    char ch = ques[0];
    int count = 0;
    if(ch == '0')
    {
        count += encode(ques.substr(1) , ans);
    }
    else
    {
        count += encode(ques.substr(1) , ans + (char)(ch - '0' + 'a' - 1));
        if(ques.length() >1)
        {
            char ch1 = ques[1];
            int num = (ch - '0') * 10 + (ch1 - '0');
            if(num <= 26)
            {
                count += encode(ques.substr(2) ,ans + (char)( 'a'+ num - 1));
            }
        }
    }
    return count;
    
}
void encoding()
{
    cout << encode("1123" , "");
}
int main()
{
    encoding();
}