class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>mp;
        int out=0;
        int i=0;
        int j=0;
        int maxfreq=0;
        while(j<s.size()&& i<s.size()){
            
            mp[s[j]]++;
            maxfreq = max(maxfreq , mp[s[j]]);

            while((j-i+1)-maxfreq>k){
                mp[s[i]]--;
                i++;
            }
            out=max(out,j-i+1);
            j++;

        }
        return out;
        
    }
};
