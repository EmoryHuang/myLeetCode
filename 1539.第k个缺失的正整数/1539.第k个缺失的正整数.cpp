/*
 * @Descroption: LeetCode 1539. �� k ��ȱʧ��������
 * @Author: EmoryHuang
 * @Date: 2021-04-22 14:56:36
 * @����˼·:
 * ȱʧ��������һ�� >= k
 * ������ÿ����һ�� <= k �����֣���ζ������һ��ȱʧ�����֣���ʱ k+1
 */

class Solution {
   public:
    int findKthPositive(vector<int>& arr, int k) {
        for (int i = 0; i < arr.size(); i++)
            if (k >= arr[i]) k++;
        return k;
    }
};