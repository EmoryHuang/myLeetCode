/*
 * @Descroption: LeetCode 1299. ��ÿ��Ԫ���滻Ϊ�Ҳ����Ԫ��
 * @Author: EmoryHuang
 * @Date: 2021-07-23 20:09:09
 * @����˼·:
 * �Ӻ���ǰ�������飬ά�����ֵ
 */

class Solution {
   public:
    vector<int> replaceElements(vector<int>& arr) {
        int amax = -1;
        for (int i = arr.size() - 1; i >= 0; i--) {
            int tmp = arr[i];
            arr[i] = amax;
            amax = max(amax, tmp);
        }
        return arr;
    }
};