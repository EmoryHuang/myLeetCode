/*
 * @Descroption: LeetCode 352. 将数据流变为多个不相交区间
 * @Author: EmoryHuang
 * @Date: 2021-10-09 19:39:58
 * @Method:
 * 并查集
 * 使用并查集记录当前区间的右端点
 * 并维护一个 set 记录区间的起点
 * 在合并并查集时，若属于同一个人区间，则从起点中删除后面的节点
 */

class SummaryRanges {
   public:
    vector<int> parent;
    set<int> s;  // 记录起点位置
    SummaryRanges() {
        // 初始化并查集
        parent.resize(10001, -1);
    }

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    void merge(int x, int y) {
        if (x >= 0 && x <= 10000 && y >= 0 && y <= 10000 && parent[x] != -1 && parent[y] != -1) {
            int px = find(x);
            int py = find(y);
            if (px != py) {
                parent[px] = py;
                // 删除起点位置
                s.erase(y);
            }
        }
    }

    void addNum(int val) {
        if (parent[val] == -1) {
            parent[val] = val;
            s.insert(val);
            merge(val, val + 1);
            merge(val - 1, val);
        }
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        for (auto start : s) {
            // 找到终点位置
            int end = find(start);
            ans.push_back({start, end});
        }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */