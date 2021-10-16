/*
 * @Descroption: LeetCode 2032. 至少在两个数组中出现的值
 * @Author: EmoryHuang
 * @Date: 2021-10-16 19:23:42
 * @Method:
 * 哈希表
 * 使用哈希表记录3个数组中数字出现的数量，将出现次数大于 2 的加入 ans
 */

class Solution {
   public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        set<int> cnt1(nums1.begin(), nums1.end());
        set<int> cnt2(nums2.begin(), nums2.end());
        set<int> cnt3(nums3.begin(), nums3.end());
        unordered_map<int, int> hash;
        vector<int> ans;
        for (int num : cnt1) hash[num]++;
        for (int num : cnt2) hash[num]++;
        for (int num : cnt3) hash[num]++;
        for (auto p : hash)
            if (p.second >= 2) ans.push_back(p.first);
        return ans;
    }
};