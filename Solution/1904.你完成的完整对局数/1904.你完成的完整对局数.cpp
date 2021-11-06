/*
 * @Descroption: LeetCode 1904. ����ɵ������Ծ���
 * @Author: EmoryHuang
 * @Date: 2021-11-06 15:46:47
 * @Method:
 * ���⣬��ʱ��ת��Ϊ����
 * ���ǽ���ʱ��ǰ���Խ��������һ���Ծֻ��ǿ�ʼʱ��ĵ�һ���Ծ�
 * Ȼ����������ɵ������Ծ���
 */

class Solution {
   public:
    int numberOfRounds(string startTime, string finishTime) {
        int start = stoi(startTime.substr(0, 2)) * 60 + stoi(startTime.substr(3, 2));
        int end = stoi(finishTime.substr(0, 2)) * 60 + stoi(finishTime.substr(3, 2));
        // �ڶ���
        if (start > end) end += 24 * 60;
        // ����ʱ��ǰ���Խ��������һ���Ծ�
        end = end / 15 * 15;
        return max(0, (end - start)) / 15;
    }
};