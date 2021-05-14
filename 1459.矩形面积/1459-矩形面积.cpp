class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int x1=max(A,E);
        int y1=max(B,F);
        int x2=min(C,G);
        int y2=min(D,H);
        return (C-A)*(D-B)+(G-E)*(H-F)-max(0,(x2-x1))*max(0,(y2-y1));
    }
};