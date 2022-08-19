/*
 * @Descroption: LeetCode 350. 两个数组的交集 II
 * @Author: EmoryHuang
 * @Date: 2021-06-11 16:51:00
 * @解题思路:
 * 与前一题不同的是，可以有重复元素
 * 排序 + 双指针
 * 先排序，然后使用双指针遍历数组，若元素相同则放入集合
 * 否则将较小一方的指针后移
 */

class Solution {
   public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> unit;
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                unit.push_back(nums1[i]);
                i++;
                j++;
            } else if (nums1[i] > nums2[j])
                j++;
            else
                i++;
        }
        return unit;
    }
};