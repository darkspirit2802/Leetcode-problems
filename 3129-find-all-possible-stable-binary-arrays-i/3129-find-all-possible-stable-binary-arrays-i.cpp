class Solution {
public:
    int M = 1e9 + 7;
    int t[201][201][2];
    int solve(int onesLeft,int zeroesLeft,bool lastWasOne,int limit){
        if(onesLeft==0 && zeroesLeft==0){
            return 1;
        }

        
        if(t[onesLeft][zeroesLeft][lastWasOne]!=-1){
            return t[onesLeft][zeroesLeft][lastWasOne];
        }
        int result = 0;
        if(lastWasOne == true){
            for(int len = 1;len <= min(zeroesLeft,limit);len++){
                result = (result + solve(onesLeft, zeroesLeft - len, false, limit)) % M;
            }
        }else{
            for(int len = 1;len <= min(onesLeft,limit);len++){
                result = (result + solve(onesLeft - len, zeroesLeft, true, limit)) % M;
            }
        }

        return t[onesLeft][zeroesLeft][lastWasOne] = result;
    }

    int numberOfStableArrays(int zero, int one, int limit) {

        memset(t,-1,sizeof(t));
        int start_with_zero = solve(one,zero,true,limit);
        int start_with_one = solve(one,zero,false,limit);    


        return (start_with_zero + start_with_one)%M;
    }
};