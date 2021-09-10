/*
 * @Descroption: LeetCode 682. 棒球比赛
 * @Author: EmoryHuang
 * @Date: 2021-05-24 20:44:11
 * @解题思路:
 * 遍历字符串，同时维护一个指向score当前位置的指针，根据给定规则进行计算
 */

class Solution {
   public:
    int calPoints(vector<string>& ops) {
        int n = ops.size();
        vector<int> score(n);
        int i = 0;
        for (auto str : ops) {
            if (str == "+")
                score[i] = score[i - 1] + score[i - 2], i++;
            else if (str == "D")
                score[i] = 2 * score[i - 1], i++;
            else if (str == "C")
                score[i - 1] = 0, i--;
            else
                score[i] = stoi(str), i++;
        }
        int ans = 0;
        for (int num : score) ans += num;
        return ans;
    }
};