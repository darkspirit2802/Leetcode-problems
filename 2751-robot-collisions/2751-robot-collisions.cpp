class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> actual_idx(n);

        iota(begin(actual_idx),end(actual_idx),0);// actual_idx ko 0 se n-1 tk fill kr deta h 
        auto lambda = [&](int &i , int &j){
            return positions[i] < positions[j]; 
        };
        sort(begin(actual_idx),end(actual_idx),lambda);

        vector<int> result;
        stack<int> st;

        for(int &curr : actual_idx){
            if(directions[curr] == 'R'){//towards right
                st.push(curr);
            }else{//towards left
                while(!st.empty() && healths[curr] > 0){
                    int top_idx = st.top();
                    st.pop();

                    if(healths[top_idx] > healths[curr]){
                        healths[top_idx] -= 1;
                        healths[curr] = 0;

                        st.push(top_idx);
                    }else if(healths[top_idx] < healths[curr]){
                        healths[curr] -= 1;
                        healths[top_idx] = 0;
                    }else{
                         healths[curr] = 0;
                        healths[top_idx] = 0;
                    }
                    
                }
            }
        }

        for(int i = 0; i<n;i++){
            if(healths[i] > 0){
                result.push_back(healths[i]);
            }
        }

        return result;
        
    }
};