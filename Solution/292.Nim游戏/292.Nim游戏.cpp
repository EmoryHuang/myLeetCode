/*
 * @Descroption: LeetCode 292. Nim ��Ϸ
 * @Author: EmoryHuang
 * @Date: 2021-05-20 17:45:37
 * @����˼·:
 * ���С��3��Ļ�������Ϊ���־Ϳ���ȫ���ߣ�������Ϸ��
 * ���ǡ�����Ŀ�ʯͷ����ͻ�ʧ�ܡ�
 * �����������4�����Ļ����Ϳ��Կ��ƽ�4���������֣���ô�Լ��ض���Ӯ
 */

class Solution {
   public:
    bool canWinNim(int n) { return n % 4 != 0; }
};