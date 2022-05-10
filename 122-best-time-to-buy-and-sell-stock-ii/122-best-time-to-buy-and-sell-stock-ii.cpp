// TC : O(N)
// SC : O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int buy = 0;
        int sell = 0;
        
        int total_profit = 0;
        
        // Increment the sell index till price[i] >= price[i-1]. If price[i] < price[i-1], then sell the stock and update buy and sell as i.
        
        for(int i=1;i<prices.size();i++){
            if(prices[i] >= prices[i-1]){
                sell++;
            }
            else{
                // Sell the stock
                total_profit += (prices[sell] - prices[buy]);
                buy = sell = i;
            }
        }
        
        // If suppose for the last element, price[i] >= price[i-1], then sell would be updated but since it is last element, it will not be sold.
        // So, in the end, we have to handle such situation and again add (prices[sell] - prices[buy]) to total_profit.
        // Suppose for the last element, price[i] < price[i-1], then buy and sell will be same. Hence (prices[sell] - prices[buy]) wil be 0.
        
        total_profit += (prices[sell] - prices[buy]);
        
        return total_profit;
    }
};