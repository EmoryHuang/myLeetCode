/*
 * @Descroption: ��ָ Offer 64. ��1+2+��+n
 * @Author: EmoryHuang
 * @Date: 2021-07-04 14:08:04
 * @����˼·:
 * �ݹ鲢�����յ�
 */

class Solution {
   public:
    int sumNums(int n) {
        // ��n��������ʱ����ߴ���Ϊ�棬&& �ұߴ����ִ�У������ݹ�
        n && (n += sumNums(n - 1));
        return n;
    }
};