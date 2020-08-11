#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> arrows) 
{
    int answer = 0;
    map<pair<int, int>, int> vertex;
    map<pair<pair<int, int>, pair<int, int>>, int> edge;
 
    int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    
    int x = 0;
    int y = 0;
    vertex[{x, y}] = 1;
    for(int i = 0; i < arrows.size(); i++)
    {
        for(int j = 0; j < 2; j++)
        {
            int xpos = x + dx[arrows[i]];
            int ypos = y + dy[arrows[i]];
            
            if(vertex[{xpos, ypos}] == 1)
            {
                if(edge[{{x, y}, {xpos, ypos}}] == 0 || edge[{{xpos, ypos}, {x, y}}] == 0)
                {
                    answer++;
                }
            }
 
            vertex[{xpos, ypos}] = 1;
            
            edge[{{x, y}, {xpos, ypos}}] = 1;
            edge[{{xpos, ypos}, {x, y}}] = 1;
            
            x = xpos;
            y = ypos;            
        }   
    }
 
    return answer;
}
