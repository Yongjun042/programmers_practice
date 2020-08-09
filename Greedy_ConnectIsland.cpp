#include <string>
#include <vector>
#include<tuple>
#include<algorithm>

using namespace std;

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    int i, j;
    int group[100];
    int left, right;
    int tmp;
    for (j = 0; j < 100; j++)
    {
        group[j] = j;
    }
    vector<tuple<int, int, int> > lines;
    for (i = 0; i < costs.size(); i++)
    {
        lines.push_back(make_tuple(costs[i][2], costs[i][0], costs[i][1]));

    }
    sort(lines.begin(), lines.end());
    for (i = 0; i < costs.size(); i++)
    {
        left = get<1>(lines[i]);
        right = get<2>(lines[i]);
        if (group[left] != group[right])
        {
            if (group[left] < group[right])
            {
                tmp = group[right];
                for (j = 0; j < 100; j++)
                {
                    if (group[j] == tmp)
                    {
                        group[j] = group[left];
                    }
                }
            }
            else
            {
                tmp = group[left];
                for (j = 0; j < 100; j++)
                {
                    if (group[j] == tmp)
                    {
                        group[j] = group[right];
                    }
                }
            }
            answer += get<0>(lines[i]);
        }
    }
    return answer;
}
