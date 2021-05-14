/*
 * @Descroption: LeetCode 137. ֻ����һ�ε����� II
 * @Author: EmoryHuang
 * @Date: 2021-04-30 20:04:36
 * @����˼·:
 * ʹ�ù�ϣӳ��ͳ��������ÿ��Ԫ�صĳ��ִ�������ͳ����ɺ󣬱�����ϣӳ�伴���ҳ�ֻ����һ�ε�Ԫ�ء�
 *
 * ������λ����ο�
 */

class Solution {
   public:
    // ����һ����ϣ��
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = 0;
        for (int num : nums) mp[num]++;
        for (auto [num, c] : mp)
            if (c == 1) {
                ans = num;
                break;
            }
        return ans;
    }

    // ��������λ����
    // int singleNumber(vector<int>& nums) {
    //     int a = 0, b = 0;
    //     for (int num : nums) {
    //         b = ~a & (b ^ num);
    //         a = ~b & (a ^ num);
    //     }
    //     return b;
    // }
};