/*
 * @Descroption: LeetCode 1200. ��С���Բ�
 * @Author: EmoryHuang
 * @Date: 2021-05-26 16:02:17
 * @����˼·:
 * �������������Ѱ�����ڵĲ�ֵ��С������Ԫ��
 * ����ֵС��diff�������diff�������ans
 * ����ֵ����diff�������ans
 */

class Solution {
   public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int diff = INT_MAX;
        vector<vector<int>> ans;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] - arr[i - 1] < diff) {  // �����ǰ�������Ĳ��С
                ans.clear();
                ans.push_back({arr[i - 1], arr[i]});
                diff = arr[i] - arr[i - 1];
            } else if (arr[i] - arr[i - 1] == diff)
                ans.push_back({arr[i - 1], arr[i]});
        }
        return ans;
    }
};