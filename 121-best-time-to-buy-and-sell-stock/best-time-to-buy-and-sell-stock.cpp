class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int buy=0;
       int sell=1;
       int mx=0;
       while(sell< prices.size())
       {
        if(prices[sell]>prices[buy])
        {
            int profit=prices[sell]-prices[buy];
            mx=max(mx,profit);
        }
        else
        {
            buy=sell;
        }
        sell++;
      
       }
       return mx;
    }
    };