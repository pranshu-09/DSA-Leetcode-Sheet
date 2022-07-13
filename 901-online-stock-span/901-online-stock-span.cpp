// TC : O(N)
// SC : O(N)
class StockSpanner {
    stack<pair<int, int>>s;
    int idx = 0;
    
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        
        if(s.empty()){
            s.push({price, idx++});
            return 1;
        }
            
        while(!s.empty() and s.top().first <= price){
            s.pop();
        }

        int best_idx = s.empty() ? idx+1 : idx - s.top().second;

        s.push({price, idx++});        
        
        return best_idx;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */