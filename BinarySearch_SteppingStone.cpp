#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    sort(rocks.begin(),rocks.end());
    int lft, rt, mid, prev, cnt, i;
    lft = 0;
    rt = distance;
    while(lft <= rt)
    {
        cnt = 0;
        mid = (lft +rt)/2;
        prev = 0;
        for(i=0;i<rocks.size();i++)
        {
            if(rocks[i] - prev < mid)
            {
                cnt++;
            }
            else
            {
                prev = rocks[i];
            }
        }
        if(distance - prev < mid)
        {
            cnt++;
        }
        if(cnt <= n)
        {
            if(answer < mid)
            {
                answer = mid;
            }
            lft = mid + 1;
        }
        else
        {
            rt = mid - 1;
        }
    }
    return answer;
}
