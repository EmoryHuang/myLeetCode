/*
 * @Descroption: LeetCode 729. �ҵ��ճ̰��ű� I
 * @Author: EmoryHuang
 * @Date: 2021-08-11 20:08:53
 * @Method:
 * ������������鵱ǰÿ���ճ̰����Ƿ������ճ̰��ų�ͻ
 */

class MyCalendar {
   public:
    vector<vector<int>> cal;
    MyCalendar() {}

    bool book(int start, int end) {
        for (auto book : cal)
            if (book[0] < end && book[1] > start) return false;
        cal.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */