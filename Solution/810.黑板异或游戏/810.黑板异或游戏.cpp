/*
 * @Descroption: LeetCode 810. �ڰ������Ϸ
 * @Author: EmoryHuang
 * @Date: 2021-05-22 13:38:00
 * @����˼·:
 * �����ʼʱ�ڰ�������������������� 0���� Alice ��ʤ��
 * ������ĳ�����ż��ʱ������ Alice �����ҵ�һ�����֣�
 * �ڲ����������֮��ʣ���������������������� 0��
 * �� Alice ����������ֺ󣬺ڰ���ʣ�����������֣����� Bob �����ĸ����֣�
 * ���� Alice ��һ���Ǻڰ���ʣ��ż�������֣�
 * ��ʱ Alice Ҫô��ʤ��Ҫô�Կ����ҵ�һ�����֣��ڲ����������֮��ʣ���������������������� 0��
 * ������ĳ���������ʱͬ��Bob һ����ʤ
 */

class Solution {
   public:
    bool xorGame(vector<int>& nums) {
        int orx = 0;
        for (int num : nums) orx ^= num;
        if (orx == 0 || nums.size() % 2 == 0) return true;
        return false;
    }
};