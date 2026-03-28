#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_set<char> st;
        int left = 0, maxLength = 0;
        
        for(int right = 0; right < s.size(); right++){
            
            while(st.count(s[right])){
                st.erase(s[left]);
                left++;
            }
            
            st.insert(s[right]);
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};