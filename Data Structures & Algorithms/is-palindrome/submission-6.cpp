class Solution {
public:
    bool isPalindrome(string s) {
        int str = 0 ;
        int end = s.size()-1;
        while(str<end){
            if(!isalnum(s[str])){
                str++;
            }
            else if(!isalnum(s[end])){
                end--;
            }
            else {
                if(tolower(s[str]) != tolower(s[end])){
                return false;}
                str++;
                end--;
            }
            
             
        } return true;
       
    }
};
