/*
 * @Descroption: ��ָ Offer II 069. ɽ������Ķ���
 * @Author: EmoryHuang
 * @Date: 2021-08-06 18:29:30
 * @Method:
 * ���ַ�Ѱ����˵�
 */

class Solution {
   public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 0, r = arr.size() - 1;
        // ���ַ�Ѱ����˵�
        while (l < r) {
            int mid = l + r >> 1;
            if (arr[mid] >= arr[mid + 1])
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};