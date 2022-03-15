/*
 * @Descroption: LeetCode 393. UTF-8 ������֤
 * @Author: EmoryHuang
 * @Date: 2022-03-13 13:17:18
 * @Method:
 * λ���㣬���� utf-8 �Ĺ�����м��
 * ʹ�� count ��¼�ֽ�������� count == 0����˵���ǵ�һ���ֽ�
 * ��� 0b110xxxxx, 0b1110xxxx, 0b11110xxx
 * ��������һ�ֽ��Ƿ��� 0b10xxxxxx
 */

class Solution {
   public:
    bool validUtf8(vector<int>& data) {
        int count = 0;
        for (auto num : data) {
            if (count == 0) {
                if ((num >> 5) == 0b110)
                    count = 1;
                else if ((num >> 4) == 0b1110)
                    count = 2;
                else if ((num >> 3) == 0b11110)
                    count = 3;
                else if (num >> 7)
                    return false;
            } else {
                if ((num >> 6) != 0b10) return false;
                count--;
            }
        }
        return count == 0;
    }
};