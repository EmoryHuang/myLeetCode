class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int n = points.size();
        int min = INT_MAX, pos=-1;
        for(int i=0;i<n;i++){
            if(points[i][0]==x || points[i][1]==y){
                int dis = abs(points[i][0]-x) + abs(points[i][1]-y);
                if(min>dis){
                    min = dis;
                    pos = i;
                }
            }
        }
        return pos;
    }
};