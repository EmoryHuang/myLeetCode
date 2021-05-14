class Solution {
public:
    int numRabbits(vector<int>& answers) {
        sort(answers.begin(),answers.end());
        int len = answers.size();
        int ans = 0;
        for(int i=0;i<len;i++){
            ans += answers[i]+1;
            int k=answers[i];
            while(k-- && i+1<len && answers[i]==answers[i+1])
                i++;
        }
        return ans;
    }
};