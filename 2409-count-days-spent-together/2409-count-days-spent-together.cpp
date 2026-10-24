class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> months = {31,28,31,30,31,30,31,31,30,31,30,31};
        pair<int,int> alice_arrive = {stoi(arriveAlice.substr(0,2)),stoi(arriveAlice.substr(3,5))};
        pair<int,int> alice_going = {stoi(leaveAlice.substr(0,2)),stoi(leaveAlice.substr(3,5))};
        unordered_set<string>st;
        int monthdiff = alice_going.first - alice_arrive.first;
        int month = alice_arrive.first, date = alice_arrive.second;
        for(int i=0;i<=monthdiff;i++){
            for(int j=date;j<= months[month-1];j++){
                st.insert(to_string(month)+"-"+to_string(j));
                if(month == alice_going.first && j == alice_going.second) break;
            }
            month++; date = 1;
        }
        pair<int,int> bob_arrive = {stoi(arriveBob.substr(0,2)),stoi(arriveBob.substr(3,5))};
        pair<int,int> bob_going = {stoi(leaveBob.substr(0,2)),stoi(leaveBob.substr(3,5))};
        monthdiff = bob_going.first - bob_arrive.first;
        month = bob_arrive.first , date = bob_arrive.second;
        int result = 0;
        for(int i=0;i<=monthdiff;i++){
            for(int j=date;j<=months[month-1];j++){
                if(st.count(to_string(month)+"-"+to_string(j))) result++;
                if(month == bob_going.first && j == bob_going.second) break;
            }
            month++; date=1;
        }
        return result;
    }
};