class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
          int n = words.size();
        
        unordered_map<string, int> freq;
        for (string f : words) {
            freq[f]++;
        }

        vector<string> sortedWords;
        for(auto& it : freq){
            sortedWords.push_back(it.first);
        }

        sort(sortedWords.begin(), sortedWords.end(), [&](const string& a, const string& b) {
            if (freq[a] == freq[b]) {
                return a < b;
            }
            return freq[a] > freq[b];
        });
         sortedWords.resize(k); 
         return sortedWords;
        // priority_queue<string, vector<string>, decltype(cmp)> heap(cmp);

        // for (pair<string, int> p : freq) {
        //     heap.push(p.first);
        //     if (heap.size() > k) {
        //         heap.pop();
        //     }
        // }
        // vector<string> top(k);
        // for (int i = k - 1; i >= 0; i--) {
        //     top[i] = heap.top();
        //     heap.pop();
        // }
        // return top;
    }
};