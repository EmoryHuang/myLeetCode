/*
 * @Descroption: LeetCode 1503. �������ϵ�����ǰ�����һ��
 * @Author: EmoryHuang
 * @Date: 2021-04-22 15:20:36
 * @����˼·:
 * ��ĿҪ��������һֻ���ϴ�ľ���ϵ�������ʱ�̣����Բ�����Ҫ����ÿֻ���ϡ�
 * ���Ҹı��ƶ��������ƶ��ٶȲ��䣬
 * ��ˣ���ֻ����������ͬʱ�ı��ƶ�����֮������εȼ�����ֻ���϶����ı��ƶ�����
 * �����Ŀ�ͱ������������Ҫ���е��·��
 */

class Solution {
   public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int time = 0;
        for (int i = 0; i < left.size(); i++) time = max(time, left[i]);
        for (int i = 0; i < right.size(); i++) time = max(time, n - right[i]);
        return time;
    }
};