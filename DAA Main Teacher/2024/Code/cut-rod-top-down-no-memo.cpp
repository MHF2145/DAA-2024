#include <iostream>
#include <vector>
#include <chrono>
#include <climits> // Untuk mengakses INT_MIN

using namespace std;
using namespace std::chrono;

// Fungsi untuk mencari potongan terbaik yang menghasilkan laba maksimal
int cutRod(vector<int> &price, int n)
{
    if (n == 0)
        return 0;

    int q = INT_MIN; // Menggunakan INT_MIN dari <climits>
    for (int i = 0; i < n; ++i)
    {
        q = max(q, price[i] + cutRod(price, n - i - 1));
    }
    return q;
}

int main()
{
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};

    vector<int> lengths = {5, 10, 15, 20, 25, 30, 40, 45, 50};

    for (int length : lengths)
    {
        auto start = high_resolution_clock::now();
        int maxProfit = cutRod(price, length);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);

        cout << "For length " << length << ", max profit: " << maxProfit << ", Runtime: " << duration.count() << " microseconds." << endl;
    }

    return 0;
}
