#include<bits/stdc++.h>
using namespace std;

vector<int> freqMap(string str)
{
    vector<int> freq(26,0);

    for(int i = 0; i < str.length() ; i++)
    {
        freq[str[i] - 'a']++;
    }
    return freq;
}
void cryptoarithmetic()
{
    string str1 = "send";
    string str2 = "more";
    string str3 = "money";

    vector<int> freq = freqMap(str1 + str2 + str3);
    string ques = "";
    for(int i = 0; i < freq.size(); i++)
    {
        if(freq[i] > 0)
        {
            ques += (char)(i + 'a');
        }
    }

}

int crypto_Arithmetic_01(string ques, int vidx , vector<int> &numberagainstchar, int istaken)
{
    if(vidx == ques.length())
    {
        if(1)
        {
            return 1;
        }
        return 0;
    }

    int count = 0;
    for(int i = 0 ;i < 10; i++)
    {
        int mask = 1 << i;
        if((istaken & mask) == 0)
        {
            istaken |= mask;
            numberagainstchar[ques[vidx] - 'a'] = i;
            istaken &= mask;
        }
    }
    return count;
}


int main()
{
    cryptoarithmetic();
}