/*
121. Best Time to Buy and Sell Stock

You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.

Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.

Constraints:

1 <= prices.length <= 105
0 <= prices[i] <= 104
*/

class Solution {
public:
    int find(vector<int> &prices, int i, int k, bool buy, vector<vector<int>> &dp) {
        if(i >= prices.size() || k <= 0) {
            return 0;
        }
        
        if(dp[i][buy] != -1) {
            return dp[i][buy];
        }
        
        if(buy) {
            return dp[i][buy] = max(-prices[i] + find(prices, i + 1, k, !buy, dp), find(prices, i + 1, k, buy, dp));
        }
        else {
            return dp[i][buy] = max(prices[i] + find(prices, i + 1, k - 1, !buy, dp), find(prices, i + 1, k, buy, dp));
        }
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        
        return find(prices, 0, 1, 1, dp);
    }
};
