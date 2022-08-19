/*
 * @Descroption: LeetCode 1054. 距离相等的条形码
 * @Author: EmoryHuang
 * @Date: 2021-09-07 20:53:58
 * @Method:
 * 方法一：直接排序
 * 先用哈希表统计元素的数量，并从大到小进行排序
 * 然后隔位插入，按元素的频次大小顺序，将元素隔位插入
 * 方法二：堆
 * 与方法一类似，不同的就是不直接排序而使用大根堆
 */

class Solution {
   public:
    // 方法一：直接排序
    // vector<int> rearrangeBarcodes(vector<int>& barcodes) {
    //     unordered_map<int, int> hash;
    //     for (int num : barcodes) hash[num]++;
    //     vector<pair<int, int>> order;
    //     for (auto it = hash.begin(); it != hash.end(); ++it) order.push_back({it->first, it->second});
    //     sort(order.begin(), order.end(), [](pair<int, int> a, pair<int, int> b) { return a.second > b.second; });
    //     int n = barcodes.size();
    //     vector<int> cur, ans(n);
    //     // 频次大到小的元素
    //     for (int i = 0; i < order.size(); i++) {
    //         auto [key, val] = order[i];
    //         while (val--) cur.push_back(key);
    //     }
    //     int j = 0;
    //     // 按元素的频次大小顺序，将元素隔位插入
    //     for (int i = 0; i < n; i += 2) ans[i] = cur[j++];
    //     for (int i = 1; i < n; i += 2) ans[i] = cur[j++];
    //     return ans;
    // }

    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> hash;
        for (int num : barcodes) hash[num]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>> q;
        for (auto it = hash.begin(); it != hash.end(); ++it) {
            int tmp = it->second;
            while (tmp--) q.push({it->second, it->first});
        }
        int n = barcodes.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i += 2) {
            ans[i] = q.top().second;
            q.pop();
        }
        for (int i = 1; i < n; i += 2) {
            ans[i] = q.top().second;
            q.pop();
        }
        return ans;
    }
};