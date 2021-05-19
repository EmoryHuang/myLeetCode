/*
 * @Descroption: LeetCode 1710. 卡车上的最大单元数
 * @Author: EmoryHuang
 * @Date: 2021-05-19 19:50:31
 * @解题思路:
 * 贪心思想，从可以装载最大单元的箱子开始拿起
 */

class Solution {
   public:
    static bool cmp(vector<int> a, vector<int> b) { return a[1] > b[1]; }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), cmp);  // 按单元数排序
        int ans = 0;
        for (auto box : boxTypes) {
            if (box[0] <= truckSize) {
                truckSize -= box[0];
                ans += box[0] * box[1];
            } else {  // 不足truckSize部分
                ans += truckSize * box[1];
                break;
            }
        }
        return ans;
    }
};