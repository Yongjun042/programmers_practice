#include <string>
#include <vector>
#include <map>

using namespace std;

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    long long tmp, room, track;
    map<long long, long long> m;
    for(int i = 0; i< room_number.size(); i++)
    {
        if(m[room_number[i]]==0)
        {
            m[room_number[i]] = room_number[i] + 1;
            answer.push_back(room_number[i]);
        }
        else
        {
            room = room_number[i];
            track = room;
            while(m[room] != 0)
            {
                room =m[room];
            }
            answer.push_back(room);
            room+=1;
            while(m[track]!=0)
            {
                tmp = track;
                track = m[track];
                m[tmp] = room;
            }
            m[room-1] = room;
        }
    }
    return answer;
}
