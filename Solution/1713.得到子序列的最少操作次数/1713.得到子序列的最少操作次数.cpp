/*
 * @Descroption: LeetCode 1713. 得到子序列的最少操作次数
 * @Author: EmoryHuang
 * @Date: 2021-07-26 13:46:49
 * @Method:
 * 为了得到子序列的最少操作次数，我们想要的得到这两个序列的最长公共子序列
 * 得到了最长公共子序列之后，我们便可以确定最少需要添加的元素数量
 * 根据target中互不相同，我们知道每个数字对应的坐标唯一
 * 于是最长公共子序列等价于arr用target的坐标转换后构成最长的上升子序列
 */

class Solution {
   public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        int n = target.size();
        unordered_map<int, int> hash;
        // 记录target中元素的下标位置
        for (int i = 0; i < n; i++) hash[target[i]] = i;
        vector<int> com;
        for (int num : arr) {
            // 如果是公共元素
            if (hash.find(num) != hash.end()) {
                // 得到这个元素在target中的下标
                int ind = hash[num];
                auto pos = lower_bound(com.begin(), com.end(), ind);
                if (pos != com.end())
                    *pos = ind;
                else
                    com.push_back(ind);
            }
        }
        return n - com.size();
    }
};