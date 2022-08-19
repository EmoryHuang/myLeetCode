/*
 * @Descroption: LeetCode 421. 数组中两个数的最大异或值
 * @Author: EmoryHuang
 * @Date: 2021-05-16 16:47:16
 * @解题思路:
 * 将数组中的元素看成长度为 31 的字符串，字符串中只包含 0 和 1
 * 每条路径都是每个数字从高位到低位的二进制表示
 *
 * 具体来看，采用贪心的思想：
 * 根据 x = ai ^ aj，通过枚举 ai，将a0,a1,...,ai-1作为aj放入字典树
 * - 如果 ai的第 k 个二进制位为 0，那么应当往表示 1 的子节点走，因为 0^1=1，如果不存在，那么往 0 走
 * - 如果 ai的第 k 个二进制位为 1，那么应当往表示 0 的子节点走，因为 1^0=1，如果不存在，那么往 1 走
 */

struct Trie {
    Trie* left = nullptr;   // 左子树指向表示 0 的子节点
    Trie* right = nullptr;  // 右子树指向表示 1 的子节点
    Trie() {}
};

class Solution {
   private:
    Trie* root = new Trie();             // 字典树的根节点
    static constexpr int HIGH_BIT = 30;  // 最高位的二进制位编号为 30

   public:
    void add(int num) {  // 向前缀树中添加数字
        Trie* cur = root;
        for (int k = HIGH_BIT; k >= 0; k--) {  // 从高位到低位
            int bit = (num >> k) & 1;          // num 的每个二进制位
            if (bit == 0) {                    // 如果当前位为 0
                if (!cur->left) cur->left = new Trie();
                cur = cur->left;  // 指向表示 0 的子节点
            } else {              // 如果当前位为 1
                if (!cur->right) cur->right = new Trie();
                cur = cur->right;  // 指向表示 1 的子节点
            }
        }
    }

    int check(int num) {
        Trie* cur = root;
        int x = 0;
        for (int k = HIGH_BIT; k >= 0; k--) {  // 从高位到低位
            int bit = (num >> k) & 1;          // num 的每个二进制位
            if (bit == 0) {                    // 如果当前位为 0
                if (cur->right) {              // 如果存在 1 的子节点
                    cur = cur->right;
                    x = x * 2 + 1;  // 0^1=1 所以加 1
                } else {            // 如果不存在 1 的子节点
                    cur = cur->left;
                    x = x * 2;  // 0^0=0 所以加 0
                }
            } else {              // 如果当前位为 1
                if (cur->left) {  // 如果存在 0 的子节点
                    cur = cur->left;
                    x = x * 2 + 1;  // 1^0=1 所以加 1
                } else {            // 如果不存在 0 的子节点
                    cur = cur->right;
                    x = x * 2;  // 1^1=0 所以加 0
                }
            }
        }
        return x;
    }

    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            add(nums[i - 1]);  // 将 nums[i-1] 放入字典树
            // 将 nums[i] 看作 ai，找出最大的 ans 更新答案
            ans = max(ans, check(nums[i]));
        }
        return ans;
    }
};
