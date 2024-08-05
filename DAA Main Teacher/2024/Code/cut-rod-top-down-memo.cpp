#include <iostream>
#include <vector>
#include <climits>
#include <chrono>
#include <iomanip> // Untuk std::fixed dan std::setprecision

// top-dwn memo
int cutRodUtil(const std::vector<int> &prices, int n, std::vector<int> &memo)
{
    if (n == 0)
    {
        return 0;
    }
    if (memo[n] >= 0)
    {
        return memo[n];
    }

    int q = INT_MIN;
    for (int i = 1; i <= n; ++i)
    {
        q = std::max(q, prices[i - 1] + cutRodUtil(prices, n - i, memo));
    }

    memo[n] = q;
    return q;
}

int cutRod(const std::vector<int> &prices, int n)
{
    std::vector<int> memo(n + 1, -1);
    return cutRodUtil(prices, n, memo);
}

int main()
{
    // array harga dan panjang
    std::vector<int> prices = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};

    std::vector<int> test_lengths = {5, 10, 15, 20, 25, 30, 40, 45, 50};

    for (int n : test_lengths)
    {
        // memastikan panjang array harga cukup test yang
        while (prices.size() < n)
        {
            prices.push_back(prices.back() + 1); // tingkatkan harga jika dibutuhkan
        }

        auto start = std::chrono::high_resolution_clock::now();
        int max_revenue = cutRod(prices, n);
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double, std::milli> duration = end - start; // mengubah ke milidetik

        std::cout << std::fixed << std::setprecision(4); // presisi 4 digit di belakang koma
        std::cout << "Maximum revenue for rod length " << n << " is " << max_revenue
                  << ". Time taken: " << duration.count() << " ms" << std::endl;
    }

    return 0;
}
