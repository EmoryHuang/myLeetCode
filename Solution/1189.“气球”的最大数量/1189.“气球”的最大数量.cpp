/*
 * @Descroption: LeetCode 1189. ������ ���������
 * @Author: EmoryHuang
 * @Date: 2021-05-26 15:47:17
 * @����˼·:
 * ʹ�ù�ϣ�����balloon��ÿ���ַ����ֵĴ���
 */

class Solution {
   public:
    int maxNumberOfBalloons(string text) {
        map<char, int> mp;
        for (auto c : text) mp[c]++;
        return min({mp['a'], mp['b'], mp['l'] / 2, mp['n'], mp['o'] / 2});
    }
};