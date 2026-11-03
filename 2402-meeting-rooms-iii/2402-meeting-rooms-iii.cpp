class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();
        sort(meetings.begin(), meetings.end());

        vector<long long> lastavailable(n, 0);
        vector<int> roomusedcount(n, 0);

        for (vector<int> meet : meetings) {

            long long start = meet[0];
            long long end = meet[1];
            long long duration = end - start;
            bool found = false;

            long long earlyendroomtime = LLONG_MAX;
            long long earlyendroom = 0;

            for (int room = 0; room < n; room++) {

                if (lastavailable[room] <= start) {
                    lastavailable[room] = end;
                    roomusedcount[room]++;
                    found = true;
                    break;
                }

                if (lastavailable[room] < earlyendroomtime) {
                    earlyendroomtime = lastavailable[room];
                    earlyendroom = room;
                }
            }
            if (!found) {
                lastavailable[earlyendroom] += duration;
                roomusedcount[earlyendroom]++;
            }
        }
        int resultroom = -1;
        int maxuse = 0;

        for (int room = 0; room < n; room++) {
            if (roomusedcount[room] > maxuse) {
                maxuse = roomusedcount[room];
                resultroom = room;
            }
        }
        return resultroom;
    }
};