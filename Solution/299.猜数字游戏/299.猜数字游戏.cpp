/*
 * @Descroption: LeetCode 299. ��������Ϸ
 * @Author: EmoryHuang
 * @Date: 2021-07-30 13:47:49
 * @Method:
 * ʹ��һ����ϣ��洢�����Ƿ����
 * ��guess�е������ǹ�ţ���� hash ��һ
 * ��secret�е������ǹ�ţ���� hash ��һ
 *
 * �����ǰλ��Ϊ������˵��һ��������secret��δƥ����ַ�
 * �����ǰλ��Ϊ������˵��һ��������guess��δƥ����ַ�
 */

class Solution {
   public:
    string getHint(string secret, string guess) {
        int a = 0, b = 0;
        vector<int> hash(10);
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i])
                a++;
            else {
                // �����ǰλ��Ϊ������˵��һ��������guess��δƥ����ַ�
                if (hash[secret[i] - '0'] < 0) b++;
                // ��secret�е������ǹ�ţ���� hash ��һ
                hash[secret[i] - '0']++;
                // �����ǰλ��Ϊ������˵��һ��������secret��δƥ����ַ�
                if (hash[guess[i] - '0'] > 0) b++;
                // ��guess�е������ǹ�ţ���� hash ��һ
                hash[guess[i] - '0']--;
            }
        }
        return to_string(a) + "A" + to_string(b) + "B";
    }
};