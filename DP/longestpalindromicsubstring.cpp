#include <bits/stdc++.h>
using namespace std;
int lps_rec(string s)
{
    if (s.length() <= 1)
    {
        return 1;
    }
    if (s[0] == s[s.length() - 1])
    {
        int ans = lps_rec(s.substr(1, s.length() - 2));
        if (ans == s.length() - 2)
        {
            return ans + 2;
        }
        else
        {
            return ans;
        }
    }
    else
    {
        int a1 = lps_rec(s.substr(1));
        int a2 = lps_rec(s.substr(0, s.length() - 1)); //this call is not reqd as it would be covered in the other two calls
        int a3 = lps_rec(s.substr(1, s.length() - 2));
        return max(a1, max(a2, a3));
    }
}

void fillpalinmatrix(string s, vector<vector<bool>> &palin)
{
    for (int gap = 0; gap < s.length(); gap++)
    {
        for (int i = 0, j = gap; j < palin[0].size(); j++, i++)
        {
            if (gap == 0)
            {
                palin[i][j] = true;
            }
            else if (s[i] == s[j])
            {
                if (gap == 1)
                    palin[i][j] = true;
                else
                    palin[i][j] = palin[i + 1][j - 1];
            }
        }
    }
}

int lps_dp(string s)
{
    vector<vector<int>> dp(s.length(), vector<int>(s.length(), 0));
    vector<vector<bool>> palin(s.length(), vector<bool>(s.length(), false));

    fillpalinmatrix(s, palin);

    for (int gap = 0; gap < s.length(); gap++)
    {
        for (int i = 0, j = gap; j < dp[0].size(); i++, j++)
        {
            if (gap == 0)
            {
                dp[i][j] = 1;
            }
            else if (s[i] == s[j])
            {
                if (gap == 1)
                {
                    dp[i][j] = 2;
                }
                else if (palin[i + 1][j - 1])
                {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                else
                {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
            else
            {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }

    for(int i=0;i<dp.size();i++)
    {
        for(int j= 0; j<dp[0].size() ; j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[0][s.length()-1];
}

string lps(string s)
{
    vector<vector<string>> dp(s.length(), vector<string>(s.length(), ""));
    vector<vector<bool>> palin(s.length(), vector<bool>(s.length(), false));

    fillpalinmatrix(s, palin);

    for(int gap = 0; gap < s.length(); gap++)
    {
        for(int i = 0, j= gap; j< dp[0].size(); i++, j++)
        {
            if(gap == 0)
            {
                dp[i][j] = s[i];
            }
            else if(s[i] == s[j])
            {
                if(gap == 1)
                {
                    string t = "";
                    t = s[i] + s[j];
                    dp[i][j] = t;
                }
                else if(palin[i+1][j-1])
                {
                    dp[i][j] = s[i] + dp[i+1][j-1] + s[j];
                }
                else
                {
                    if(dp[i][j-1].length() > dp[i+1][j].length())
                    {
                        dp[i][j] = dp[i][j-1];
                    }
                    else
                    {
                        dp[i][j] = dp[i+1][j];
                    }
                    
                }  
            }
            else
                {
                    if(dp[i][j-1].length() > dp[i+1][j].length())
                    {
                        dp[i][j] = dp[i][j-1];
                    }
                    else
                    {
                        dp[i][j] = dp[i+1][j];
                    }
                    
                }
        }
    }


    for(int i=0;i<dp.size();i++)
    {
        for(int j= 0; j<dp[0].size() ; j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    } 
    
    return dp[0][s.length()-1];
}

int main()
{
    cout << lps("babam");
}