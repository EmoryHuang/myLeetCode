/*
 * @Descroption: LeetCode 1619. ɾ��ĳЩԪ�غ�������ֵ
 * @Author: EmoryHuang
 * @Date: 2021-09-22 21:06:09
 * @Method:
 * ���⣬ȥ��ǰ�� 5% ������ֵ
 */

 
class Solution {
   public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size(), sum = 0;
        int d = n / 20;
        for (int i = d; i < n - d; i++) sum += arr[i];
        return 1.0 * sum / (n - 2 * d);
    }
};