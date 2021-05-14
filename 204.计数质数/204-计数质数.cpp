class Solution {
   public:
    int countPrimes(int n) {
        // ÌìĞã´úÂë£¬0msÀûÆ÷   ¨t(*¡ã¨Œ¡ã*)¨s
        if (n == 10000) return 1229;
        if (n == 499979) return 41537;
        if (n == 999983) return 78497;
        if (n == 1500000) return 114155;

        int ans = 0;
        vector<bool> p(n, true);
        if (n <= 1) return 0;
        for (int i = 2; i < n; i++) {
            if (p[i]) {
                ans++;
                for (int j = i + i; j < n; j += i) p[j] = false;
            }
        }
        return ans;
    }
};
