/*
 * @Descroption: LeetCode 1346. 检查整数及其两倍数是否存在
 * @Author: EmoryHuang
 * @Date: 2021-07-25 14:40:25
 * @Method:
 * 简单题，使用哈希表存储元素
 * 数字0需要特殊考虑
 */

class Solution {
   public:
    bool checkIfExist(vector<int>& arr) {
        map<int, int> hash;
        for (int num : arr) hash[num]++;
        for (int num : arr) {
            if (num && hash[num * 2] >= 1)
                return true;
            else if (!num && hash[num * 2] >= 2)
                return true;
        }
        return false;
    }
};