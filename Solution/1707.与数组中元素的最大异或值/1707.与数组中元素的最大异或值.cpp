/*
 * @Descroption: LeetCode 1707. 与数组中元素的最大异或值
 * @Author: EmoryHuang
 * @Date: 2021-05-23 14:03:11
 * @解题思路:
 * 与[421. 数组中两个数的最大异或值]类似
 * 将数组中的元素看成长度为 31 的字符串，字符串中只包含 0 和 1
 * 每条路径都是每个数字从高位到低位的二进制表示
 * 为了尽可能多地取到 1，我们需要在每一步寻找与当前位相反的子节点
 *      如果 num 的第 k 个二进制位为 0，那么应当往表示 1 的子节点走
 *      如果 num 的第 k 个二进制位为 1，那么应当往表示 0 的子节点走
 * 此外，由于对询问排序会打乱原询问的顺序，而我们需要按照原询问的顺序返回答案，
 * 因此可以在排序前，对每个询问附加一个其在 queries 中的下标
 */

class Trie {
   public:
    const int HIGH = 30;
    Trie* next[2] = {nullptr};
    Trie() {}
    void insert(int num) {
        Trie* node = this;
        for (int i = HIGH - 1; i >= 0; i--) {  // 从高位到低位
            int bit = (num >> i) & 1;          // num 的每个二进制位
            if (node->next[bit] == nullptr)    // 若不存在则建立节点
                node->next[bit] = new Trie();
            node = node->next[bit];
        }
    }
    int getMax(int num) {
        Trie* node = this;
        int ans = 0;
        for (int i = HIGH - 1; i >= 0; i--) {      // 从高位到低位
            int bit = (num >> i) & 1;              // num 的每个二进制位
            if (node->next[bit ^ 1] != nullptr) {  // 如果相反的节点非空
                node = node->next[bit ^ 1];        // 更新节点位置
                ans = ans * 2 + bit ^ 1;
            } else {                     // 如果相反的节点为空
                node = node->next[bit];  // 更新节点位置
                ans = ans * 2 + bit;
            }
        }
        ans ^= num;  // 两个数的最大异或值
        return ans;
    }
};

class Solution {
   public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());
        int n = queries.size();
        // 提前给 queries 编号，不然排序会打乱顺序
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
            if (ind == 0)  // nums 中的所有元素都大于 query[1]
                ans[query[2]] = -1;
            else
                ans[query[2]] = node->getMax(query[0]);
        }
        return ans;
    }
};