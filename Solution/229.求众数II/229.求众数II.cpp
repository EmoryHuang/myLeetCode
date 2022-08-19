/*
 * @Descroption: LeetCode 229. 求众数 II
 * @Author: EmoryHuang
 * @Date: 2021-10-22 09:19:40
 * @Method:
 * 方法一：哈希表
 * 使用哈希表记录元素数量
 *
 * 方法二：摩尔投票法
 * 与 169. 多数元素 类似
 * 出现次数超过 n / k 的数最多只有 k - 1 个
 *
 * 摩尔投票法: 每次从序列里选择两个不相同的数字删除掉（或称为“抵消”），
 * 最后剩下一个数字或几个相同的数字，就是出现次数「可能」大于总数一半的那个
 */

class Solution {
   public:
    // 方法一：哈希表
    // vector<int> majorityElement(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> ans;
    //     unordered_map<int, int> hash;
    //     for (int num : nums) hash[num]++;
    //     unordered_map<int, int>::iterator it = hash.begin();
    //     for (; it != hash.end(); it++)
    //         if (it->second > n / 3) ans.push_back(it->first);
    //     return ans;
    // }

    // 方法二：摩尔投票法
    vector<int> majorityElement(vector<int>& nums) {
        // 出现次数超过 n / k 的数最多只有 k - 1 个
        int a = 0, b = 0;
        int c1 = 0, c2 = 0;
        for (int num : nums) {
            if (c1 != 0 && num == a)
                c1++;
            else if (c2 != 0 && num == b)
                c2++;
            else if (c1 == 0)
                a = num, c1++;
            else if (c2 == 0)
                b = num, c2++;
            else
                c1--, c2--;
        }
        // 再进行一次遍历，检查
        c1 = c2 = 0;
        for (int num : nums) {
            if (num == a)
                c1++;
            else if (num == b)
                c2++;
        }
        vector<int> ans;
        if (c1 > nums.size() / 3) ans.push_back(a);
        if (c2 > nums.size() / 3) ans.push_back(b);
        return ans;
    }
};