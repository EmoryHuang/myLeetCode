/*
 * @Descroption: LeetCode 554. שǽ
 * @Author: EmoryHuang
 * @Date: 2021-05-02 17:08:36
 * @����˼·:
 * ����שǽ��ÿһ�У����ڵ�ǰ�У������ҵ�ɨ��ÿһ��ש��ʹ��һ����ϣ���¼��ǰש���Ҳ��Ե��שǽ��λ��
 * ��������ϣ���ҵ����ִ�������ש���Ե������Ǵ��߾�����ש���Ե����שǽ�ĸ߶ȼ�ȥ�����ֵ��Ϊ��
 */

class Solution {
   public:
    int leastBricks(vector<vector<int>>& wall) {
        map<int, int> mp;  // map�洢ÿ��ש�ұ�Եλ�õ�����
        int ans = 0;
        for (auto sub : wall) {
            int sum = 0;
            for (int i = 0; i < sub.size() - 1; i++) {
                sum += sub[i];
                mp[sum]++;
            }
        }
        for (auto a : mp) ans = max(ans, a.second);  //��������ұ�Ե
        return wall.size() - ans;
    }
};