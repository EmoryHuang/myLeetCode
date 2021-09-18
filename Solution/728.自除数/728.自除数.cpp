/*
 * @Descroption: LeetCode 728. �Գ���
 * @Author: EmoryHuang
 * @Date: 2021-09-18 20:26:57
 * @Method:
 * ������Χ�ڵ�ÿ�������ж��ǲ����Գ���
 */

class Solution {
   public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for (int num = left; num <= right; num++) {
            int tmp = num;
            while (tmp) {
                if (tmp % 10 == 0 || num % (tmp % 10)) break;
                tmp /= 10;
            }
            if (tmp == 0) ans.push_back(num);
        }
        return ans;
    }
};