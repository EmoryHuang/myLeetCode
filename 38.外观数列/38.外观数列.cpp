class Solution {
   public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string ans, pre = countAndSay(n - 1);
        int c = 1;
        for (int i = 0; i < pre.size(); i++) {
            if (pre[i] != pre[i + 1]) {  // �ַ�������ֹ��
                ans += (c + '0');        // ����
                ans += pre[i];           // ����
                c = 0;
            }
            c++;
        }
        return ans;
    }
};