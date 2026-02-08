class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=0,sell=1,mx=0;
        while(sell<prices.size())
        {
            if(prices[buy]<prices[sell])
            {
                int profit=prices[sell]-prices[buy];
                mx=max(mx,profit);
            }
            else
            {
                buy=sell;
            }
            sell++;}
    
    return mx;
    }
    
};