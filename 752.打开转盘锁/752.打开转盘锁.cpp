/*
 * @Descroption: LeetCode 752. ��ת����
 * @Author: EmoryHuang
 * @Date: 2021-06-25 14:51:00
 * @����˼·:
 * �������������С��ֱ������������������
 * ������������ϣ�����ڡ������ͬ�ڵ��ظ��������͡���¼ת��������
 * ÿ�δӶ�����ȡֵ������չʱ�����ж��ĸ�������������
 * ��������������С��������Է��������Ľڵ㡹��˵���ҵ������·��
 */

class Solution {
   public:
    int openLock(vector<string>& deadends, string target) {
        if (target == "0000") return 0;  // ����Ҫת��
        unordered_set<string> dead;
        for (auto deadend : deadends) {
            if (deadend == "0000") return -1;  // deadends �г����� 0000
            dead.insert(deadend);              // �� deadends �е�Ԫ��ѹ�� set
        }
        // ���򣺴���� s ��ʼ���������򣺴ӽ�β t ��ʼ����
        // q1 �� q2 �ֱ���������ͷ�������
        queue<string> q1, q2;
        q1.push("0000");
        q2.push(target);
        // m1 �� m2 �ֱ��¼����ͷ�����ֵ�״̬�Ǿ������ٴ�ת������
        unordered_map<string, int> m1, m2;
        m1["0000"] = 0;  // ����ת���� "0000" ��Ҫ��ת 0 ��
        m2[target] = 0;  // ����ת���� target ��Ҫ��ת 0 ��

        // ֻ���������ж����գ����б�Ҫ������������
        // �������һ�����п��ˣ�˵����ĳ�������ѵ��׶��Ѳ����÷����Ŀ��ڵ�
        while (!q1.empty() && !q2.empty()) {
            int ans = -1;
            if (q1.size() <= q2.size())  // �����������ȶ̵�
                ans = update(q1, m1, m2, dead);
            else
                ans = update(q2, m2, m1, dead);
            if (ans != -1) return ans;
        }
        return -1;
    }

    int update(queue<string>& q, unordered_map<string, int>& same,
               unordered_map<string, int>& other, unordered_set<string>& dead) {
        string cur = q.front();  // ��ǰ��������ַ���
        int step = same[cur];    // ת�� cur ��Ҫ�Ĵ���
        q.pop();
        for (int i = 0; i < 4; i++) {
            // ģ������ͷ�����ת +1��-1
            for (int j = -1; j <= 1; j++) {
                if (j == 0) continue;
                string t = cur;
                if (t[i] == '9' && j == 1)
                    t[i] -= 10;
                else if (t[i] == '0' && j == -1)
                    t[i] += 10;
                t[i] += j;
                if (same.count(t) || dead.count(t)) continue;  // ������ֹ�������dead�����
                if (other.count(t))  // ����ڡ���һ�����ҵ�����˵���ҵ������·������������
                    return 1 + step + other[t];
                else {
                    q.push(t);
                    same[t] = step + 1;
                }
            }
        }
        return -1;
    }
};