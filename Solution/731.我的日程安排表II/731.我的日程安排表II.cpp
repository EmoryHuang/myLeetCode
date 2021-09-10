/*
 * @Descroption: LeetCode 731. �ҵ��ճ̰��ű� II
 * @Author: EmoryHuang
 * @Date: 2021-08-11 20:16:53
 * @Method:
 * ������������鵱ǰÿ���ճ̰����Ƿ������ճ̰��ų�ͻ
 * �����ж��Ƿ��Ѿ��ظ������ٴ��ظ����򷵻� false
 * ��֮ǰδ�ظ�������С���ص���������
 */

class MyCalendarTwo {
   public:
    vector<pair<int, int>> cal, over;
    MyCalendarTwo() {}

    bool book(int start, int end) {
        // �����ж��Ƿ��Ѿ��ظ�
        for (auto book : over)
            if (book.first < end && book.second > start) return false;
        // ��֮ǰδ�ظ�
        for (auto book : cal)
            if (book.first < end && book.second > start) {
                // ����С���ص���������
                over.push_back({max(book.first, start), min(book.second, end)});
            }
        cal.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */