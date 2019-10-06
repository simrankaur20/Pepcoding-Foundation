#include<bits/stdc++.h>
using namespace std;
bool isWordPresent(vector<string> &dict , string word)
{
    for(string s : dict)
    {
        if(s.compare(word) == 0)
        {
            return true;
        }
    }
    return false;
}
bool iswordbreak(vector<string> dictionary, string word,string ans)
{
    if(word.length() == 0)
    {
        cout << ans << endl;
        return 1;
    }
    int count = 0;
    for(int i = 1 ; i <= word.length() ; i++)
    {
        string str = word.substr(0,i);
        if(isWordPresent(dictionary , str))
        {
            string latter = word.substr(i);
            count += iswordbreak(dictionary , latter , ans + str + " ");
        }
    }

    return count;
}

int main()
{
    vector<string> dictionary = {"mobile" , "samsung" , "sam" , "sung", "man" , "mango" , "icecream", "and", "go" , "i", "like", "ice","cream"};

    string statement = "ilikesamsung";
    cout<< iswordbreak(dictionary,statement, "");
}