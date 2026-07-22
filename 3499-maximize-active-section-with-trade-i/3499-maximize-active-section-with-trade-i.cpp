class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
       int n = s.size();
       int activecount = count(begin(s) , end(s) , '1');
       vector<int> inactiveblocks;
       int i = 0;
       while(i < n){
          if(s[i] == '0'){
            int start = i;
            while(i < n && s[i] == '0') i++;
            inactiveblocks.push_back(i - start);
          } else i++;
       } 

       int maxPairsum = 0;
       for(int i = 1; i < inactiveblocks.size(); i++){
        maxPairsum = max(maxPairsum , inactiveblocks[i] + inactiveblocks[i-1]);
       }

       return maxPairsum + activecount;
    }
};