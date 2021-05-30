/*
 * @Descroption: LeetCode 705. 设计哈希集合
 * @Author: EmoryHuang
 * @Date: 2021-05-30 10:30:00
 * @解题思路:
 * 直接使用一个 bool 数组记录某个 key 是否存在
 */

class MyHashSet {
   public:
    vector<bool> mp;
    /** Initialize your data structure here. */
    MyHashSet() { mp.resize(1000005,0); }

    void add(int key) { mp[key] = true; }

    void remove(int key) { mp[key] = false; }

    /** Returns true if this set contains the specified element */
    bool contains(int key) { return mp[key] == true; }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */