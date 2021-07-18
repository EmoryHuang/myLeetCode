/*
 * @Descroption: 面试题 16.02. 单词频率
 * @Author: EmoryHuang
 * @Date: 2021-07-18 14:34:38
 * @解题思路:
 * 哈希表
 */

class WordsFrequency {
   public:
    map<string, int> mp;
    WordsFrequency(vector<string>& book) {
        for (auto s : book) mp[s]++;
    }

    int get(string word) { 
        return mp[word]; 
    }
};

/**
 * Your WordsFrequency object will be instantiated and called as such:
 * WordsFrequency* obj = new WordsFrequency(book);
 * int param_1 = obj->get(word);
 */