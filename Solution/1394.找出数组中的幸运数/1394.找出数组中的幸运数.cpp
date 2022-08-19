/*
 * @Descroption: LeetCode 1394. �ҳ������е�������
 * @Author: EmoryHuang
 * @Date: 2021-08-20 19:46:22
 * @Method:
 * ��ϣ���¼ÿ���ַ����ֵĴ���
 * ������Ƶ�κ�������ֵ��С�����¼���ҵ����ֵ
 */

class Solution {
   public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> hash;
        for (int num : arr) hash[num]++;
        int ans = -1;
        unordered_map<int, int>::iterator it;
        for (auto v : hash)
            if (v.first == v.second) ans = max(ans, v.first);
        return ans;
    }
};