class Solution {
   public:
    bool isPalindrome(string s) {
        int len = s.size();
        int left = 0, right = len - 1;
        while (left < right) {
            char lch = s[left];
            char rch = s[right];
            if (!isalnum(lch))
                left++;
            else if (!isalnum(rch))
                right--;
            else {
                lch = tolower(lch);
                rch = tolower(rch);
                if (lch == rch) {
                    left++;
                    right--;
                } else
                    return false;
            }
        }
        return true;
    }
};