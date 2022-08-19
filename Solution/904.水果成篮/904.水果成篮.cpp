/*
 * @Descroption: LeetCode 904. ˮ������
 * @Author: EmoryHuang
 * @Date: 2021-11-04 20:31:50
 * @Method:
 * ��������
 * ����Ŀ������ת��һ�£������������Ԫ�ص��������
 * ʹ�ù�ϣ���¼�����е�Ԫ��
 */

class Solution {
   public:
    int totalFruit(vector<int>& fruits) {
        int ans = 0, l = 0;
        unordered_map<int, int> cnt;
        for (int r = 0; r < fruits.size(); ++r) {
            cnt[fruits[r]]++;
            if (cnt.size() >= 3) {
                // ������������
                cnt[fruits[l]]--;
                // �����˵��ֵ��Ϊ 0 ��ɾ��
                if (cnt[fruits[l]] == 0) cnt.erase(fruits[l]);
                l++;
            }
            // ������󳤶�
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};