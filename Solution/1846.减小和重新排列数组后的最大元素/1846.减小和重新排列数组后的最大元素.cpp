/*
 * @Descroption: LeetCode 1846. ��С�������������������Ԫ��
 * @Author: EmoryHuang
 * @Date: 2021-07-15 18:48:44
 * @����˼·:
 * �����������飬��һ��Ϊ 1
 * ��arr[i]��arr[i - 1]֮����� 1������arr[i] = arr[i - 1] + 1
 */

class Solution {
   public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        arr[0] = 1;
        for (int i = 1; i < arr.size(); i++)
            if (arr[i] - arr[i - 1] > 1) arr[i] = arr[i - 1] + 1;
        return arr[arr.size() - 1];
    }
};