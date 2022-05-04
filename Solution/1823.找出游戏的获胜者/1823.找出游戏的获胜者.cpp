/*
 * @Descroption: LeetCode 1823. �ҳ���Ϸ�Ļ�ʤ��
 * @Author: EmoryHuang
 * @Date: 2022-05-04 11:17:24
 * @Method:
 * ����һ: ����ģ��
 * �ڶ����з��� 1 �� n �����
 * ÿһ����Ϸ�У�������Ԫ��ȡ��������Ԫ���ڶ�β�����¼�����У��ظ��ò��� k - 1 ��
 * �� k �μ�Ϊʧ���ߣ�ֱ�������ֻʣ��һ����ң�����ʤ��
 *
 * ������: ��ѧ + ģ��
 * ÿ����ͬһ�����Թ̶����� k ��������
 * ������һ�β����ķ����Ϊ����λ�õ���һ����
 * ͬʱ�����ģ��� n ��Ϊ n - 1
 * ����� f(n, k) = (f(n - 1, k) + k) % n
 */

class Solution {
   public:
    // ����һ: ����ģ��
    // int findTheWinner(int n, int k) {
    //     deque<int> q;
    //     for (int i = 1; i <= n; i++) q.push_back(i);
    //     while (q.size() > 1) {
    //         for (int i = 0; i < k - 1; i++) {
    //             q.push_back(q.front());
    //             q.pop_front();
    //         }
    //         q.pop_front();
    //     }
    //     return q.front();
    // }

    // ������: ��ѧ + ģ��
    int findTheWinner(int n, int k) {
        int ans = 0;
        for (int i = 2; i <= n; i++) ans = (ans + k) % i;
        return ans + 1;
    }
};