class Solution {
   public:
    vector<int> decode(vector<int>& encoded) {
        int n = encoded.size();
        int a = 0;  // a 为 perm 的首元素
        for (int i = 1; i <= n + 1; i++) a ^= i;
        for (int i = n - 1; i >= 0; i-=2) a ^= encoded[i];
        vector<int> ans(n + 1);
        ans[0] = a;
        for (int i = 0; i < n; i++) ans[i + 1] = ans[i] ^ encoded[i];
        return ans;
    }
};