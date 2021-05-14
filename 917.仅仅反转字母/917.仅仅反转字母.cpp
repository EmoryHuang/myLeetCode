class Solution {
public:
    string reverseOnlyLetters(string S) {
        int left=0,right=S.size()-1;
        while(left<right){
            while(left<right && !isalpha(S[left])) left++;
            while(left<right && !isalpha(S[right])) right--;
            if(left<right) swap(S[left++],S[right--]);
        }
        return S;
    }
};