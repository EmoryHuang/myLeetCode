/*
 * @Descroption: LeetCode 274. H ָ��
 * @Author: EmoryHuang
 * @Date: 2021-04-05 18:18:36
 * @����˼·:
 * �ȶ������������
 * ��`h = citations.length - i`����������`h`ƪ���ķֱ�����������`citation[i]`��
 * ֻҪ`citation[i] �� h`������������
 */

class Solution {
   public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int len = citations.size();
        for (int i = 0; i < len; i++) {
            int h = len - i;
            if (h <= citations[i]) return h;
        }
        return 0;
    }
};