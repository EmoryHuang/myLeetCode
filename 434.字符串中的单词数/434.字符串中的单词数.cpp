/*
 * @Descroption: LeetCode 434. �ַ����еĵ�����
 * @Author: EmoryHuang
 * @Date: 2021-03-26 15:46:36
 * @����˼·:
 * �����⣬��ĩβ���һ���ո񣬿��Խ��մ����ո��β���ַ���β����״����һ���ǣ����ٶ�����ж�
 */

class Solution {
   public:
    int countSegments(string s) {
        int ans = 0;
        s += " ";
        for (int i = 0; i < s.size() - 1; i++)
            if (s[i] != ' ' && s[i + 1] == ' ') ans++;
        return ans;
    }
};