/*
 * @Descroption: LeetCode 1832. �жϾ����Ƿ�Ϊȫ��ĸ��
 * @Author: EmoryHuang
 * @Date: 2021-04-21 15:19:36
 * @����˼·:
 * �����������ڼ�����֮���ڱ���һ��������飬Ҳ����ʹ�� set ������
 */

class Solution {
   public:
    bool checkIfPangram(string sentence) {
        vector<int> count(26, 0);
        for (int i = 0; i < sentence.size(); i++) count[sentence[i] - 'a']++;
        for (int i = 0; i < 26; i++)
            if (count[i] == 0) return false;
        return true;
    }
};