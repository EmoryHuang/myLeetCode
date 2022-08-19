/*
 * @Descroption: LeetCode 1218. �����������
 * @Author: EmoryHuang
 * @Date: 2021-08-10 13:47:58
 * @Method:
 * ��̬�滮 + ��ϣ��
 * ʹ�ù�ϣ������nums[i]��β�ĵȲ����е�����
 * �� num - difference ���ڹ�ϣ���У�����Ϊ 1
 * ������Ϊ hash[num - difference] + 1
 */

class Solution {
   public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> hash;
        for (int num : arr) {
            hash[num] = hash[num - difference] + 1;
        }
        int ans = 0;
        for (auto h : hash) ans = max(ans, h.second);
        return ans;
    }
};