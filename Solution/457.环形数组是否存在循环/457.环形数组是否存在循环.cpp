/*
 * @Descroption: LeetCode 457. ���������Ƿ����ѭ��
 * @Author: EmoryHuang
 * @Date: 2021-08-07 14:22:09
 * @Method:
 * ģ��
 * ��ÿ���±� i ���г�����飬�����ĳ���±� i Ϊ�����㷢���ˡ�ѭ���������� True�����򷵻� False
 */

class Solution {
   public:
    int n;
    bool check(vector<int>& nums, int start) {
        int cur = start;
        int cnt = 1;  // ��¼������ɨ������±�����
        while (true) {
            if (cnt > n) return false;
            int next = ((cur + nums[cur]) % n + n) % n;
            // ��ȫ���������߸���
            if (nums[start] > 0 && nums[next] < 0) return false;
            if (nums[start] < 0 && nums[next] > 0) return false;
            if (start == next) return cnt > 1;  // �ҵ����������ͬ���±�
            cur = next;
            cnt++;
        }
    }
    bool circularArrayLoop(vector<int>& nums) {
        n = nums.size();
        for (int i = 0; i < n; i++)
            if (check(nums, i)) return true;
        return false;
    }
};