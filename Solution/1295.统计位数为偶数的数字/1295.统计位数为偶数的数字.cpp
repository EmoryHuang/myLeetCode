/*
 * @Descroption: LeetCode 1295. ͳ��λ��Ϊż��������
 * @Author: EmoryHuang
 * @Date: 2021-07-19 18:56:42
 * @����˼·:
 * �������飬����ż�����ȵ�����
 */

class Solution {
   public:
    int findNumbers(vector<int>& nums) {
        int cnt = 0;
        for (auto num : nums)
            if (to_string(num).size() % 2 == 0) cnt++;
        return cnt;
    }
};