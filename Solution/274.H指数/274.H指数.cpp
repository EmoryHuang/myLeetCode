/*
 * @Descroption: LeetCode 274. H ָ��
 * @Author: EmoryHuang
 * @Date: 2021-07-11 13:25:04
 * @����˼·:
 * �������֣����ַ�Ѱ���Ҷ˵�
 */

class Solution {
   public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int n = citations.size();
        int l = 0, r = n;
        while (l < r) {
            int mid = l + (r - l + 1) / 2;
            // ������ mid ���������������
            if (citations[n - mid] >= mid)
                l = mid;
            else
                r = mid - 1;
        }
        return l;
    }
};