/*
 * @Descroption: LeetCode 1299. 将每个元素替换为右侧最大元素
 * @Author: EmoryHuang
 * @Date: 2021-07-23 20:09:09
 * @解题思路:
 * 从后往前遍历数组，维护最大值
 */

class Solution {
   public:
    vector<int> replaceElements(vector<int>& arr) {
        int amax = -1;
        for (int i = arr.size() - 1; i >= 0; i--) {
            int tmp = arr[i];
            arr[i] = amax;
            amax = max(amax, tmp);
        }
        return arr;
    }
};