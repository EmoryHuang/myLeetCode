/*
 * @Descroption: ������ 17.11. ���ʾ���
 * @Author: EmoryHuang
 * @Date: 2022-05-27 08:52:55
 * @Method:
 * һ�α��� + ˫ָ��
 * ��¼���ʳ��ֵ�λ�ã�ȡ��̾���
 */


class Solution {
   public:
    int findClosest(vector<string>& words, string word1, string word2) {
        int ans = INT_MAX;
        int index1 = -1, index2 = -1;
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == word1)
                index1 = i;
            else if (words[i] == word2)
                index2 = i;
            if (index1 >= 0 && index2 >= 0) ans = min(ans, abs(index1 - index2));
        }
        return ans;
    }
};