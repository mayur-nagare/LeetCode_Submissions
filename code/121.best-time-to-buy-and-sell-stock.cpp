class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int min_ind = prices[0];
        
        for(int i=1; i<prices.size();i++){
            max_profit = max(prices[i] - min_ind, max_profit);
            min_ind = min(prices[i], min_ind);
        }
        return max_profit;
    }
};