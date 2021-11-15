/*
 * @Descroption: LeetCode 677. ��ֵӳ��
 * @Author: EmoryHuang
 * @Date: 2021-11-14 14:23:30
 * @Method:
 * ��ϣ���¼�����ַ���
 * ���ʱ������ϣ��
 */

class MapSum {
   public:
    unordered_map<string, int> hash;
    MapSum() {}

    void insert(string key, int val) { hash[key] = val; }

    int sum(string prefix) {
        int ans = 0;
        unordered_map<string, int>::iterator it;
        for (it = hash.begin(); it != hash.end(); ++it) {
            string cur = it->first;
            if (cur.find(prefix) == 0) ans += it->second;
        }
        return ans;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */