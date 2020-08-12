#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int solution(vector<int> food_times, long long k) {
	int answer = 0;
	long long count = 0;
	long long min;
	vector<pair<int, int> > ft;
	for (int i = 0; i < food_times.size(); i++)
	{
		ft.push_back(make_pair(food_times[i], i));
		count += food_times[i];
	}
	sort(ft.begin(), ft.end(), greater<pair <int, int> >());
	if (count <= k)
	{
		return -1;
	}

	int ftsize = ft.size();
	long long elem = 0;
	for (int i = ft.size() - 1; i != 0; i--)
	{
		min = (long long)ft[i].first - elem;
		if (min == 0)
		{
			ftsize--;
			continue;
		}
		if (min * ftsize < k)
		{
			k -= (min * ftsize);
			elem += min;
			ftsize--;
		}
		else
		{
			break;
		}
	}
	ft.resize(ftsize);

	long long answerNo = (k % ft.size());
	sort(ft.begin(), ft.end(), [](pair<int, int>& left, pair<int, int>& right) {
		return left.second < right.second;
		});
	answer = ft[answerNo].second + 1;



	return answer;
}
