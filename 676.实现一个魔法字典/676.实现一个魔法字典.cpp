/*
 * @Descroption: LeetCode 676. ʵ��һ��ħ���ֵ�
 * @Author: EmoryHuang
 * @Date: 2021-08-11 19:55:53
 * @Method:
 * ���������������ʴ����ϣ���У��ж�����������ֵ��еĵ����Ƿ�ֻ��һ����ĸ
 */

class MagicDictionary {
   public:
    /** Initialize your data structure here. */
    unordered_map<int, vector<string>> mp;
    MagicDictionary() {}

    void buildDict(vector<string> dictionary) {
        for (auto word : dictionary) mp[word.size()].push_back(word);
    }

    bool search(string searchWord) {
        int n = searchWord.size();
        for (auto word : mp[n]) {
            int cnt = 0;
            for (int i = 0; i < word.size(); i++)
                if (searchWord[i] != word[i]) cnt += 1;
            if (cnt == 1) return true;
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */