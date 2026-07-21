class Solution {
public:
    bool isalphanum(char ch){
        return (ch>='A' && ch <='Z') || (ch>='a' && ch<='z') || (ch>='0' && ch<='9');
    }

    bool isPalindrome(string s) {
       int i=0;
       int j=s.size()-1;
       while(i<j){
        while(i<j && !isalphanum(s[i])){
            i++;
        }
        while(i<j && !isalphanum(s[j])){
            j--;
        }
        if(tolower(s[i])!=tolower(s[j])){
            return false;
        }
        i++;
        j--;
       }
       return true;
    }
};
