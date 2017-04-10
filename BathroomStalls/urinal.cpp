#include <cinttypes>
#include <functional>
#include <iostream>
#include <queue>

using namespace std;

typedef queue<pair<int64_t, int64_t>> Queue;

int64_t split(Queue& holes)
{
	auto p = holes.front();
	int64_t max_hole = p.first;
	int64_t count = p.second;

	if (max_hole > 1)
	{
		int64_t min_hole = holes.back().first;

		if (max_hole / 2 == min_hole)
			holes.back().second += count;
		else
			holes.push(make_pair(max_hole / 2, count));

		min_hole = holes.back().first;

		if ((max_hole - 1) / 2 == min_hole)
			holes.back().second += count;
		else if (max_hole > 2)
			holes.push(make_pair((max_hole - 1) / 2, count));
	}

	holes.pop();

	return count;
}

int main()
{
	int64_t T;
	cin >> T;

	for (int64_t t = 0; t < T; ++t)
	{
		int64_t N, K;
		int64_t max_hole = N;
		Queue holes;

		cin >> N >> K;

		holes.push(make_pair(N, 1));

		max_hole = holes.front().first;
		while (K > 0)
		{
			max_hole = holes.front().first;
			K -= split(holes);
		}

		cout << "Case #" << t + 1 << ": " << max_hole / 2 << " " << (max_hole - 1) / 2 << endl;
	}

	return 0;
}
