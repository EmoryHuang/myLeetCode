/*
 * @Descroption: LeetCode 496. 下一个更大元素 I
 * @Author: EmoryHuang
 * @Date: 2021-08-12 19:13:52
 * @Method:
 * 单调栈 + 哈希表
 * 维护一个单调栈，统计 nums2 中当前字符右边更大的数组
 * 然后遍历 nums1 同样是对应位置的比较
 */

class Solution {
   public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> hash;
        for (int num : nums2) {
            // 维护一个单调栈
            while (!st.empty() && st.top() < num) {
                hash[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }
        for (int& num : nums1) {
            auto it = hash.find(num);
            // 把nums1换成对应元素
            num = it == hash.end() ? -1 : it->second;
        }
        return nums1;
    }
};