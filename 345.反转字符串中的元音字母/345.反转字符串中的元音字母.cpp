class Solution {
   public:
    string reverseVowels(string s) {
        int i = 0, j = s.size() - 1;
        string str = "aeiouAEIOU";
        while (i < j) {
            while (i < j && str.find(s[i]) == string::npos) i++;
            while (i < j && str.find(s[j]) == string::npos) j--;
            swap(s[i], s[j]);
            i++;
            j--;
        }
        return s;
    }
};