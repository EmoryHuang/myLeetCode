/*
 * @Descroption: LeetCode 796. ��ת�ַ���
 * @Author: EmoryHuang
 * @Date: 2021-06-26 14:18:00
 * @����˼·:
 * ���⣬�� s + s ���ж��Ƿ�����Ӵ� goal
 */

class Solution {
   public:
    bool rotateString(string s, string goal) {
        return s.size() == goal.size() && (s + s).find(goal) != -1;
    }
};