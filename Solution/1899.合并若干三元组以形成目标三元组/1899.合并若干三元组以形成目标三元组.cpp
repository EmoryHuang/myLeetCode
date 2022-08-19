/*
 * @Descroption: LeetCode 1899. �ϲ�������Ԫ�����γ�Ŀ����Ԫ��
 * @Author: EmoryHuang
 * @Date: 2021-11-04 20:43:58
 * @Method:
 * ̰��
 * ��������ÿ������С�� target ����ȫ�����кϲ����Ƚ��Ƿ��� target ��ͬ
 */

class Solution {
   public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> cur(3);
        for (auto t : triplets) {
            if (t[0] <= target[0] && t[1] <= target[1] && t[2] <= target[2]) {
                cur[0] = max(cur[0], t[0]);
                cur[1] = max(cur[1], t[1]);
                cur[2] = max(cur[2], t[2]);
            }
        }
        return cur == target;
    }
};