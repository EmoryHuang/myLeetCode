class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int minp = prices[0],maxp=0;
        for(int i = 1 ; i<len;i++){
            maxp=max(maxp,prices[i]-minp);
            minp =min(minp,prices[i]);
        }
        return maxp;
    }
};