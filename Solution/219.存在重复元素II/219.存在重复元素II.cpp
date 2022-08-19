/*
 * @Descroption: LeetCode 219. �����ظ�Ԫ�� II
 * @Author: EmoryHuang
 * @Date: 2021-04-17 15:28:36
 * @����˼·:
 * �� [217. �����ظ�Ԫ��]����
 * �����Ѵ��ڵ�Ԫ�أ���`[0,i)`���ٴ�Ѱ�ң��ж��±�
 */

class Solution {
   public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int len = nums.size();
        unordered_set<int> st;
        for (int i = 0; i < len; i++) {
            if (st.find(nums[i]) == st.end())  // �����в�����
                st.insert(nums[i]);
            else {
                for (int j = 0; j < i; j++) {  // ��[0,i)��Ѱ��
                    if (nums[i] == nums[j] && i - j <= k) return true;
                }
            }
        }
        return false;
    }
};