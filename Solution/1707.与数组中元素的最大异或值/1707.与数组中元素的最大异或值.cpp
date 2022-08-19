/*
 * @Descroption: LeetCode 1707. ��������Ԫ�ص�������ֵ
 * @Author: EmoryHuang
 * @Date: 2021-05-23 14:03:11
 * @����˼·:
 * ��[421. ��������������������ֵ]����
 * �������е�Ԫ�ؿ��ɳ���Ϊ 31 ���ַ������ַ�����ֻ���� 0 �� 1
 * ÿ��·������ÿ�����ִӸ�λ����λ�Ķ����Ʊ�ʾ
 * Ϊ�˾����ܶ��ȡ�� 1��������Ҫ��ÿһ��Ѱ���뵱ǰλ�෴���ӽڵ�
 *      ��� num �ĵ� k ��������λΪ 0����ôӦ������ʾ 1 ���ӽڵ���
 *      ��� num �ĵ� k ��������λΪ 1����ôӦ������ʾ 0 ���ӽڵ���
 * ���⣬���ڶ�ѯ����������ԭѯ�ʵ�˳�򣬶�������Ҫ����ԭѯ�ʵ�˳�򷵻ش𰸣�
 * ��˿���������ǰ����ÿ��ѯ�ʸ���һ������ queries �е��±�
 */

class Trie {
   public:
    const int HIGH = 30;
    Trie* next[2] = {nullptr};
    Trie() {}
    void insert(int num) {
        Trie* node = this;
        for (int i = HIGH - 1; i >= 0; i--) {  // �Ӹ�λ����λ
            int bit = (num >> i) & 1;          // num ��ÿ��������λ
            if (node->next[bit] == nullptr)    // �������������ڵ�
                node->next[bit] = new Trie();
            node = node->next[bit];
        }
    }
    int getMax(int num) {
        Trie* node = this;
        int ans = 0;
        for (int i = HIGH - 1; i >= 0; i--) {      // �Ӹ�λ����λ
            int bit = (num >> i) & 1;              // num ��ÿ��������λ
            if (node->next[bit ^ 1] != nullptr) {  // ����෴�Ľڵ�ǿ�
                node = node->next[bit ^ 1];        // ���½ڵ�λ��
                ans = ans * 2 + bit ^ 1;
            } else {                     // ����෴�Ľڵ�Ϊ��
                node = node->next[bit];  // ���½ڵ�λ��
                ans = ans * 2 + bit;
            }
        }
        ans ^= num;  // ��������������ֵ
        return ans;
    }
};

class Solution {
   public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());
        int n = queries.size();
        // ��ǰ�� queries ��ţ���Ȼ��������˳��
        for (int i = 0; i < n; i++) queries[i].push_back(i);
        sort(queries.begin(), queries.end(), [](auto& a, auto& b) { return a[1] < b[1]; });
        vector<int> ans(n);
        Trie* node = new Trie();
        int ind = 0;
        for (auto query : queries) {
            while (ind < nums.size() && nums[ind] <= query[1]) {
                node->insert(nums[ind]);
                ind++;
            }
            if (ind == 0)  // nums �е�����Ԫ�ض����� query[1]
                ans[query[2]] = -1;
            else
                ans[query[2]] = node->getMax(query[0]);
        }
        return ans;
    }
};