/*
 * @Descroption: ������ 16.02. ����Ƶ��
 * @Author: EmoryHuang
 * @Date: 2021-07-18 14:34:38
 * @����˼·:
 * ��ϣ��
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