/*
 * @Descroption: ��ָ Offer 50. ��һ��ֻ����һ�ε��ַ�
 * @Author: EmoryHuang
 * @Date: 2021-07-29 19:31:35
 * @Method:
 * ���⣬ʹ�ù�ϣ�����
 */

class Solution {
   public:
    char firstUniqChar(string s) {
        unordered_map<int, int> hash;
        for (auto c : s) hash[c]++;
        for (auto c : s)
            if (hash[c] == 1) return c;
        return ' ';
    }
};