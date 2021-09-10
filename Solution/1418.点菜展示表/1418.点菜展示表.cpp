/*
 * @Descroption: LeetCode 1418. ���չʾ��
 * @Author: EmoryHuang
 * @Date: 2021-07-06 20:51:40
 * @����˼·:
 * ʹ�ù�ϣ��ͳ�� ���� : {��Ʒ : ����}
 * Ȼ��ͳ�����
 */

class Solution {
   public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        set<string> fds;
        vector<vector<string>> ans;
        // ���� : {��Ʒ : ����}
        unordered_map<int, unordered_map<string, int>> hash;
        for (auto order : orders) {
            int table = stoi(order[1]);
            string food = order[2];
            fds.insert(food);
            ++hash[table][food];  // ������ϣ��
        }
        // ���� title
        vector<string> foods(fds.begin(), fds.end());
        sort(foods.begin(), foods.end());
        vector<string> title;
        title.push_back("Table");
        for (auto food : foods) title.push_back(food);
        ans.push_back(title);
        // ��������
        vector<int> tables;
        for (auto [table, _] : hash) tables.push_back(table);
        sort(tables.begin(), tables.end());

        for (auto table : tables) {
            unordered_map<string, int> mp(hash[table].begin(), hash[table].end());
            vector<string> cur;
            cur.push_back(to_string(table));                             // ����
            for (auto food : foods) cur.push_back(to_string(mp[food]));  // ʳ��
            ans.push_back(cur);
        }
        return ans;
    }
};