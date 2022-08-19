/*
 * @Descroption: LeetCode 1700. �޷�����͵�ѧ������
 * @Author: EmoryHuang
 * @Date: 2021-05-19 20:14:31
 * @����˼·:
 * ��ϣ���¼ϲ����ÿ�������ε�ѧ����
 * ��˳��������������飬�Ѷ�Ӧ�������ηָ�ϲ����ѧ��
 * ��ǰ��������û��ѧ��ϲ������ô�͵õ�����
 */

class Solution {
   public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        vector<int> cnt(2);
        for (int student : students) cnt[student]++;  // ��ÿ�������ε�ѧ����
        for (int sandwich : sandwiches) {
            if (cnt[sandwich] > 0)  // ��ϲ���Ե�ǰ�����ε�ѧ��
                cnt[sandwich]--;
            else
                break;
        }
        return cnt[0] + cnt[1];
    }
};