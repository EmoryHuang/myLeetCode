class Solution {
   public:
    string reverseWords(string s) {
        s += " ";
        int left = 0;  // ��¼�������λ��
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                reverse(s.begin() + left, s.begin() + i);
                left = i + 1;
            }
        }
        s.erase(s.end() - 1);
        return s;
    }
};