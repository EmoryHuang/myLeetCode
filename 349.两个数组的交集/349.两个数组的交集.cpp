/*
 * @Descroption: LeetCode 349. 两个数组的交集
 * @Author: EmoryHuang
 * @Date: 2021-06-11 16:30:00
 * @解题思路:
 * 方法一：使用封装函数
 *
 * 方法二：排序 + 双指针
 * 先排序，然后使用双指针遍历数组，若元素相同则放入集合
 * 否则将较小一方的指针后移
 */

class Solution {
   public:
    // 方法一：使用封装函数
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> ans;
        unordered_set<int> s1(nums1.begin(), nums1.end());
        for (auto num : nums2) {
            if (s1.find(num) != s1.end()) ans.insert(num);
        }
        return vector<int>(ans.begin(), ans.end());
    }

    // 方法二：排序 + 双指针
    // vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    //     sort(nums1.begin(), nums1.end());
    //     sort(nums2.begin(), nums2.end());
    //     unordered_set<int> unit;
    //     int i = 0, j = 0;
    //     while (i < nums1.size() && j < nums2.size()) {
    //         if (nums1[i] == nums2[j]) {
    //             unit.insert(nums1[i]);
    //             i++;
    //             j++;
    //         } else if (nums1[i] > nums2[j])
    //             j++;
    //         else
    //             i++;
    //     }
    //     vector<int> ans(unit.begin(), unit.end());
    //     return ans;
    // }
};