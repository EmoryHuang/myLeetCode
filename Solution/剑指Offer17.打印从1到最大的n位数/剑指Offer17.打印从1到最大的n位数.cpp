/*
 * @Descroption: ��ָ Offer 17. ��ӡ�� 1 ������ n λ��
 * @Author: EmoryHuang
 * @Date: 2021-06-27 15:45:00
 * @����˼·:
 * �����Ǵ�������Ļ�ֱ������Ӿ���
 */

class Solution {
   public:
    vector<int> printNumbers(int n) {
        vector<int> ans;
        for (int i = 1; i < pow(10, n); i++) ans.push_back(i);
        return ans;
    }
};