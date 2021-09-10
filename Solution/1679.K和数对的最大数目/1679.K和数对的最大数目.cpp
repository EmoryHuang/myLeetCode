/*
 * @Descroption: LeetCode 1679. K �����Ե������Ŀ
 * @Author: EmoryHuang
 * @Date: 2021-07-20 20:55:06
 * @����˼·:
 * �����������ڵ�ÿһ����������¼λ�������ڵ�Ԫ�ص�����
 */

class Solution {
   public:
    int maxOperations(vector<int>& nums, int k) {
        int cnt = 0;
        map<int, int> hash;
        for (int num : nums) {
            if (hash[k - num] == 0)
                hash[num]++;
            else {
                cnt++;
                hash[k - num]--;
            }
        }
        return cnt;
    }
};