/*
 * @Descroption: LeetCode 1089. 复写零
 * @Author: EmoryHuang
 * @Date: 2022-06-17 20:41:58
 * @Method:
 * 简单题，遍历数组，如果是 0，则插入 1 并 pop
 */

class Solution {
   public:
    void duplicateZeros(vector<int>& arr) {
        int i = 0, n = arr.size();
        while (i < n) {
            if (arr[i] == 0) {
                arr.insert(arr.begin() + i, 0);
                arr.erase(arr.end() - 1);
                i++;
            }
            i++;
        }
    }
};