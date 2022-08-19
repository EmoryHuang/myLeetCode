/*
 * @Descroption: LeetCode 496. ��һ������Ԫ�� I
 * @Author: EmoryHuang
 * @Date: 2021-08-12 19:13:52
 * @Method:
 * ����ջ + ��ϣ��
 * ά��һ������ջ��ͳ�� nums2 �е�ǰ�ַ��ұ߸��������
 * Ȼ����� nums1 ͬ���Ƕ�Ӧλ�õıȽ�
 */

class Solution {
   public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> hash;
        for (int num : nums2) {
            // ά��һ������ջ
            while (!st.empty() && st.top() < num) {
                hash[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }
        for (int& num : nums1) {
            auto it = hash.find(num);
            // ��nums1���ɶ�ӦԪ��
            num = it == hash.end() ? -1 : it->second;
        }
        return nums1;
    }
};