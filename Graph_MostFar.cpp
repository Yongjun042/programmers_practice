#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<int> link[20001];
    bool visit[20001] = {true, true, };
    queue<int> que1, que2;
    int tmp;
    bool select = true;
    for(int i = 0; i < edge.size();i++)
    {
        link[edge[i][0]].push_back(edge[i][1]);
        link[edge[i][1]].push_back(edge[i][0]);
    }
    que1.push(1);
    while(!(que1.empty() && que2.empty()))
    {
        answer = 0;
        if(select)
        {
            while(!que1.empty())
            {
                answer++;
                tmp = que1.front();
                que1.pop();
                for(int i =0; i< link[tmp].size(); i++)
                {
                    if(!visit[link[tmp][i]])
                    {
                    que2.push(link[tmp][i]);
                    visit[link[tmp][i]] = true;
                    }
                }
            }
            select = false;
        }
        else
        {
            while(!que2.empty())
            {
                answer++;
                tmp = que2.front();
                que2.pop();
                for(int i =0; i< link[tmp].size(); i++)
                {
                    if(!visit[link[tmp][i]])
                    {
                    que1.push(link[tmp][i]);
                        visit[link[tmp][i]] = true;
                    }
                }
            }
            select = true;
        }
    }
    return answer;
}
