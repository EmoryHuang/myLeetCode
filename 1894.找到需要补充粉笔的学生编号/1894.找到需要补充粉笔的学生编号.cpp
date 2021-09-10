/*
 * @Descroption: LeetCode 1894. �ҵ���Ҫ����۱ʵ�ѧ�����
 * @Author: EmoryHuang
 * @Date: 2021-09-10 14:54:25
 * @Method:
 * ��ѧ
 * ��ͣ�ȡ�࣬�ҵ�n�ֺ�ʣ�µ�������Ȼ���ٱ���һ�Σ��ҵ���Ҫ�����λ��
 */

class Solution {
   public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = 0;
        for (int num : chalk) sum += num;
        int cnt = k % sum;
        for (int i = 0; i < chalk.size(); i++) {
            if (cnt < chalk[i]) return i;
            cnt -= chalk[i];
        }
        return -1;
    }
};
