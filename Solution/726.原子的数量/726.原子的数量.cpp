/*
 * @Descroption: LeetCode 726. ԭ�ӵ�����
 * @Author: EmoryHuang
 * @Date: 2021-07-05 21:33:40
 * @����˼·:
 * ��������ַ���
 * �������������¼����������ĸ���¼
 * ������ ) ������ߵ�������Ϊ�������������ܱ���
 * ������ ( �򽫶�Ӧ ) �ı�����ԭ
 * ��������д��ĸ����ת�ַ��������� str �� num ���� map
 */


class Solution {
   public:
    string countOfAtoms(string formula) {
        map<string, int> mp;
        stack<int> hash;
        // str ��¼�ַ���num ��¼���֣�muls��¼�ܵı���
        string str, num;
        int muls = 1;
        // �Ӻ���ǰ�����ַ���
        for (int i = formula.size() - 1; i >= 0; i--) {
            // ��������֣����¼
            if (isdigit(formula[i]))
                num = formula[i] + num;
            else if (formula[i] == ')') {
                // �� num Ϊ�գ���˵�������ұ�û�����֣�����Ϊ 1
                // ������Ϊ num
                int mul = num == "" ? 1 : stoi(num);
                num = "";     // ���¼�¼ num
                muls *= mul;  // �����ܵı���
                hash.push(mul);
            } else if (formula[i] == '(') {
                muls /= hash.top();  // �����ܵı���
                hash.pop();
            } else {
                str += formula[i];
                if (isupper(formula[i])) {
                    // ��������д��ĸ����ת�ַ����������� map
                    reverse(str.begin(), str.end());
                    mp[str] += (num == "" ? 1 : stoi(num)) * muls;
                    str = "", num = "";  // ���
                }
            }
        }
        string ans;
        for (auto i : mp) {
            ans += i.first;
            if (i.second > 1) ans += to_string(i.second);
        }
        return ans;
    }
};