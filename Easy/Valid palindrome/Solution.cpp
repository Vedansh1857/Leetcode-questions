class Solution {
public:
    bool isPalindrome(string s) {
        string wd = "";
        for(int i=0;i<s.length();i++){
            if(s[i]>='A' && s[i]<='Z'){
                s[i] = tolower(s[i]);
                wd += s[i];
            }
            else if(s[i]>='a' && s[i]<='z'){wd += s[i];}
            else if(s[i]>='0' && s[i]<='9'){wd += s[i];}
            else{continue;}
        }
        string wd2 = wd;
        reverse(wd.begin(),wd.end());
        if(wd == wd2){return true;}
        else{return false;}
    }
};
