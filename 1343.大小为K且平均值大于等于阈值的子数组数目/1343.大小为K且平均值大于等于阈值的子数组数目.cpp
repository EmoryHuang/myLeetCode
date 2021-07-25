/*
 * @Descroption: LeetCode 1343. ��СΪ K ��ƽ��ֵ���ڵ�����ֵ����������Ŀ
 * @Author: EmoryHuang
 * @Date: 2021-07-25 14:27:18
 * @����˼·:
 * ���⣬�̶����ȵĻ�������
 */

class Solution {
   public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int s = 0;
        for (int i = 0; i < k; i++) s += arr[i];
        int ans = s / k >= threshold ? 1 : 0;
        for (int i = k; i < arr.size(); i++) {
            s += arr[i];
            s -= arr[i - k];
            ans = s / k >= threshold ? ans + 1 : ans;
        }
        return ans;
    }
};