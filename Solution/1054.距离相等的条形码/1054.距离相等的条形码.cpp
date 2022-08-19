/*
 * @Descroption: LeetCode 1054. ������ȵ�������
 * @Author: EmoryHuang
 * @Date: 2021-09-07 20:53:58
 * @Method:
 * ����һ��ֱ������
 * ���ù�ϣ��ͳ��Ԫ�ص����������Ӵ�С��������
 * Ȼ���λ���룬��Ԫ�ص�Ƶ�δ�С˳�򣬽�Ԫ�ظ�λ����
 * ����������
 * �뷽��һ���ƣ���ͬ�ľ��ǲ�ֱ�������ʹ�ô����
 */

class Solution {
   public:
    // ����һ��ֱ������
    // vector<int> rearrangeBarcodes(vector<int>& barcodes) {
    //     unordered_map<int, int> hash;
    //     for (int num : barcodes) hash[num]++;
    //     vector<pair<int, int>> order;
    //     for (auto it = hash.begin(); it != hash.end(); ++it) order.push_back({it->first, it->second});
    //     sort(order.begin(), order.end(), [](pair<int, int> a, pair<int, int> b) { return a.second > b.second; });
    //     int n = barcodes.size();
    //     vector<int> cur, ans(n);
    //     // Ƶ�δ�С��Ԫ��
    //     for (int i = 0; i < order.size(); i++) {
    //         auto [key, val] = order[i];
    //         while (val--) cur.push_back(key);
    //     }
    //     int j = 0;
    //     // ��Ԫ�ص�Ƶ�δ�С˳�򣬽�Ԫ�ظ�λ����
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