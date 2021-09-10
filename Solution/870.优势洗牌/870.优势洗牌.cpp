/*
 * @Descroption: LeetCode 870. ����ϴ��
 * @Author: EmoryHuang
 * @Date: 2021-07-21 19:46:06
 * @����˼·:
 * ̰��˼�룬�������
 * ���ַ�Ѱ����˵㣬�� nums1 ���ҵ����� nums2[i] ����Сֵ
 * �������ڣ��򷵻� nums1 �е���Сֵ
 */

class Solution {
   public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        vector<int> ans;
        for (int i = 0; i < nums2.size(); i++) {
            int l = 0, r = nums1.size() - 1;
            while (l < r) {
                int mid = (l + r) >> 1;
                if (nums1[mid] > nums2[i])
                    r = mid;
                else
                    l = mid + 1;
            }
            if (nums1[l] > nums2[i]) {
                ans.push_back(nums1[l]);
                nums1.erase(nums1.begin() + l);
            } else {
                ans.push_back(nums1[0]);
                nums1.erase(nums1.begin());
            }
        }
        return ans;
    }
};