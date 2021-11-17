class Solution {
   public:
    // ����һ����ϣ��
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        map<pair<int, int>, int> cnt;
        // ���£����£����ϣ�����
        int lb = rectangles[0][0], rb = rectangles[0][1], lt = rectangles[0][2], rt = rectangles[0][3];
        // ��������
        int area = 0;
        for (auto rect : rectangles) {
            int x = rect[0], y = rect[1], a = rect[2], b = rect[3];
            area += (a - x) * (b - y);
            lb = min(lb, x);
            lt = max(lt, a);
            rb = min(rb, y);
            rt = max(rt, b);
            cnt[{a, b}]++, cnt[{a, y}]++, cnt[{x, y}]++, cnt[{x, b}]++;
        }
        // ��С�������֮�Ͳ����ڴ���������������������
        // ���£����ϣ����£�����ֻ�����һ��
        if (area != (rt - rb) * (lt - lb) || cnt[{lb, rb}] != 1 || cnt[{lb, rt}] != 1 || cnt[{lt, rb}] != 1 || cnt[{lt, rt}] != 1)
            return false;
        cnt.erase({lb, rb}), cnt.erase({lb, rt}), cnt.erase({lt, rb}), cnt.erase({lt, rt});
        for (auto& entry : cnt) {
            int value = entry.second;
            if (value != 2 && value != 4) {
                return false;
            }
        }
        return true;
    }
};