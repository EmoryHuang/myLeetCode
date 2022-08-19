/*
 * @Descroption: LeetCode 2013. ���������
 * @Author: EmoryHuang
 * @Date: 2022-01-26 11:16:48
 * @Method:
 * ʹ�ù�ϣ��洢�� {x, {y: ��(x, y)���ִ���}}
 * ����ĵ�Ϊ (x, y)���Ȳ�ѯ x �ж�����Щ�У���ö�ٵ� (x, ny)
 * �ɴ˿��Եõ������α߳� d
 * ������Ѱ�� (x �� d, y) �� (x �� d, ny)
 * Ӧ�ó˷�ԭ������֪���������εķ�����
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
            int d = c - x;  // �߳�
            // �˷�ԭ��������г��ִ���
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