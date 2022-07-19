// TC : O(N)
// SC : O(N)

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int>nums;
        
        for(auto x : tokens){
            
            if(x=="+" or x=="-" or x=="*" or x=="/"){
                int v1 = nums.top();
                nums.pop();
                
                int v2 = nums.top();
                nums.pop();
                
                if(x=="+"){     
                    nums.push(v1+v2);
                }
                else if(x=="-"){ 
                    nums.push(v2-v1);
                }
                else if(x=="*"){
                    nums.push(v1*v2);
                }
                else{      
                    nums.push(v2/v1);
                }
            }
            else{
                nums.push(stoi(x));
            }
        }
        
        return nums.top();
    }
};