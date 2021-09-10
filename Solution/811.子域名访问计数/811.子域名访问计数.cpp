/*
 * @Descroption: LeetCode 811. 子域名访问计数
 * @Author: EmoryHuang
 * @Date: 2021-05-22 14:08:00
 * @解题思路:
 * 首先提出前面的数字，然后从后往前遍历
 * 使用哈希表存储每个域名的访问次数
 */

class Solution {
   public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map<string, int> mp;
        vector<string> ans;
        for (auto cpdomain : cpdomains) {
            int count = 0;
            // 提取前面的数字
            for (int i = 0; cpdomain[i] != ' '; i++) 
                count = count * 10 + (cpdomain[i] - '0');
            // 从后往前遍历，每读到'.',就将其加入哈希表
            int j = cpdomain.size() - 1;
            for (; cpdomain[j] != ' '; j--)
                if (cpdomain[j] == '.') 
                    mp[cpdomain.substr(j + 1)] += count;
            mp[cpdomain.substr(j + 1)] += count;
        }
        map<string, int>::iterator it;
        for (it = mp.begin(); it != mp.end(); it++)
            ans.push_back(to_string(it->second) + " " + it->first);
        return ans;
    }
};