class Solution {
public:
    bool equalFrequency(string word) {
        
        vector<int> freq(26, 0);
        
        // store frequency of each character
        for(auto ch : word)
            freq[ch - 'a']++;
        
        // iterate over each character 
        for(auto ch : word){
            vector<int> temp = freq;
            temp[ch-'a']--;
            
            // insert freq of characters in set to check 
            // if freq of all characters is euaql or not
            set<int> s;
            
            for(auto x : temp){
                if(x>0)  // if freq is 0 we will not consider this character
                    s.insert(x);
            }
                
            // check if freq are equal
            if(s.size() == 1)
                return true;
            
        }
        return false;
    }
};
