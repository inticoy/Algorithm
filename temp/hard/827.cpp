class Solution
{
public:
    int explore(vector<vector<int>> &grid, int x, int y, int key)
    {
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid.size())
            return 0;
        else if (grid[y][x] == 0 || grid[y][x] > 1)
            return 0;

        grid[y][x] = key;
        int left = explore(grid, x - 1, y, key);
        int right = explore(grid, x + 1, y, key);
        int up = explore(grid, x, y - 1, key);
        int down = explore(grid, x, y + 1, key);
        int curr = (left + right + up + down) + 1;
        return curr;
    }

    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<int> m = {0, 0};
        int key = 2;
        for (int y = 0; y < n; y++)
        {
            for (int x = 0; x < n; x++)
            {
                if (grid[y][x] == 1)
                {
                    int blocks = explore(grid, x, y, key++);
                    m.push_back(blocks);
                }
            }
        }

        if (m.size() == 2)
            return 1;

        int answer = 1;

        for (int y = 0; y < n; y++)
        {
            for (int x = 0; x < n; x++)
            {
                if (grid[y][x] == 0)
                {
                    int curr = 1;
                    if (x != 0)
                    {
                        curr += m[grid[y][x - 1]];
                        m[grid[y][x - 1]] *= -1;
                    }
                    if (x != n - 1 && m[grid[y][x + 1]] > 0)
                    {
                        curr += m[grid[y][x + 1]];
                        m[grid[y][x + 1]] *= -1;
                    }
                    if (y != 0 && m[grid[y - 1][x]] > 0)
                    {
                        curr += m[grid[y - 1][x]];
                        m[grid[y - 1][x]] *= -1;
                    }
                    if (y != n - 1 && m[grid[y + 1][x]] > 0)
                    {
                        curr += m[grid[y + 1][x]];
                        m[grid[y + 1][x]] *= -1;
                    }
                    answer = max(curr, answer);

                    if (x != 0 && m[grid[y][x - 1]] < 0)
                        m[grid[y][x - 1]] *= -1;
                    if (x != n - 1 && m[grid[y][x + 1]] < 0)
                        m[grid[y][x + 1]] *= -1;
                    if (y != 0 && m[grid[y - 1][x]] < 0)
                        m[grid[y - 1][x]] *= -1;
                    if (y != n - 1 && m[grid[y + 1][x]] < 0)
                        m[grid[y + 1][x]] *= -1;
                }
            }
        }

        return (answer == 1) ? m[2] : answer;
    }
};