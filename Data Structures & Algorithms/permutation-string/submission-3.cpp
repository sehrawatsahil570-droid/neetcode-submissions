class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>mp;
        for(int i=0;i<s1.size();i++){
            mp[s1[i]]++;
        }
        
        int l=0,r=0,count=0;
        
        int n=s1.size();
        while(r < s2.size()){
            if(mp[s2[r]] >0){
               mp[s2[r]]--;
            count+=1;
            }
            else {
             mp[s2[r]]--;
            }
            

            if(r-l+1 > n){
                mp[s2[l]]++;

                if(mp[s2[l]] >0)
                    count--;

                
               l++;
            }
            if(count == n)
            return true;

            r=r+1;
           
        }
        return false;
    }
};
