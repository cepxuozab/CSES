#include <iostream>
#include <vector>

auto MaximumNumberPages(std::vector<int> const &prices, std::vector<int> const &pages, int maximum_total_price) -> int;

auto main() -> int {
    int number_of_book;
    int maximum_total_price;
    std::cin >> number_of_book >> maximum_total_price;
    std::vector<int> prices(number_of_book);
    for (auto &price: prices) {
        std::cin >> price;
    }
    std::vector<int> pages(number_of_book);
    for (auto &page: pages) {
        std::cin >> page;
    }
    std::cout << MaximumNumberPages(prices, pages, maximum_total_price);
}

auto MaximumNumberPages(std::vector<int> const &prices, std::vector<int> const &pages, int maximum_total_price) -> int {
    std::vector<int> dp(maximum_total_price + 1, 0);
    for (size_t i = 0; i < prices.size(); ++i) {
        for (int j = maximum_total_price; j >= prices[i]; --j) {
            dp[j] = std::max(dp[j], dp[j - prices[i]] + pages[i]);
        }
    }
    return dp.back();
}