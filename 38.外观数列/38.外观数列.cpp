class Solution {
   public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string ans, pre = countAndSay(n - 1);
        int c = 1;
        for (int i = 0; i < pre.size(); i++) {
            if (pre[i] != pre[i + 1]) {  // ×Ö·û´®ÓÐÖÕÖ¹·û
                ans += (c + '0');        // ¸öÊý
                ans += pre[i];           // Êý×Ö
                c = 0;
            }
            c++;
        }
        return ans;
    }
};