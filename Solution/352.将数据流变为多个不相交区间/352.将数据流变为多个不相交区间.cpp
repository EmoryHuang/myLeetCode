/*
 * @Descroption: LeetCode 352. ����������Ϊ������ཻ����
 * @Author: EmoryHuang
 * @Date: 2021-10-09 19:39:58
 * @Method:
 * ���鼯
 * ʹ�ò��鼯��¼��ǰ������Ҷ˵�
 * ��ά��һ�� set ��¼��������
 * �ںϲ����鼯ʱ��������ͬһ�������䣬��������ɾ������Ľڵ�
 */

class SummaryRanges {
   public:
    vector<int> parent;
    set<int> s;  // ��¼���λ��
    SummaryRanges() {
        // ��ʼ�����鼯
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
                // ɾ�����λ��
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
            // �ҵ��յ�λ��
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