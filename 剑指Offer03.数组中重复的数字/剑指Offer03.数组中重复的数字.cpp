/*
 * @Descroption: ��ָ Offer 03. �������ظ�������
 * @Author: EmoryHuang
 * @Date: 2021-06-28 16:23:00
 * @����˼·:
 * ���⣬��ϣ�����
 */

class Solution {
   public:
    int findRepeatNumber(vector<int>& nums) {
        set<int> hash;
        for (auto num : nums)
            if (hash.count(num) != 0)
                return num;
            else
                hash.insert(num);
        return 0;
    }
};