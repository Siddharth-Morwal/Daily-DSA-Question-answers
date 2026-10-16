class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
  
    if(tomatoSlices % 2 != 0 || tomatoSlices > 4 * cheeseSlices || tomatoSlices < 2 * cheeseSlices) return {};

    int total_jumbo = (tomatoSlices - 2 * cheeseSlices) / 2;
    int total_small = (tomatoSlices - 4 * total_jumbo) / 2;

    return {total_jumbo , total_small};

    }
};