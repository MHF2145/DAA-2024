#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//Fungsi utilitas yang mengembalikan maksimal dua bilangan bulat
int max(int a, int b) { return (a > b) ? a : b; }

//Tabel memoisasi
int n;
int W;
vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));



//Fungsi utilitas untuk menyelesaikan masalah Knapsack menggunakan memoisasi
int knapSackUtil(int W, int wt[], int val[], int n) {
//Kasus Dasar
    if (n == 0 || W == 0)
        return 0;

//Periksa apakah nilai sudah dihitung
    if (dp[n][W] != -1)
        return dp[n][W];


//Jika berat barang ke-n lebih dari kapasitas Knapsack W,
//maka item ini tidak dapat dimasukkan dalam solusi optimal
    if (wt[n - 1] > W)
        dp[n][W] = knapSackUtil(W, wt, val, n - 1);
    else
        dp[n][W] = max(val[n - 1] + knapSackUtil(W - wt[n - 1], wt, val, n - 1),
                       knapSackUtil(W, wt, val, n - 1));

    return dp[n][W];
}

//Mencetak barang-barang yang dimasukkan ke dalam ransel berkapasitas W
void printknapSack(int W, int wt[], int val[], int n) {
//Inisialisasi tabel memoisasi dengan -1
    dp = vector<vector<int>>(n + 1, vector<int>(W + 1, -1));
    
//Buat tabel memoisasi menggunakan fungsi utilitas
    int res = knapSackUtil(W, wt, val, n);

    cout << res << endl;

    int w = W;
    for (int i = n; i > 0 && res > 0; i--) {
        if (res == dp[i - 1][w])
            continue;
        else {
//Item ini disertakan.
            cout << " " << wt[i - 1];

//Karena bobot ini disertakan, nilainya dikurangi
            res -= val[i - 1];
            w -= wt[i - 1];
        }
    }
}

//Kode pengemudi
int main() {
    int val[] = { 1, 4, 5, 7 };
    int wt[] = { 1, 3, 4, 5 };
    W = 7;
    n = sizeof(val) / sizeof(val[0]);

    printknapSack(W, wt, val, n);

    return 0;
}
