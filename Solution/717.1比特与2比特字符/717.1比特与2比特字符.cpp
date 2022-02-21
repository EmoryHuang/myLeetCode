/*
 * @Descroption: LeetCode 717. 1������2�����ַ�
 * @Author: EmoryHuang
 * @Date: 2022-02-20 10:30:18
 * @Method:
 * ���⣬��������ɨ�����һλ֮ǰ���ַ�������¼֮ǰ��ƥ��״̬
 */

class Solution {
   public:
    bool isOneBitCharacter(vector<int>& bits) {
        int idx = 0;
        int n = bits.size();
        while (idx < n - 1) {
            if (bits[idx] == 0)
                idx++;
            else
                idx += 2;
        }
        return idx == n - 1;
    }
};