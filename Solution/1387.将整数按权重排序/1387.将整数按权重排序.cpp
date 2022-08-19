/*
 * @Descroption: LeetCode 1387. ��������Ȩ������
 * @Author: EmoryHuang
 * @Date: 2021-08-27 14:49:53
 * @Method:
 * ����Ȩ�أ�ԭʼ���ݽ�������
 */

class Solution {
   public:
    int to_one(int num) {
        int cnt = 0;
        while (num != 1) {
            if (num % 2 == 0)
                num /= 2;
            else
                num = 3 * num + 1;
            cnt++;
        }
        return cnt;
    }
    int getKth(int lo, int hi, int k) {
        vector<pair<int, int>> nums;
        for (int i = lo; i <= hi; i++) nums.push_back({to_one(i), i});
        sort(nums.begin(), nums.end(), [](pair<int, int> a, pair<int, int> b) {
            if (a.first != b.first) return a.first < b.first;
            return a.second < b.second;
        });
        return nums[k - 1].second;
    }
};