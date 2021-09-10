/*
 * @Descroption: LeetCode 68. �ı����Ҷ���
 * @Author: EmoryHuang
 * @Date: 2021-09-09 19:53:55
 * @Method:
 * ģ��
 * ά��ÿ�еĵ��ʣ�һֱ�� row ����ӵ��ʣ�ֱ���������Ϊֹ
 * �������һ�У�������룻����һ��ֻ��һ�����ʣ��������
 * ������������������ ��ǰ�пո񳤶�spaceWidth����ǰ�е��ʸ���cnt
 * ����ƽ����� avgSpace = spaceWidth // (cnt - 1)
 * ���ⵥ�ʼ�� extraSpace = spaceWidth % (cnt - 1)
 * ����ֻ��Ҫ��ǰ extraSpace ��������� avgSpace + 1 ���ո�
 */

class Solution {
   public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size(), i = 0;
        vector<string> ans;
        while (i < n) {
            vector<string> row;
            // �� row ����䵥��
            int cur = words[i].size();
            row.push_back(words[i++]);
            // һֱ�� row ����ӵ��ʣ�ֱ���������Ϊֹ
            // ע�ⵥ��֮���пո���Ҫ�� 1
            while (i < n && cur + 1 + words[i].size() <= maxWidth) {
                cur += 1 + words[i].size();
                row.push_back(words[i++]);
            }

            // �������һ�У��������
            if (i == n) {
                string s, tmp;
                for (int j = 0; j < row.size() - 1; j++) tmp += row[j] + ' ';
                tmp += row.back();
                s = tmp + string(maxWidth - tmp.size(), ' ');
                ans.push_back(s);
                break;
            }
            // ����һ��ֻ��һ�����ʣ��������
            int cnt = row.size();
            if (cnt == 1) {
                string s;
                s += row[0] + string(maxWidth - row[0].size(), ' ');
                ans.push_back(s);
                continue;
            }

            // �������
            int wordWidth = cur - (cnt - 1);          // ��ǰ�е��ʳ���
            int spaceWidth = maxWidth - wordWidth;    // ��ǰ�пո񳤶�
            int avgSpace = spaceWidth / (cnt - 1);    // ����ƽ�����
            int extraSpace = spaceWidth % (cnt - 1);  // ���ⵥ�ʼ��
            string s;
            for (int j = 0; j < row.size(); j++) {
                s += row[j];
                if (j == cnt - 1) break;
                // ����ƽ�����
                s += string(avgSpace, ' ');
                // ǰ extraSpace ��������� avgSpace + 1 ���ո�
                if (extraSpace-- > 0) s += ' ';
            }
            ans.push_back(s);
        }
        return ans;
    }
};