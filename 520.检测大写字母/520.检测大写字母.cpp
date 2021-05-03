class Solution {
public:
    bool detectCapitalUse(string word) {
        int cnt = 0;
        for(auto c :word)
            if(islower(c)) cnt++;
        if(cnt==word.size() || cnt==0 || (isupper(word[0]) && cnt == word.size()-1))
            return true;
        return false;
    }
};