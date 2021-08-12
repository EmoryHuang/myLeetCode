/*
 * @Descroption: LeetCode 729. 我的日程安排表 I
 * @Author: EmoryHuang
 * @Date: 2021-08-11 20:08:53
 * @Method:
 * 暴力遍历，检查当前每个日程安排是否与新日程安排冲突
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