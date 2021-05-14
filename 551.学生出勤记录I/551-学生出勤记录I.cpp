class Solution {
public:
    bool checkRecord(string s) {
        int countA = 0;
        int countL = s.find("LLL");
        for(auto c:s)
            if(c=='A')countA++;
        return countA < 2 && countL==-1;
    }
};