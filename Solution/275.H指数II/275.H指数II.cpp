/*
 * @Descroption: LeetCode 275. H ָ�� II
 * @Author: EmoryHuang
 * @Date: 2021-04-05 18:38:36
 * @����˼·:
 * ����һ�� [274. H ָ��]��ͬ
 * �ȶ������������
 * ��`h = citations.length - i`����������`h`ƪ���ķֱ�����������`citation[i]`��
 * ֻҪ`citation[i] �� h`������������
 *
 * ������Ϊ����������
 * �ҵ����� `citations[i] >= n - i` �ĵ�һ�� `citations[i]`
 */

class Solution {
   public:
    // ����һ������
    // int hIndex(vector<int>& citations) {
    //     int len = citations.size();
    //     for (int i = 0; i < len; i++) {
    //         int h = len - i;
    //         if (h <= citations[i]) return h;
    //     }
    //     return 0;
    // }

    // ����������������
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        int left = 0, right = len - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (citations[mid] == len - mid)
                return len - mid;
            else if (citations[mid] > len - mid)
                right = mid - 1;
            else
                left = left + 1;
        }
        return len - left;
    }
};