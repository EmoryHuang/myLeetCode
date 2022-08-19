/*
 * @Descroption: LeetCode 5. ������Ӵ�
 * @Author: EmoryHuang
 * @Date: 2021-03-17 17:20:36
 * @����˼·: �����Ǳ����㷨������ÿ���Ӵ����ж����Ƿ�Ϊ���Ĵ����� c++�ᳬʱ
 * ����ʹ�ö�̬�滮��`dp[i][j]` ��ʾ `s[i]` �� `s[j]` ����ʾ�Ĵ��Ƿ�Ϊ���Ĵ�������Ϊ 1������Ϊ 0
 * �� `s[i] == s[j]` ����ôֻҪ `s[i+1] `��` s[j-1]` �ǻ��Ĵ��� `s[i]` �� `s[j]`����ʾ�Ĵ���Ϊ���Ĵ�
 * �� `s[i] != s[j]` ����ô `s[i]` �� `s[j]` ����ʾ�Ĵ��Ͳ��ǻ��Ĵ�
 * dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1])
 * dp[i][j] = (s[i] == s[j]) ? 1 : 0
 * �߽磺`dp[i][i]=1`,`dp[i][i+1]=(s[i]==s[i+1])?1:0`
 */

class Solution {
   public:
    string longestPalindrome(string s) {
        int len = s.size();
        string ans;
        vector<vector<int>> dp(len, vector<int>(len));
        for (int l = 0; l < len; l++) {          //�����Ӵ�����
            for (int i = 0; i + l < len; i++) {  //�������λ��
                int j = i + l;                   //�Ҷ˵�λ��
                if (l == 0)
                    dp[i][j] = 1;  //�߽磬���ǻ��Ĵ�
                else if (l == 1)
                    dp[i][j] = (s[i] == s[j]) ? 1 : 0;  //�߽磬���ǻ��Ĵ�
                else
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                if (dp[i][j] && l + 1 > ans.size()) {
                    ans = s.substr(i, l + 1);  //�����Ӵ�
                }
            }
        }
        return ans;
    }
};