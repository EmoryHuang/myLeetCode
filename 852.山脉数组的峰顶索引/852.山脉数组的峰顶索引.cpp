/*
 * @Descroption: LeetCode 852. ɽ������ķ嶥����
 * @Author: EmoryHuang
 * @Date: 2021-06-15 16:16:00
 * @����˼·:
 * ���⣬ö�ٵķ����Ͳ�д�ˣ�д��һ�¶���
 * �� arr[mid] >= arr[mid + 1] ��˵�� mid ���Ұ벿��
 * ���ն��ֲ���ģ�弴��
 */

class Solution {
   public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 0, r = arr.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] >= arr[mid + 1])
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};