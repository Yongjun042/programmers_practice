#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs) {
    //현재 큐에 있는 작업들.
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > min_heap;
    int answer = 0;
    int i = 0;
    //총 지난 시간.
    int timestamp = 0;
    pair<int,int> job_time;
    //시간순대로 벡터 정렬
    sort(jobs.begin(),jobs.end());
    while(true)
    {
        //작업들을 큐에 넣기
        if(i != jobs.size())
        {
            //프린터가 놀고있을경우 새로운 작업이 들어오는 시간으로 넘기기
            if(jobs[i][0] > timestamp && min_heap.empty())
            {
                timestamp = jobs[i][0];
            }
            //작업시간 우선으로 현재 시간까지의 작업들을 우선순위 큐에 넣기.
            for(;i<jobs.size() && jobs[i][0] <=timestamp;i++)
            {
                min_heap.push(make_pair(jobs[i][1],jobs[i][0]));
            }
        }
        if(min_heap.empty())
        {
            break;
        }
        //큐에서 제일 작은 작업 실행시키기
        else
        {
            job_time = min_heap.top();
            min_heap.pop();
            timestamp+= job_time.first;
            answer+=(timestamp - job_time.second);
        }
    }
    if(i != 0)
        answer/=jobs.size();
    return answer;
}