#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int>	orig;
	vector<int>	zip;
	int			N;
	int			i;
	int			input;

	cin >> N;
	for (i = 0; i < N; i++)
	{
		cin >> input;
		orig.push_back(input);
		zip.push_back(input);
	}
	sort(zip.begin(), zip.end());
	zip.erase(unique(zip.begin(), zip.end()), zip.end());
	for (i = 0; i < N; i++)
		cout << lower_bound(zip.begin(), zip.end(), orig[i]) - zip.begin() << ' ';
	return (0);
}
