#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    int i, m; 
    m = times.size();
    long long min, max, mid, sum;
    min = 1;
    max = (long long)times[m-1]*n;
    answer = max;
    while(min<=max)
    {
        sum = 0;
        mid = (min+max)/2;
        for(i=0;i < m;i++)
        {
            sum += mid/times[i];
        }
        if(n>sum)
        {
            min = mid+1;
        }
        else
        {
            if(mid <= answer)
            {
                answer = mid;
            }
            max = mid-1;
        }
    }
    return answer;
}
