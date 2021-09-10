/*
 * @Descroption: LeetCode 942. �����ַ���ƥ��
 * @Author: EmoryHuang
 * @Date: 2021-06-04 14:07:00
 * @����˼·:
 * ά����ǰδʹ�õ���С������������������ɨ���ַ�����
 * ������� 'I'����ȡ����ǰ��С����������ȡ����ǰ������
 */

class Solution {
   public:
    vector<int> diStringMatch(string s) {
        int low = 0, high = s.size();
        vector<int> ans;
        for (auto c : s) {
            if (c == 'I')
                ans.push_back(low++);
            else if (c == 'D')
                ans.push_back(high--);
        }
        ans.push_back(low);
        return ans;
    }
};