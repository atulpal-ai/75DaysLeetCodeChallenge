#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        
        stack<int> countStack;
        stack<string> stringStack;
        
        string currString = "";
        int currNum = 0;
        
        for(char ch : s){
            
            if(isdigit(ch)){
                currNum = currNum * 10 + (ch - '0');
            }
            
            else if(ch == '['){
                
                countStack.push(currNum);
                stringStack.push(currString);
                
                currNum = 0;
                currString = "";
            }
            
            else if(ch == ']'){
                
                int repeatTimes = countStack.top();
                countStack.pop();
                
                string temp = stringStack.top();
                stringStack.pop();
                
                for(int i = 0; i < repeatTimes; i++){
                    temp += currString;
                }
                
                currString = temp;
            }
            
            else{
                currString += ch;
            }
        }
        
        return currString;
    }
};