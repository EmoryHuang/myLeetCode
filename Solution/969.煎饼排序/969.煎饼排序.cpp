/*
 * @Descroption: LeetCode 969. 煎饼排序
 * @Author: EmoryHuang
 * @Date: 2022-02-19 09:13:18
 * @Method:
 * 由于 arr 是 1 到 n 的排列，因此可以每次排序确定一个最大值
 * 从后往前枚举每个位置需要的元素
 * 找到当前需要的元素在 arr 中的位置 idx
 * 若需要的元素不在第一个位置，则先反转 [0, idx]，这样可以保证第一个位置是需要的元素
 * 若需要的元素在第一个位置，则直接反转 [0, i - 1]
 */

class Solution {
   public:
    vector<int> pancakeSort(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;
        // 从后往前枚举每个位置需要的元素
        for (int i = n; i > 0; i--) {
            // 找到当前需要的元素在 arr 中的位置 idx
            int idx = find(arr.begin(), arr.begin() + i, i) - arr.begin();
            // 若位置不需要改变
            if (idx == i - 1) continue;
            if (idx != 0) {
                // 若需要的元素不在第一个位置，则先反转 [0, idx]，这样可以保证第一个位置是需要的元素
                ans.push_back(idx + 1);
                reverse(arr.begin(), arr.begin() + idx + 1);
            }
            // 若需要的元素在第一个位置，则直接反转 [0, i - 1]
            ans.push_back(i);
            reverse(arr.begin(), arr.begin() + i);
        }
        return ans;
    }
};