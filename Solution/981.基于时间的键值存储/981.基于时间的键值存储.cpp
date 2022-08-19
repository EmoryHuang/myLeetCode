/*
 * @Descroption: LeetCode 981. ����ʱ��ļ�ֵ�洢
 * @Author: EmoryHuang
 * @Date: 2021-07-10 14:01:43
 * @����˼·:
 * ��ϣ�� + ����
 * ʹ�ù�ϣ��洢 key, value, timestamp
 * �����Ҫ���ҵ� key, ʹ�ö�����������С�ڵ��� timestamp �ĵ�һ��ֵ
 */

class TimeMap {
   public:
    /** Initialize your data structure here. */
    unordered_map<string, vector<pair<string, int>>> mp;
    TimeMap() {}

    void set(string key, string value, int timestamp) { 
        mp[key].push_back({value, timestamp}); 
    }

    string get(string key, int timestamp) {
        if (!mp.count(key)) return "";
        int l = 0, r = mp[key].size() - 1;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (mp[key][mid].second <= timestamp)
                l = mid;
            else
                r = mid - 1;
        }
        return mp[key][r].second > timestamp ? "" : mp[key][r].first;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */