/*
 * @Descroption: LeetCode 344. ��ת�ַ���
 * @Author: EmoryHuang
 * @Date: 2021-05-06 20:13:36
 * @����˼·: ���⣬����˫ָ�룬��ǰ���󣬴Ӻ���ǰ�ƶ�
 */

class Solution {
   public:
    void reverseString(vector<char>& s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
};