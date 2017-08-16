#include <iostream>
#include <cstring>

using namespace std;

int grid[501][501];
bool vis[501][501];
int m, n;
long long ans = -1;
int cx[] = {-1, 0, 1};
int cy[] = {0, 1, 0};

// Use of depth first search
void dfs(long long sum, int x, int y) {

    if (y == n - 1 && sum > ans) {
        ans = sum;
    }

    for (int i = 0; i < 3; ++i) {
        bool flag = false;
        int nx = x + cx[i];
        if (nx == -1) {
            nx = m - 1;
            flag = true;
        }
        if (nx == m) {
            nx = 0;
            flag = true;
        }
        int ny = y + cy[i];
        if (ny == n) continue;
        if (vis[nx][ny] || grid[nx][ny] == -1) continue;// to check for -1 values
        vis[nx][ny] = true;
        if (flag)
            dfs(grid[nx][ny], nx, ny);
        else {
            dfs(sum + grid[nx][ny], nx, ny);}
        vis[nx][ny] = false;
    }
}

int main() {
    cout<<"Enter Grid :";
    cin>>m>>n;
    cout<<endl<<"Enter Numbers & -1 to Block the Snake"<<endl;
    for(int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin>>grid[i][j];
    memset(vis,false, sizeof(vis));

    for (int i = 0; i < m; ++i) {
        if (grid[i][0] == -1)
            continue;
        vis[i][0] = true;
        dfs(grid[i][0], i, 0);
        vis[i][0] = false;
    }
    cout<<endl<<"Highest Score : "<<ans;
    return 0;
}
