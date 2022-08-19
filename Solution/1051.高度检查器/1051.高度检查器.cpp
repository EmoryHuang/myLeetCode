/*
 * @Descroption: LeetCode 1051. �߶ȼ����
 * @Author: EmoryHuang
 * @Date: 2021-07-17 14:35:29
 * @����˼·:
 * һ���ܼ򵥵�˼���ǽ�ԭ�����������Ȼ��������������ԭ������бȽ�
 * Ȼ������ж��ٸ�Ԫ��û��ָ����λ��
 *
 * ����Ͱ�����˼����Ա�������ʱ�临�Ӷ�ΪO(n)
 */

class Solution {
   public:
    int heightChecker(vector<int>& heights) {
        vector<int> arr(101);
        for (auto height : heights) arr[height]++;
        int ans = 0, j = 0;
        for (int i = 1; i < arr.size(); i++) {
            while (arr[i]-- > 0)
                if (heights[j++] != i) ans++;
        }
        return ans;
    }
};