/*
 * @Descroption: LeetCode 1720. �������������
 * @Author: EmoryHuang
 * @Date: 2021-05-06 18:24:36
 * @����˼·:
 * �����������������ʣ�
 * - ����������㽻���ɺͽ���ɣ�
 * - �����������������������Ľ�������� 0���� `x^x=0`��
 * - ���������� 0 ���������Ľ���������������� `x^0 = 0^x = x`��
 * a^b = c �� a^b^b = a�� �� c^b=a ͬ�� c^a =b
 * �����
 * `encode[i] = decode[i] ^ decode[i+1]`
 * `decode[i+1] = decode[i] ^ encode[i]`
 */

class Solution {
   public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ans;
        ans.push_back(first);
        for (int i = 0; i < encoded.size(); i++) {
            ans.push_back(ans.back() ^ encoded[i]);
        }
        return ans;
    }
};