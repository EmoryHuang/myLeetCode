/*
 * @Descroption: LeetCode 852. ɽ������ķ嶥����
 * @Author: EmoryHuang
 * @Date: 2021-04-25 14:06:36
 * @����˼·:
 * ���⣬�������飬�ҵ���һ��`arr[i] > arr[i + 1]`��Ԫ��
 */

class Solution {
   public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int i;
        for (i = 0; i < arr.size() - 1; i++)
            if (arr[i] - arr[i + 1] > 0) break;
        return i;
    }
};