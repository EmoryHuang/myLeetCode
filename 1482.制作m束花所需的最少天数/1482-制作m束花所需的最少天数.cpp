class Solution {
   public:
    bool makeBloom(vector<int>& bloomDay, int day, int m, int k) {
        int bloom = 0;  // 花的数量
        int num = 0;    // 花束的数量
        for (int i = 0; i < bloomDay.size() && num < m; i++) {
            if (bloomDay[i] <= day) {
                bloom++;  // 花开
                if (bloom == k) {
                    num++;
                    bloom = 0;
                }
            } else  // 不是连续的花
                bloom = 0;
        }
        return num >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (m * k > n) return -1;
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        while (low < high) {
            int day = low + (high - low) / 2;
            if (makeBloom(bloomDay, day, m, k))  //如果 day 天能够做出 m 朵花
                high = day;                      //继续查找更小的值
            else
                low = day + 1;
        }
        return low;
    }
};