/*
 * @Descroption: LeetCode 274. H 指数
 * @Author: EmoryHuang
 * @Date: 2021-04-05 18:18:36
 * @解题思路:
 * 先对数组进行排序，
 * 设`h = citations.length - i`，即至多有`h`篇论文分别引用了至少`citation[i]`次
 * 只要`citation[i] ≥ h`，就满足题意
 */

class Solution {
   public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int len = citations.size();
        for (int i = 0; i < len; i++) {
            int h = len - i;
            if (h <= citations[i]) return h;
        }
        return 0;
    }
};