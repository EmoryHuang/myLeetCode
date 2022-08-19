/*
 * @Descroption: LeetCode 421. ��������������������ֵ
 * @Author: EmoryHuang
 * @Date: 2021-05-16 16:47:16
 * @����˼·:
 * �������е�Ԫ�ؿ��ɳ���Ϊ 31 ���ַ������ַ�����ֻ���� 0 �� 1
 * ÿ��·������ÿ�����ִӸ�λ����λ�Ķ����Ʊ�ʾ
 *
 * ��������������̰�ĵ�˼�룺
 * ���� x = ai ^ aj��ͨ��ö�� ai����a0,a1,...,ai-1��Ϊaj�����ֵ���
 * - ��� ai�ĵ� k ��������λΪ 0����ôӦ������ʾ 1 ���ӽڵ��ߣ���Ϊ 0^1=1����������ڣ���ô�� 0 ��
 * - ��� ai�ĵ� k ��������λΪ 1����ôӦ������ʾ 0 ���ӽڵ��ߣ���Ϊ 1^0=1����������ڣ���ô�� 1 ��
 */

struct Trie {
    Trie* left = nullptr;   // ������ָ���ʾ 0 ���ӽڵ�
    Trie* right = nullptr;  // ������ָ���ʾ 1 ���ӽڵ�
    Trie() {}
};

class Solution {
   private:
    Trie* root = new Trie();             // �ֵ����ĸ��ڵ�
    static constexpr int HIGH_BIT = 30;  // ���λ�Ķ�����λ���Ϊ 30

   public:
    void add(int num) {  // ��ǰ׺�����������
        Trie* cur = root;
        for (int k = HIGH_BIT; k >= 0; k--) {  // �Ӹ�λ����λ
            int bit = (num >> k) & 1;          // num ��ÿ��������λ
            if (bit == 0) {                    // �����ǰλΪ 0
                if (!cur->left) cur->left = new Trie();
                cur = cur->left;  // ָ���ʾ 0 ���ӽڵ�
            } else {              // �����ǰλΪ 1
                if (!cur->right) cur->right = new Trie();
                cur = cur->right;  // ָ���ʾ 1 ���ӽڵ�
            }
        }
    }

    int check(int num) {
        Trie* cur = root;
        int x = 0;
        for (int k = HIGH_BIT; k >= 0; k--) {  // �Ӹ�λ����λ
            int bit = (num >> k) & 1;          // num ��ÿ��������λ
            if (bit == 0) {                    // �����ǰλΪ 0
                if (cur->right) {              // ������� 1 ���ӽڵ�
                    cur = cur->right;
                    x = x * 2 + 1;  // 0^1=1 ���Լ� 1
                } else {            // ��������� 1 ���ӽڵ�
                    cur = cur->left;
                    x = x * 2;  // 0^0=0 ���Լ� 0
                }
            } else {              // �����ǰλΪ 1
                if (cur->left) {  // ������� 0 ���ӽڵ�
                    cur = cur->left;
                    x = x * 2 + 1;  // 1^0=1 ���Լ� 1
                } else {            // ��������� 0 ���ӽڵ�
                    cur = cur->right;
                    x = x * 2;  // 1^1=0 ���Լ� 0
                }
            }
        }
        return x;
    }

    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            add(nums[i - 1]);  // �� nums[i-1] �����ֵ���
            // �� nums[i] ���� ai���ҳ����� ans ���´�
            ans = max(ans, check(nums[i]));
        }
        return ans;
    }
};
