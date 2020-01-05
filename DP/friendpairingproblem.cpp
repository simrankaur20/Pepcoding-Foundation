#include <bits/stdc++.h>
using namespace std;

int friendpairing_rec(int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n == 1)
    {
        return 1;
    }
    return friendpairing_rec(n - 1) + friendpairing_rec(n - 2) * (n - 1);
}

int friendpairing_tab(int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i < n + 1; i++)
    {
        dp[i] = dp[i - 1] + (i - 1) * dp[i - 2];
    }
    return dp[n];
}

int main()
{
    cout << friendpairing_tab(3);
}