/*
 * @Descroption: LeetCode 1311. ��ȡ������ѹۿ�����Ƶ
 * @Author: EmoryHuang
 * @Date: 2021-08-04 10:50:30
 * @Method:
 * bfs��ȡ���Ϊlevel�Ľڵ�
 * ͳ�����Ϊlevel�Ľڵ�Ĺۿ���Ƶͳ��
 * Ȼ���ո���Ҫ���������
 */

class Solution {
   public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id,
                                          int level) {
        int n = watchedVideos.size();
        queue<int> q;
        vector<bool> vis(n);
        q.push(id);
        vis[id] = true;
        // bfs��ȡ���Ϊlevel�Ľڵ�
        for (int i = 0; i < level; i++) {
            int len = q.size();
            for (int j = 0; j < len; j++) {
                int u = q.front();
                q.pop();
                for (auto v : friends[u]) {
                    if (!vis[v]) {
                        q.push(v);
                        vis[v] = true;
                    }
                }
            }
        }
        // ͳ�����Ϊlevel�Ľڵ�Ĺۿ���Ƶͳ��
        unordered_map<string, int> cnt;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto watch : watchedVideos[u]) cnt[watch]++;
        }
        vector<pair<string, int>> videos(cnt.begin(), cnt.end());
        sort(videos.begin(), videos.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
            if (a.second != b.second)
                return a.second < b.second;
            else
                return a.first < b.first;
        });
        vector<string> ans;
        for (auto video : videos) ans.push_back(video.first);
        return ans;
    }
};