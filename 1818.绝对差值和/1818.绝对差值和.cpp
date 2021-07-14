/*
 * @Descroption: LeetCode 1818. ���Բ�ֵ��
 * @Author: EmoryHuang
 * @Date: 2021-07-14 20:18:58
 * @����˼·:
 * ���ַ�
 * ����ÿ�����У��ҵ���ǰ��Ӧ��ֵ�ľ���ֵ diff
 * ���ַ�Ѱ�� nums1 ����ӽ� nums2[i] �����֣��ҵ���õ��µĲ�ֵ
 * ����Ϊ�Ǿ���ֵ�����Լ����ֵҪ�������ߣ�
 * ��¼���Լ�С�����Ĳ�ֵ
 */

class Solution {
   public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> sorted = nums1;
        sort(sorted.begin(), sorted.end());
        long sum = 0;
        int max_diff = 0;
        // ����ÿ������
        for (int i = 0; i < n; i++) {
            int a = nums1[i], b = nums2[i];
            if (a == b) continue;
            int diff = abs(a - b);  // ��ǰ��Ӧ��ֵ�ľ���ֵ
            sum += diff;            // ���Բ�ֵ��
            // ���ַ�Ѱ�� nums1 ����ӽ� b ������
            int l = 0, r = n - 1;
            while (l < r) {
                int mid = (l + r + 1) / 2;
                if (sorted[mid] <= b)
                    l = mid;
                else
                    r = mid - 1;
            }
            // �õ��µĲ�ֵ
            int new_diff = abs(sorted[l] - b);
            // ��Ϊ�Ǿ���ֵ������Ҫ��������
            if (l + 1 < n) new_diff = min(new_diff, abs(sorted[l + 1] - b));
            // ��¼���Լ�С�����Ĳ�ֵ
            if (new_diff < diff) max_diff = max(max_diff, diff - new_diff);
        }
        return (sum - max_diff) % 1000000007;
    }
};