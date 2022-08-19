/*
 * @Descroption: LeetCode 1405. 最长快乐字符串
 * @Author: EmoryHuang
 * @Date: 2022-02-07 10:37:28
 * @Method:
 * 按照剩余数量降序排序
 * 贪心策略，每次尽可能优先使用当前数量最多的字母
 * 使用数量最多的字母: 结果字符串长度小于 2; 最后两个字符与其不相同; 数量最多的字母还有
 * 否则使用数量第二多的字母
 */


class Solution {
   public:
    string longestDiverseString(int a, int b, int c) {
        string ans;
        vector<pair<int, char>> cnt = {{a, 'a'}, {b, 'b'}, {c, 'c'}};
        while (true) {
            int n = ans.size();
            // 按照剩余数量降序排序
            sort(cnt.begin(), cnt.end(), [](const pair<int, char>& a, const pair<int, char>& b) { return a.first > b.first; });
            if (cnt[0].first && (n < 2 || !(ans[n - 1] == cnt[0].second && ans[n - 2] == cnt[0].second))) {
                //使用数量最多的字母
                // 数量最多的字母还有 and (结果字符串长度小于 2 or 最后两个字符与其不相同)
                ans += cnt[0].second;
                cnt[0].first--;
            } else if (cnt[1].first) {
                // 使用数量第二多的字母
                ans += cnt[1].second;
                cnt[1].first--;
            } else {
                break;
            }
        }
        return ans;
    }
};