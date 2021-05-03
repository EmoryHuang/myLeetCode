class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int sum = 0,maxw=0;
        for(int w : weights){
            sum += w;
            maxw = max(maxw,w);
        }
        while(maxw <sum){
            int tmp=0,day=1;
            int mid = maxw + (sum - maxw) /2;
            for(int w:weights){
                tmp += w;
                if(tmp > mid){
                    day++;
                    tmp = w;
                }
            }
            if(day <= D) sum = mid;
            else maxw = mid + 1;
        }
        return maxw;
    }
};