/*
 * @Descroption: LeetCode 1408. �����е��ַ���ƥ��
 * @Author: EmoryHuang
 * @Date: 2021-06-23 12:35:00
 * @����˼·:
 * ����������ÿ��Ԫ�أ�������Ԫ���в����Ƿ�Ϊ�Ӵ�
 */

class Solution {
   public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        for (auto word : words) {
            for (int i = 0; i < words.size(); i++) {
                if (word != words[i] && words[i].find(word) != string::npos) {
                    ans.push_back(word);
                    break;
                }
            }
        }
        return ans;
    }
};