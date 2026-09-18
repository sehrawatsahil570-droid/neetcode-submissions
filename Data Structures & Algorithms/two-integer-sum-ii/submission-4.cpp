class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int str=0;
        int end=numbers.size()-1;
        while(end>str){
            int sum = numbers[str]+numbers[end];
            if(sum == target){
                return {str+1,end+1};

            }
            else if(sum<target){
                str++;
                
            }
            else{
                end--;
            }
        }
        return {};
    }
    
};
