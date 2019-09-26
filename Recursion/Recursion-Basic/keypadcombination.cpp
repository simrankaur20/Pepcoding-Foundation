#include<bits/stdc++.h>
using namespace std;
string arr[] = {"+" , "abc" , "def" , "ghi" , "jkl" , "mno" , "pqrs" , "tuv" ,"wx" , "yz"}; 
void keypad(string input, string ans)
{
    if(input.length() == 0)
    {
        cout<<ans<<" ";
        return ;
    }
    int firstdig = input[0] - 48;
    string tobeans = arr[firstdig];
    for(int i = 0 ; i < tobeans.length() ; i++)
    {
        char ch = tobeans[i];
        keypad(input.substr(1) , ans + ch);
    }
}

int main()
{
    keypad("235" , "");
}