class Solution {
public:
    string processStr(string s) {
        int n = s.length();
        string result;
        for(int i = 0;i<n;i++){
            if(s[i]== '*'){
                if(result.length() >= 1){
                    result.pop_back();
                }else{
                    continue;
                }
            }else if(s[i]=='#'){
                result  = result + result;
            }else if(s[i]=='%'){
                reverse(begin(result),end(result));
            }else{
                result += s[i];
            }
        }
        return result;
    }
};