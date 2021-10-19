/*309. Best Time to Buy and Sell Stock with Cooldown

You are given an array prices where prices[i] is the price of a given stock on the ith day.
Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again). 

Example 1:

Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]

Example 2:

Input: prices = [1]
Output: 0 

Constraints:

1 <= prices.length <= 5000
0 <= prices[i] <= 1000
*/

class Solution {
public:
    int find(vector<int> &prices, bool buy, int pos, vector<vector<int>> &dp) {
        if(pos >= prices.size() || (buy && pos == prices.size() - 1)) {
            return 0;
        }
        
        if(dp[pos][buy] != -1) {
            return dp[pos][buy];
        }
        
        int skip = find(prices, buy, pos + 1, dp);
        
        if(buy) {
            int profit = -prices[pos] + find(prices, !buy, pos + 1, dp);
            return dp[pos][buy] = max(profit, skip);
        }
        else {
            int profit = prices[pos] + find(prices, !buy, pos + 2, dp);
            return dp[pos][buy] = max(profit, skip);
        }
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n < 2) {
            return 0;
        }
        else if(n == 2) {
            return max(0, prices[1] - prices[0]);
        }
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        
        return find(prices, true, 0, dp);
    }
};
