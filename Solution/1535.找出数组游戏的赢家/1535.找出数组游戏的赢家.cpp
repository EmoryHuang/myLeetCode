/*
 * @Descroption: LeetCode 1535. 找出数组游戏的赢家
 * @Author: EmoryHuang
 * @Date: 2021-10-21 19:58:20
 * @Method:
 * 模拟
 * 一轮结束之后，在首位的必定是数组的最大值
 */

class Solution {
   public:
    int getWinner(vector<int>& arr, int k) {
        int cur = arr[0], cnt = 0;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > cur) {
                cur = arr[i];
                cnt = 1;
            } else
                cnt++;
            if (cnt == k) return cur;
        }
        return cur;
    }
};