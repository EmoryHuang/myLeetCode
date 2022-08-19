/*
 * @Descroption: ������ 10.01. �ϲ����������
 * @Author: EmoryHuang
 * @Date: 2021-07-18 15:05:28
 * @����˼·:
 * һ���򵥵ķ������ǽ����� B �Ž����� A ��β����Ȼ��ֱ������
 * �ٽ�һ���Ļ�����ʹ��˫ָ�룬�������ұȽ�������Ԫ�صĴ�С����Ԫ�طŵ��µ�������
 * ��Ȼ������ A �������㹻�Ŀռ䣬��˿���ʹ������˫ָ��
 */

class Solution {
   public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int i = m - 1, j = n - 1;
        int tail = m + n - 1;
        while (i >= 0 || j >= 0) {
            if (i == -1)
                A[tail--] = B[j--];
            else if (j == -1)
                A[tail--] = A[i--];
            else if (A[i] > B[j])
                A[tail--] = A[i--];
            else
                A[tail--] = B[j--];
        }
    }
};