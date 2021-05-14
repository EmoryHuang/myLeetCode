/*
 * @Descroption: LeetCode 17. �绰�������ĸ���
 * @Author: EmoryHuang
 * @Date: 2021-03-22 14:53:36
 * @����˼·: DFS + ��ϣ��
 * ÿ��ȡ�绰�����һλ���֣��ӹ�ϣ���л�ø����ֶ�Ӧ�����п��ܵ���ĸ��
 * �������е�һ����ĸ���뵽���е���ĸ���к��棬Ȼ���������绰����ĺ�һλ���֣�
 * ֱ��������绰�����е��������֣����õ�һ����������ĸ����
 */

class Solution {
   public:
    string temp;
    vector<string> ans;
    vector<string> strs = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void DFS(int pos, string digits) {
        if (pos == digits.size()) {
            ans.push_back(temp);
            return;
        }
        int num = digits[pos] - '0';
        for (int i = 0; i < strs[num].size(); i++) {
            temp.push_back(strs[num][i]);
            DFS(pos + 1, digits);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (!digits.size()) return ans;
        DFS(0, digits);
        return ans;
    }
};