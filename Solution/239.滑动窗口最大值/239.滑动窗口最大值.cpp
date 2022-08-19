/*
 * @Descroption: LeetCode 239. �����������ֵ
 * @Author: EmoryHuang
 * @Date: 2021-07-13 20:40:44
 * @����˼·:
 * ����һ�����ȶ���
 * ά��һ������ѣ�����������
 * �����ǰ���ֵ���ڻ��������ڣ��򵯳�
 * Ȼ�󽫶Ѷ�Ԫ�ؼ��� ans
 *
 * ����������������
 * ʹ��һ�����д洢���л�û�б��Ƴ����±�
 * ���µ�Ԫ�����β��Ԫ����Ƚ�, ��֤����Ϊ�ݼ�����
 * �����ǰ���ֵ���ڻ��������ڣ��򵯳�
 * Ȼ�󽫶���Ԫ�ؼ��� ans
 */

class Solution {
   public:
    // ����һ�����ȶ���
    // vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    //     priority_queue<pair<int, int>> q;
    //     vector<int> ans;
    //     for (int i = 0; i < k; i++) {
    //         q.emplace(nums[i], i);
    //     }
    //     ans.push_back(q.top().first);
    //     for (int i = k; i < nums.size(); i++) {
    //         q.emplace(nums[i], i);
    //         // �����ǰ���ֵ���ڻ��������ڣ��򵯳�
    //         while (q.top().second <= i - k) q.pop();
    //         ans.push_back(q.top().first);
    //     }
    //     return ans;
    // }

    // ����������������
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            // ��֤����Ϊ�ݼ�����
            while (!q.empty() && nums[i] >= nums[q.back()]) q.pop_back();
            q.push_back(i);
        }
        ans.push_back(nums[q.front()]);
        for (int i = k; i < nums.size(); i++) {
            // ��֤����Ϊ�ݼ�����
            while (!q.empty() && nums[i] >= nums[q.back()]) q.pop_back();
            q.push_back(i);
            // �����ǰ���ֵ���ڻ��������ڣ��򵯳�
            while (q.front() <= i - k) q.pop_front();
            ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};