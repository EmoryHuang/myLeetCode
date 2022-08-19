/*
 * @Descroption: LeetCode 881. ����ͧ
 * @Author: EmoryHuang
 * @Date: 2021-08-26 15:56:33
 * @Method:
 * ˫ָ�� + ����
 * ���ȶ������������ά������ָ��l��r���ֱ�ָ��ͷβ
 * �� people[l] + people[r] <= limit ˵���ܹ���2�ˣ�ָ��ֱ����ң��������
 * ����people[r] ��Ҫ�������Ŵ�����ָ�������ƶ�
 */

class Solution {
   public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int ans = 0, l = 0, r = people.size() - 1;
        while (l <= r) {
            if (people[l] + people[r] <= limit) l++;
            r--;
            ans++;
        }
        return ans;
    }
};