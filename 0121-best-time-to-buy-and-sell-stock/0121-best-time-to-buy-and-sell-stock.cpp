class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX;
        int max_profit = 0;
        
        for (int price : prices) {
            if (price < min_price) {
                min_price = price; // Update the minimum buying price seen so far
            } else if (price - min_price > max_profit) {
                max_profit = price - min_price; // Update maximum profit
            }
        }
        
        return max_profit;
    }
};