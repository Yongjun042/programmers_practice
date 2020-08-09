#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    bool visit[200] = {};
    int i,j, k;
    i = 0;
    queue<int> nodeList ;
    while(i<n)
    {
        if(visit[i])
        {
           i ++ ;
        }
        else
        {
            answer++;
            nodeList.push(i);
            visit[i] = true;
            while(!nodeList.empty())
            {
                k = nodeList.front();
                nodeList.pop();
                for(j = 0;j<n;j++)
                {
                    if(computers[k][j] && !visit[j])
                    {
                        visit[j] = true;
                        nodeList.push(j);
                    }
                }
            }
        }
    }
    return answer;
}
