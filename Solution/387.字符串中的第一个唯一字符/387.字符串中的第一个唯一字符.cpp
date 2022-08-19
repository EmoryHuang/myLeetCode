/*
 * @Descroption: LeetCode 387. �ַ����еĵ�һ��Ψһ�ַ�
 * @Author: EmoryHuang
 * @Date: 2021-05-20 20:04:37
 * @����˼·:
 * ʹ�ù�ϣ���¼s���ַ����ֵĴ���,��֮����ҳ��ִ���Ϊ1��Ԫ��
 */

class Solution {
   public:
    int firstUniqChar(string s) {
        map<char, int> mp;
        for (auto c : s) mp[c]++;
        for (int i = 0; i < s.size(); i++)
            if (mp[s[i]] == 1) return i;
        return -1;
    }
};