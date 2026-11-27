class Solution {
public:
    string interpret(string command) {
        int n = command.length();
        string result = "";
        for(int i=0;i<n;i++){
            char ch = command[i];
            if(ch=='G') result+="G";
            else if(ch == '(' && command[i+1] ==')'){
                result+="o";
                i++;
            }else{
                result+="al";
                i+=3;
            }
        }
        return result;
    }
};