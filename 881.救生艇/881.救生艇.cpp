/*
 * @Descroption: LeetCode 881. ����ͧ
 * @Author: EmoryHuang
 * @Date: 2021-07-21 20:18:39
 * @����˼·:
 * ˫ָ�� + ̰��
 * �������ߺ����ұߵ������ϴ�����ô�������˾���
 * �������ߺ����ұߵ��˲����ϴ������ұߵ��˵�����
 */

class Solution {
   public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int cnt = 0, l = 0, r = people.size() - 1;
        while (l <= r) {
            if (people[l] + people[r] <= limit) {
                // �������ߺ����ұߵ������ϴ�
                l++;
                r--;
                cnt++;
            } else {
                // �������ߺ����ұߵ��˲����ϴ������ұߵ��˵�����
                r--;
                cnt++;
            }
        }
        return cnt;
    }
};