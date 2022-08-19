/*
 * @Descroption: LeetCode 744. Ѱ�ұ�Ŀ����ĸ�����С��ĸ
 * @Author: EmoryHuang
 * @Date: 2021-05-30 10:50:00
 * @����˼·:
 * �������飬���ص�һ������ target ��Ԫ��
 * �� target ���� letters �е�����Ԫ�أ��򷵻ص�һ��Ԫ��
 *
 * ������������Ѱ��
 */

class Solution {
   public:
    // ����һ��ֱ�ӱ���
    // char nextGreatestLetter(vector<char>& letters, char target) {
    //     for (auto letter : letters) {
    //         if (letter > target) return letter;
    //     }
    //     return letters[0];  // ��target����letters�е�����Ԫ�أ��򷵻ص�һ��Ԫ��
    // }

    // ������������
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (letters[mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        // ��target����letters�е�����Ԫ�أ��򷵻ص�һ��Ԫ��
        return letters[l % n];
    }
};