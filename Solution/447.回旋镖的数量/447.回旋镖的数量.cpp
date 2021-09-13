/*
 * @Descroption: LeetCode 447. �����ڵ�����
 * @Author: EmoryHuang
 * @Date: 2021-09-13 11:07:15
 * @Method:
 * ���� + ��ϣ��
 * ������ǰ�㵽������ľ��룬���ù�ϣ���¼������ִ���
 * ��ÿ��������ִ��� n ��ѡ������������Ϊ����������
 * �� A(n, 2) = n * (n - 1)
 */

class Solution {
   public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ans = 0;
        for (auto a : points) {
            unordered_map<int, int> hash;
            // ������ǰ�㵽������ľ���
            for (auto b : points) {
                int dis = (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
                hash[dis]++;
            }
            unordered_map<int, int>::iterator it;
            // ��ÿ��������ִ��� n ��ѡ��������
            // �� A(n, 2) = n * (n - 1)
            for (it = hash.begin(); it != hash.end(); it++) {
                ans += it->second * (it->second - 1);
            }
        }
        return ans;
    }
};