/*
 * @Descroption: LeetCode 859. �����ַ���
 * @Author: EmoryHuang
 * @Date: 2021-06-09 19:54:00
 * @����˼·:
 * �ַ������Ȳ����, ֱ�ӷ���false
 * �ַ�����ȵ�ʱ��, ֻҪ���ظ���Ԫ�ؾͷ���true
 * A, B�ַ����в���ȵ������ط�, ��Ҫ�鿴���ǽ������Ƿ���ȼ���
 */

class Solution {
   public:
    bool buddyStrings(string a, string b) {
        if (a.size() != b.size()) return false;
        if (a == b) {
            set<char> s;
            for (auto c : a) {
                if (s.count(c) != 0) return true;  // ���ظ�Ԫ��
                s.insert(c);
            }
            return false;
        }
        int first = -1, second = -1;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                if (first == -1)
                    first = i;
                else if (second == -1)
                    second = i;
                else
                    return false;
            }
        }
        return second != -1 && a[first] == b[second] && a[second] == b[first];
    }
};