/*
 * @Descroption: LeetCode 933. 最近的请求次数
 * @Author: EmoryHuang
 * @Date: 2022-05-05 08:47:24
 * @Method:
 * 简单题，使用队列模拟
 * 若队首元素超时，则删除队首元素
 */


class RecentCounter {
   public:
    queue<int> q;
    RecentCounter() {}

    int ping(int t) {
        q.push(t);
        while (q.front() < t - 3000) q.pop();
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */