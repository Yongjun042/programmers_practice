#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    int startP, endP;
    startP = -30001;
    endP = 30001;
    
    sort(routes.begin(),routes.end());
    for(int i = 0; i<routes.size();i++)
    {
        if(endP < routes[i][0])
        {
            answer++;
            startP = routes[i][0];
            endP = routes[i][1];
        }
        else
        {
            startP = routes[i][0];
            if(endP > routes[i][1])
            {
                endP = routes[i][1];
            }
        }
    }
    return answer + 1;
}
