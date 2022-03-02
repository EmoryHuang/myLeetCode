/*
 * @Descroption: LeetCode 1601. 最多可达成的换楼请求数目
 * @Author: EmoryHuang
 * @Date: 2022-02-28 09:22:08
 * @Method:
 * 二进制枚举
 * 使用二进制位记录选择换楼情况，遍历所有换楼请求
 * 统计二进制数中 1 的个数，并判断当前 state 是否可以满足换楼请求
 */

class Solution {
   public:
    vector<vector<int>> req;
    int count1(int state) {
        int res = 0;
        while (state) {
            res += state & 1;
            state >>= 1;
        }
        return res;
    }
    bool check(int state) {
        vector<int> cnt(20);
        for (int i = 0; i < req.size(); i++) {
            if ((state >> i) & 1) {
                cnt[req[i][0]]++;
                cnt[req[i][1]]--;
            }
        }
        bool flag = true;
        for (auto c : cnt)
            if (c != 0) {
                flag = false;
                break;
            }
        return flag;
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int ans = 0, m = requests.size();
        req = requests;
        // 遍历所有换楼请求
        for (int state = 0; state < (1 << m); state++) {
            // 统计二进制数中 1 的个数
            int cnt = count1(state);
            if (cnt <= ans) continue;
            // 判断当前数是否可以满足换楼请求
            if (check(state)) ans = max(ans, cnt);
        }
        return ans;
    }
};