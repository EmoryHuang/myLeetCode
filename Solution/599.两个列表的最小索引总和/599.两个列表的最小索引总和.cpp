/*
 * @Descroption: LeetCode 599. �����б����С�����ܺ�
 * @Author: EmoryHuang
 * @Date: 2022-03-14 08:52:53
 * @Method:
 * ���⣬ʹ�ù�ϣ���¼ list1 ÿ��Ԫ�ص�����
 * Ȼ���� list2 ��Ѱ�� list1 �е�Ԫ�أ���ά����С������
 */

class Solution {
   public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, vector<int>> hash;
        for (int i = 0; i < list1.size(); i++) hash[list1[i]].push_back(i);
        vector<string> ans;
        int min_idx = INT_MAX;
        for (int i = 0; i < list2.size(); i++) {
            string name = list2[i];
            if (hash.count(name)) {
                int idx = hash[name][0] + i;
                if (idx < min_idx) {
                    min_idx = idx;
                    ans.clear();
                    ans.push_back(name);
                } else if (idx == min_idx)
                    ans.push_back(name);
            }
        }
        return ans;
    }
};