#include <iostream>
#include <vector>
#include <climits>
#include <chrono>

// bottom-up memo
int cutRod(const std::vector<int>& prices, int n) {
    std::vector<int> dp(n + 1, 0);

    for (int j = 1; j <= n; ++j) {
        int max_val = INT_MIN;
        for (int i = 1; i <= j; ++i) {
            max_val = std::max(max_val, prices[i - 1] + dp[j - i]);
        }
        dp[j] = max_val;
    }

    return dp[n];
}

int main() {
    // array harga dan panjang
    std::vector<int> prices = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};

    std::vector<int> test_lengths = {5, 10, 15, 20, 25, 30, 40, 45, 50};

    for (int n : test_lengths) {
        // memastikan panjang array harga cukup test yang berlangsung
        while (prices.size() < n) {
            prices.push_back(prices.back() + 1); // tingkatkan harga jika dibutuhkan
        }

        auto start = std::chrono::high_resolution_clock::now();
        int max_revenue = cutRod(prices, n);
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> duration = end - start;

        std::cout << "Maximum revenue for rod length " << n << " is " << max_revenue
                  << ". Time taken: " << duration.count() << " seconds" << std::endl;
    }

    return 0;
}
