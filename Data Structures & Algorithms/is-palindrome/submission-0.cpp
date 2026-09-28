class Solution {
public:
    bool isPalindrome(string s) {
        string final_string = "";
        for(char c: s){
            if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')){
                final_string += tolower(c);
            }
        }
        int start = 0;
        int end = final_string.size() - 1;
        while(start <= end){
            if(final_string[start] != final_string[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};
