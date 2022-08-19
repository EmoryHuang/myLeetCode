/*
 * @Descroption: LeetCode 520. ����д��ĸ
 * @Author: EmoryHuang
 * @Date: 2021-04-26 16:12:36
 * @����˼·: ��Сд��ĸ����������ͳ�ƣ��������ж��Ƿ���Ϲ淶
 */

class Solution {
   public:
    bool detectCapitalUse(string word) {
        int cnt = 0;
        for (auto c : word)
            if (islower(c)) cnt++;
        // ȫСд/ȫ��д/����ĸ��д
        if (cnt == word.size() || cnt == 0 || (isupper(word[0]) && cnt == word.size() - 1))
            return true;
        return false;
    }
};