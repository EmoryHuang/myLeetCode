class Solution {
public:
    double average(vector<int>& salary) {
        int sum = 0,maxs = INT_MIN,mins = INT_MAX;
        for(int i = 0;i<salary.size();i++){
            sum += salary[i];
            maxs = max(maxs,salary[i]);
            mins = min(mins,salary[i]);
        }
        return 1.0*(sum-maxs-mins)/(salary.size()-2);
    }
};