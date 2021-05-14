class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        int maxr=0;
        vector<int> maxc(n);
        for(int i=0;i<m;i++){
            maxr=0;
            for(int j=0;j<n;j++){
                if(grid[i][j]) ans++;
                maxr=max(maxr,grid[i][j]);
                maxc[j]=max(maxc[j],grid[i][j]);
            }
            ans += maxr;
        }
        for(int i=0;i<n;i++)
            ans += maxc[i];
        return ans;
    }
};