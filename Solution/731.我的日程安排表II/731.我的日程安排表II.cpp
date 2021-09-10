/*
 * @Descroption: LeetCode 731. 我的日程安排表 II
 * @Author: EmoryHuang
 * @Date: 2021-08-11 20:16:53
 * @Method:
 * 暴力遍历，检查当前每个日程安排是否与新日程安排冲突
 * 首先判断是否已经重复，若再次重复，则返回 false
 * 若之前未重复，则将最小的重叠交集加入
 */

class MyCalendarTwo {
   public:
    vector<pair<int, int>> cal, over;
    MyCalendarTwo() {}

    bool book(int start, int end) {
        // 首先判断是否已经重复
        for (auto book : over)
            if (book.first < end && book.second > start) return false;
        // 若之前未重复
        for (auto book : cal)
            if (book.first < end && book.second > start) {
                // 将最小的重叠交集加入
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