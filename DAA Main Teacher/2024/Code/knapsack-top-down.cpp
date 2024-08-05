#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }

int n;
int W;
vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));

int knapSackUtil(int W, int wt[], int val[], int n)
{
    if (n == 0 || W == 0)
        return 0;

    if (dp[n][W] != -1)
        return dp[n][W];

    if (wt[n - 1] > W)
        dp[n][W] = knapSackUtil(W, wt, val, n - 1);
    else
        dp[n][W] = max(val[n - 1] + knapSackUtil(W - wt[n - 1], wt, val, n - 1),
                       knapSackUtil(W, wt, val, n - 1));

    return dp[n][W];
}

void printknapSack(int W, int wt[], int val[], int n)
{

    dp = vector<vector<int>>(n + 1, vector<int>(W + 1, -1));

    int res = knapSackUtil(W, wt, val, n);

    cout << res << endl;

    int w = W;
    for (int i = n; i > 0 && res > 0; i--)
    {
        if (res == dp[i - 1][w])
            continue;
        else
        {

            cout << " " << wt[i - 1];

            res -= val[i - 1];
            w -= wt[i - 1];
        }
    }
}

int main()
{
    int val[] = {1, 4, 5, 7};
    int wt[] = {1, 3, 4, 5};
    W = 7;
    n = sizeof(val) / sizeof(val[0]);

    printknapSack(W, wt, val, n);

    return 0;
}
