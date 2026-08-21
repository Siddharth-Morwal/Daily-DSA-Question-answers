class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        int left=0,right=0;
        int cnt=0,maxl=1e9;
        int index=-1;
        vector<int> freq(256,0);
      for(int i=0;i<m;i++){
            freq[t[i]]++;
            }
       while(right<n){
        if(freq[s[right]]>0){
                cnt++;
            }
          freq[s[right]]--;
            
           while(cnt==m){
            if(maxl>right-left+1){
                maxl=right-left+1;
                index=left;
            }
                freq[s[left]]++;
                if(freq[s[left]]>0) cnt--;
                left++;

            }
            right++;
        }
        if(index==-1)return "";
        return s.substr(index,maxl);
    }
};
