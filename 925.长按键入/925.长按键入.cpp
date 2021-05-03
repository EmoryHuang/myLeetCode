class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int m = name.size();
        int n = typed.size();
        if(m > n)return false;
        int i=0,j=0;
        while(j < n){
            if(i<m&&name[i]==typed[j]){
                i++;
                j++;
            }else if(j>0 && typed[j-1] == typed[j])
                j++;
            else
                return false;
        }
        return i==m;
    }
};