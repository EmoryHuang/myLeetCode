class Solution {
   public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        int m = queries.size();
        vector<int> nums(n + 1), ans(m);
        // nums[i] Ϊ�� arr[0] �� arr[i-1] �������
        for (int i = 0; i < n; i++) {
            nums[i + 1] = nums[i] ^ arr[i];
        }
        for (int i = 0; i < m; i++) {  // �������
            ans[i] = nums[queries[i][0]] ^ nums[queries[i][1] + 1];
        }
        return ans;
    }
};