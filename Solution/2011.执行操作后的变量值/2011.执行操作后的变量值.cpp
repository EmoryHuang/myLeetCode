/*
 * @Descroption: LeetCode 2011. ִ�в�����ı���ֵ
 * @Author: EmoryHuang
 * @Date: 2021-10-15 19:54:47
 * @Method:
 * ���⣬ģ��
 */


class Solution {
   public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for (auto op : operations) {
            if (op[1] == '+')
                x++;
            else if (op[1] == '-')
                x--;
        }
        return x;
    }
};