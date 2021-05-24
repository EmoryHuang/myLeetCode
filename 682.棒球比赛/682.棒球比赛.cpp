/*
 * @Descroption: LeetCode 682. �������
 * @Author: EmoryHuang
 * @Date: 2021-05-24 20:44:11
 * @����˼·:
 * �����ַ�����ͬʱά��һ��ָ��score��ǰλ�õ�ָ�룬���ݸ���������м���
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