/*
 * @Descroption: LeetCode 925. ��������
 * @Author: EmoryHuang
 * @Date: 2021-04-27 15:30:36
 * @����˼·:
 * ����˫ָ�� `i`��`j`���ֱ�ָ�� `name` �� `typed` �Ƚ��ַ��Ƿ�ƥ�䣬�����ظ��� `j++`
 */

class Solution {
   public:
    bool isLongPressedName(string name, string typed) {
        int m = name.size();
        int n = typed.size();
        if (m > n) return false;
        int i = 0, j = 0;
        while (j < n) {
            if (i < m && name[i] == typed[j]) {  // �����i<m����while�����ܴ���type��Ҫʣ������
                i++;
                j++;
            } else if (j > 0 && typed[j - 1] == typed[j])  // �ظ����
                j++;
            else
                return false;
        }
        return i == m;  //ȫ��
    }
};