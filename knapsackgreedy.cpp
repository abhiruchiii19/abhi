/*#include <bits/stdc++.h>
struct Item {
    int profit;
    int weight;
    Item(int profit, int weight) : profit(profit), weight(weight) {}
};
bool compare(Item a, Item b) {
    double ratioA = (double)a.profit / a.weight;
    double ratioB = (double)b.profit / b.weight;
    return ratioA > ratioB;
}
double fractionalKnapsack(int W, std::vector<Item>& items) {
    std::sort(items.begin(), items.end(), compare);
    double totalProfit = 0.0;
    for (const Item& item : items) {
        if (W >= item.weight) {
            totalProfit += item.profit;
            W -= item.weight;
        } else {
            totalProfit += (double)W / item.weight * item.profit;
            break;
        }
    }
    return totalProfit;
}
int main() {
    int W = 50;
    std::vector<Item> items = {{60, 10}, {100, 20},  {120, 30},{34, 7}};
    double maxProfit = fractionalKnapsack(W, items);
    std::cout << "Maximum Profit: " << maxProfit << std::endl;
    return 0;
}*/

#include <bits/stdc++.h>
using namespace std;
int max(int a, int b) {
    return (a > b) ? a : b;
}
int knapsack(int W, std::vector<int>& wt, std::vector<int>& val, int n) {
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (wt[i - 1] <= w) {
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][W];
}
int main() {
    int W = 50;
    std::vector<int> wt = {10, 20, 30};
    std::vector<int> val = {60, 100, 120};
    int n = wt.size();

    int maxProfit = knapsack(W, wt, val, n);
    std::cout << "Maximum Profit: " << maxProfit << std::endl;
    return 0;
}

