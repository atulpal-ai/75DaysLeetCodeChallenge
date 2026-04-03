#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        int n = temperatures.size();
        vector<int> result(n, 0);
        stack<int> st; // store indices
        
        for(int i = 0; i < n; i++){
            
            while(!st.empty() && temperatures[i] > temperatures[st.top()]){
                
                int prev = st.top();
                st.pop();
                
                result[prev] = i - prev;
            }
            
            st.push(i);
        }
        
        return result;
    }
};