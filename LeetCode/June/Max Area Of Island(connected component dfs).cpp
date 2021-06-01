int n, m;
int vis[51][51];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int comp[3000];

class Solution {
public:
    
    void dfs(int x, int y, int col, vector<vector<int>>& gr){
        vis[x][y] = col;
        
        for (int i = 0; i < 4; i ++){
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || gr[nx][ny] == 0 || vis[nx][ny])
                continue;
            dfs(nx, ny, col, gr);
        }
        return ;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        int col = 1;
        
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < m; j ++){
                 if (vis[i][j] or grid[i][j] == 0) continue;
                 else{
                     dfs(i, j, col, grid);
                     col ++;
                 }        
        }
        
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < m; j ++)
                comp[vis[i][j]] ++;
                     
        int ans = 0;
        
        for (int i = 1; i < col; i ++)
            ans = max(comp[i], ans);
        
        for (int i = 0; i <= n ;i ++)
            for (int j = 0; j <= m; j ++)
                vis[i][j] = 0;
        
        for (int i = 0; i < col; i ++)
            comp[i] = 0;
        
        return ans;
    }
};
