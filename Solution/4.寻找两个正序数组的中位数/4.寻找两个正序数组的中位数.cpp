/*
 * @Descroption: LeetCode 4. Ѱ�����������������λ��
 * @Author: EmoryHuang
 * @Date: 2021-03-16 19:30:36
 * @����˼·: ������򵥵�˼·���Ǻϲ� 2 �����飬Ȼ�������������λ��
 *          �ڶ�������Ӧ�ö��ֵ�˼�룬Ѱ�ҵ� k (k>1) С��Ԫ�أ�����ȡ `nums1[k/2-1]` ��
 * `nums2[k/2-1]` ���бȽϡ� ����������������ĳ��ȷֱ�Ϊ `m` �� `n`��
 *          �����������ȵ����飬��λ�����������������еĵ� `(m+n)/2` ��Ԫ�أ�
 *          ����ż�����ȵ����飬��λ�����������������еĵ� `(m+n)/2` ��Ԫ�غ͵� `(m+n)/2+1`
 * ��Ԫ�ص�ƽ��ֵ
 */

class Solution {
   public:
    // ����һ���ϲ�����
    // double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    //     int len2 = nums2.size();
    //     for (int i = 0; i < len2; i++) nums1.push_back(nums2[i]);  //����������ϲ�
    //     sort(nums1.begin(), nums1.end());                          //����
    //     int len1 = nums1.size();
    //     double ans;
    //     if (len1 % 2 == 0)  //������Ϊż��
    //         ans = (nums1[len1 / 2] + nums1[len1 / 2 - 1]) / 2.0;
    //     else
    //         ans = nums1[len1 / 2];
    //     return ans;
    // }

    //������������ѡ��
    int getKthElement(const vector<int>& nums1, const vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        int ind1 = 0, ind2 = 0;

        while (true) {
            // �߽����
            if (ind1 == m) return nums2[ind2 + k - 1];         // nums1�е���ȫ���ų�
            if (ind2 == n) return nums1[ind1 + k - 1];         // nums2�е���ȫ���ų�
            if (k == 1) return min(nums1[ind1], nums2[ind2]);  // k=1����Сֵ

            // �������
            int newind1 = min(ind1 + k / 2 - 1, m - 1);
            int newind2 = min(ind2 + k / 2 - 1, n - 1);
            int p1 = nums1[newind1];
            int p2 = nums2[newind2];
            if (p1 <= p2) {               //�Ƚϵ� k/2-1 ��Ԫ�صĴ�С
                k -= newind1 - ind1 + 1;  //ɾ���ų���Ԫ��
                ind1 = newind1 + 1;       //�����±�
            } else {
                k -= newind2 - ind2 + 1;
                ind2 = newind2 + 1;
            }
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size() + nums2.size();  //�ܳ���
        if (len % 2 == 1) {
            return getKthElement(nums1, nums2, (len + 1) / 2);
        } else {
            return (getKthElement(nums1, nums2, len / 2) +
                    getKthElement(nums1, nums2, len / 2 + 1)) /
                   2.0;
        }
    }
};