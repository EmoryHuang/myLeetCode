/*
 * @Descroption: LeetCode 2013. 检测正方形
 * @Author: EmoryHuang
 * @Date: 2022-01-26 11:16:48
 * @Method:
 * 使用哈希表存储点 {x, {y: 点(x, y)出现次数}}
 * 传入的点为 (x, y)，先查询 x 行都有哪些列，即枚举点 (x, ny)
 * 由此可以得到正方形边长 d
 * 而后再寻找 (x ± d, y) 和 (x ± d, ny)
 * 应用乘法原理，即可知道该正方形的方案数
 */

class DetectSquares {
   public:
    unordered_map<int, unordered_map<int, int>> hash;
    DetectSquares() {}

    void add(vector<int> point) {
        int x = point[0], y = point[1];
        hash[x][y]++;
    }

    int count(vector<int> point) {
        int ans = 0;
        int x = point[0], y = point[1];
        if (hash.count(x) == 0) return 0;
        auto xcnt = hash[x];
        for (auto [c, ccnt] : hash) {
            if (c == x) continue;
            int d = c - x;  // 边长
            // 乘法原理计算所有出现次数
            ans += ccnt[y] * ccnt[y + d] * xcnt[y + d];
            ans += ccnt[y] * ccnt[y - d] * xcnt[y - d];
        }
        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */