/*
 * @Descroption: LeetCode 838. �ƶ���ŵ
 * @Author: EmoryHuang
 * @Date: 2022-02-21 09:12:18
 * @Method:
 * ˫ָ��
 * �ҵ�һ��������δ��ʩ���������䣬ͨ���������ߵķ�����ȷ��������ĵ���
 * left �� right ��ʾ���������������Ƶ��ķ���
 * ������ͬ������һ�����򵹣�������ԣ����м䵹
 */

class Solution {
   public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size(), i = 0;
        // left �� right ��ʾ�Ƶ��ķ���
        char left = 'L';
        while (i < n) {
            int j = i;
            // �ҵ�һ��������δ��ʩ����������
            while (j < n && dominoes[j] == '.') j++;
            char right = j < n ? dominoes[j] : 'R';
            if (left == right)
                // ������ͬ����һ������
                while (i < j) dominoes[i++] = right;
            else if (left == 'R' && right == 'L') {
                // ������ԣ����м䵹
                int k = j - 1;
                while (i < k) {
                    dominoes[i++] = 'R';
                    dominoes[k--] = 'L';
                }
            }
            left = right;
            i = j + 1;
        }
        return dominoes;
    }
};