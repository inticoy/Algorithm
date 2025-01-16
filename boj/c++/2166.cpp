#include <iostream>
#include <utility>
#include <vector>

using namespace std;

using vec = pair<double, double>;

double cross_product(vec v1, vec v2)
{
    double cross = v1.first * v2.second - v1.second * v2.first;
    return cross / 2;
}

double absf(double f) { return f * (f >= 0 ? 1 : -1); }

int main(int argc, char **argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x, y;
    vector<vec> v;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }

    double sum = 0;
    for (int i = 0; i < n - 2; i++)
    {
        vec vec1 = make_pair(v.at(i + 1).first - v.at(0).first, v.at(i + 1).second - v.at(0).second);
        vec vec2 = make_pair(v.at(i + 2).first - v.at(0).first, v.at(i + 2).second - v.at(0).second);
        sum += cross_product(vec1, vec2);
    }

    cout << fixed;
    cout.precision(1);

    cout << absf(sum);

    return 0;
}