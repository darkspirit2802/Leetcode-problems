class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        int m = goal.length();

        if(m!=n){
            return false;
        }

        for(int count= 1;count<=n;count++){
            rotate(begin(s),begin(s)+1,end(s));
            if(s==goal){
                return true;
            }
        }
        return false;
    }
};