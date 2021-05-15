/*
 * @Descroption: LeetCode 915. �ָ�����
 * @Author: EmoryHuang
 * @Date: 2021-04-27 14:27:36
 * @����˼·:
 * ��Ϊ��Ŀ��֤�л��֣���ô������������ֵ��������ֵ��ȫ�����ֵ���ҵ���һ����������ֶ����ֵ
 */

class Solution {
   public:
    int partitionDisjoint(vector<int>& A) {
        if (A.size() == 0) return 0;
        int maxA = A[0], maxLeft = A[0];
        int pos = 0;
        for (int i = 0; i < A.size(); i++) {
            maxA = max(maxA, A[i]);
            if (maxLeft > A[i]) {  // �ҵ���һ����������ֶ����ֵ
                maxLeft = maxA;
                pos = i;
            }
        }
        return pos + 1;
    }
};