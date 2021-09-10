/*
 * @Descroption: LeetCode 961. �ظ� N �ε�Ԫ��
 * @Author: EmoryHuang
 * @Date: 2021-06-28 14:40:00
 * @����˼·:
 * ���⣬��ϣ�����
 */

class Solution {
   public:
    int repeatedNTimes(vector<int>& nums) {
        set<int> st;
        for (auto num : nums) {
            if (!st.count(num))
                st.insert(num);
            else
                return num;
        }
        return 0;
    }
};