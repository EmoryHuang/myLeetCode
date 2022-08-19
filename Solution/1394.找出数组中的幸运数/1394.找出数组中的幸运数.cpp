/*
 * @Descroption: LeetCode 1394. 找出数组中的幸运数
 * @Author: EmoryHuang
 * @Date: 2021-08-20 19:46:22
 * @Method:
 * 哈希表记录每个字符出现的次数
 * 若出现频次和它的数值大小，则记录并找到最大值
 */

class Solution {
   public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> hash;
        for (int num : arr) hash[num]++;
        int ans = -1;
        unordered_map<int, int>::iterator it;
        for (auto v : hash)
            if (v.first == v.second) ans = max(ans, v.first);
        return ans;
    }
};