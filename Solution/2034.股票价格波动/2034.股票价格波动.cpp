/*
 * @Descroption: LeetCode 2034. ��Ʊ�۸񲨶�
 * @Author: EmoryHuang
 * @Date: 2022-01-23 09:11:38
 * @Method:
 * ģ��
 * ʹ�ù�ϣ��洢ʱ��۸�
 * */

class StockPrice {
   public:
    unordered_map<int, int> m;
    multiset<int> s;
    int max_t = 0;
    StockPrice() {}

    void update(int timestamp, int price) {
        if (m.count(timestamp)) s.erase(s.find(m[timestamp]));
        m[timestamp] = price;
        s.insert(price);
        max_t = max(max_t, timestamp);
    }

    int current() { return m[max_t]; }

    int maximum() { return *s.rbegin(); }

    int minimum() { return *s.begin(); }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */