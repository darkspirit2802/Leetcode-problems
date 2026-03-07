class Solution {
public:
    int N,M,K;
    int MOD = 1e9+7;
    int t[51][51][101];
    int solve(int idx,int searchCost,int max){
        if(idx==N){
            if(searchCost==K){
                return 1;
            }else{
                return 0;
            }
        }

        if(t[idx][searchCost][max] != -1){
            return t[idx][searchCost][max];
        }
        int result = 0;
        for(int i = 1;i<=M;i++){
            if(i > max){
                result = (result + solve(idx+1,searchCost + 1,i))%MOD;
            }else{
                result =( result + solve(idx+1,searchCost , max))%MOD;
            }
        }

        return t[idx][searchCost][max] = result % MOD;
    }
    int numOfArrays(int n, int m, int k) {
        N = n;
        M = m;
        K = k;
        memset(t,-1,sizeof(t));
        return solve(0,0,0);
    }
};