/*
 * @Descroption: LeetCode 14. �����ǰ׺
 * @Author: EmoryHuang
 * @Date: 2021-03-20 14:16:36
 * @����˼·: ����һ��ȡ��һ���ַ������ͺ���ıȽϣ���ÿ��������ͬ���ǰ׺�Ƕ��٣����������ַ���
 *          ���������Ե�һ��Ԫ��Ϊ��׼��������Ԫ������룬Ȼ������Ƚ�
 */

class Solution {
   public:
    // ����һ��find()
    string longestCommonPrefix(vector<string>& strs) {
        int len = strs.size();
        if (len == 0) return "";
        string ans;
        ans = strs[0];  //ȡ��һ���ַ����ͺ���ıȽ�
        for (int i = 1; i < len; i++) {
            while (strs[i].find(ans) != 0) {
                ans = ans.substr(0, ans.size() - 1);  //ȡ ans ��ÿ��������ͬ���ǰ׺
            }
        }
        return ans;
    }

    //������������Ƚ�
    // string longestCommonPrefix(vector<string>& strs) {
    //     int len = strs.size();
    //     if (len == 0) return "";
    //     if (len == 1) return strs[0];
    //     string ans = strs[0];
    //     for (int i = 0; i < ans.size(); i++) {                    //������һ���ַ���
    //         for (int j = 1; j < len; j++) {                       //����ʣ���ַ���
    //             if (i == strs[j].size() || strs[j][i] != ans[i])  //������ĩβ���߲����
    //                 return ans.substr(0, i);
    //         }
    //     }
    //     return ans;
    // }
};