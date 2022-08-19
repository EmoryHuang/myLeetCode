/*
 * @Descroption: LeetCode 443. ѹ���ַ���
 * @Author: EmoryHuang
 * @Date: 2021-08-21 17:47:22
 * @Method:
 * ˫ָ��
 * Ѱ����ͬ���ַ����ƶ���ָ�룬��¼�ַ������������Դ˸����ַ���
 * ʹ�� tail ����ʶ�´�
 */

class Solution {
   public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int l = 0, r = 0, tail = 0;
        while (r < n) {
            while (r < n && chars[r] == chars[l]) r++;
            int cnt = r - l;
            chars[tail++] = chars[l];
            if (cnt > 1) {
                string cnt_str = to_string(cnt);
                for (auto c : cnt_str) chars[tail++] = c;
            }
            l = r;
        }
        return tail;
    }
};