/*
 * @Descroption: LeetCode 1346. ������������������Ƿ����
 * @Author: EmoryHuang
 * @Date: 2021-07-25 14:40:25
 * @Method:
 * ���⣬ʹ�ù�ϣ��洢Ԫ��
 * ����0��Ҫ���⿼��
 */

class Solution {
   public:
    bool checkIfExist(vector<int>& arr) {
        map<int, int> hash;
        for (int num : arr) hash[num]++;
        for (int num : arr) {
            if (num && hash[num * 2] >= 1)
                return true;
            else if (!num && hash[num * 2] >= 2)
                return true;
        }
        return false;
    }
};