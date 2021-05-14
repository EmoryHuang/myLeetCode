class Solution {
   public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int cur = 0, total = 0, start = 0;
        for (int i = 0; i < n; i++) {
            total += gas[i] - cost[i];
            cur += gas[i] - cost[i];
            if (cur < 0) {  // 一个站的收益如果小于0
                cur = 0;
                start = i + 1;  // 下一站作为起点
            }
        }
        return total < 0 ? -1 : start;  // 总和必须大于等于0
    }
};