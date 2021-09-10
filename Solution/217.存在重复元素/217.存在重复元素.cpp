/*
 * @Descroption: LeetCode 217. �����ظ�Ԫ��
 * @Author: EmoryHuang
 * @Date: 2021-03-21 15:22:36
 * @����˼·:
 * ����һ���������ٱ���
 *
 * ������������ unordered_set
 */

class Solution {
   public:
    // ����һ���������ٱ���
    bool containsDuplicate(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                return true;
            }
        }
        return false;
    }

    // ������������unordered_set
    // bool containsDuplicate(vector<int>& nums) {
    //     int len = nums.size();
    //     unordered_set<int> st;
    //     for (int i = 0; i < len; i++) {
    //         if (st.find(nums[i]) == st.end())
    //             st.insert(nums[i]);
    //         else
    //             return true;
    //     }
    //     return false;
    // }
};