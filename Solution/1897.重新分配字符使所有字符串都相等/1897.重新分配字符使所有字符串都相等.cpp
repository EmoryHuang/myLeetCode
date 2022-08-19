/*
 * @Descroption: LeetCode 1897. ���·����ַ�ʹ�����ַ��������
 * @Author: EmoryHuang
 * @Date: 2021-07-20 20:05:18
 * @����˼·:
 * ʹ�ù�ϣ���¼ÿ���ַ�������
 * ���ַ��ĸ����������鳤�ȵ���������������
 */
 
class Solution {
   public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        vector<int> mp(26);
        for (auto word : words)
            for (auto ch : word) mp[ch - 'a']++;
        for (auto num : mp)
            if (num % n != 0) return false;
        return true;
    }
};