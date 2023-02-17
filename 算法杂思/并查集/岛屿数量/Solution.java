package 并查集.岛屿数量;

import java.util.LinkedList;
// https://leetcode.cn/problems/number-of-islands/solution/dao-yu-shu-liang-by-leetcode/
class DFS {
    /*
     * dfs 需要注意的点
     * 1. 可以通过visited数组去重
     * 2. 入口处判断岛屿数量++
     * 3. dfs内部回调函数前的判断条件考虑全
     *     1. 边界判断
     *     2. visited数组 
     */    
    boolean[][] visited;
    int[][] dir = {{0,1},{0,-1},{1,0},{-1,0}};
    public int numIslands(char[][] grid) {
        int cnt = 0;
        int m = grid.length;
        int n = grid[0].length;
        visited = new boolean[m][n];
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(!visited[i][j] && grid[i][j] == '1') {
                    ++cnt;
                    visited[i][j] = true;
                    dfs(grid, i, j, m, n, visited, cnt);
                }
            }
        }
        return cnt;
    }
    public void dfs(char[][] grid, int x, int y, int m, int n, boolean[][] visited, int cnt) {
        for(int i = 0; i < 4; ++i) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if(0 <= nx && nx < m && 0 <= ny && ny < n && !visited[nx][ny] && grid[nx][ny] == '1') {
                visited[nx][ny] = true;
                dfs(grid, nx, ny, m, n, visited, cnt);
            }
        }
    }
}

class BFS {
    /*
     * bfs 需要注意的点
     * 1. 外循环 在栈为空后新增cnt
     * 2. 内循环 处理同一个岛屿四个方向上的链接
     */
    boolean[][] visited;
    int[][] dir = {{0,1},{0,-1},{1,0},{-1,0}};
    public int numIslands(char[][] grid) {
        int cnt = 0;
        int m = grid.length;
        int n = grid[0].length;
        visited = new boolean[m][n];
        LinkedList<int[]> list = new LinkedList<>();
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(!visited[i][j] && grid[i][j] == '1') {
                    cnt++;
                    visited[i][j] = true;
                    list.addLast(new int[]{i, j});
                    while(!list.isEmpty()) {
                        int r = list.getLast()[0];
                        int c = list.getLast()[1];
                        list.pollLast();
                        for(int k = 0; k < 4; ++k) {
                            int nr = r + dir[k][0];
                            int nc = c + dir[k][1];
                            if(0 <= nr && nr < m && 0 <= nc && nc < n && !visited[nr][nc] && grid[nr][nc] == '1') {
                                list.addLast(new int[]{nr, nc});
                                visited[nr][nc] = true;
                            }
                        }
                    }
                }
            }
        }
        return cnt;
    }
}

class UnionFind {
    /*
     * 并查集 需要注意的点
     * 
     */
    private int[] parent;
    private int[] rank;
    boolean[][] visited;
    int[][] dir = {{0,1},{0,-1},{1,0},{-1,0}};
    int count;
    public UnionFind(char[][] grid) {
        count = 0;
        int m = grid.length;
        int n = grid[0].length;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == '1') {
                    parent[parent.length-1] = i*n+j;
                    ++count;
                }else {
                    parent[parent.length-1] = -1;
                }
                rank[rank.length-1] = 0;
            }
        }
    }
    int find(int i) {
        if(parent[i] != i) {
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }
    void unite(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if(rootx != rooty) {
            if(rank[rootx] < rank[rooty]) {
                swap(rootx, rooty);
            }
            parent[rooty] = rootx;
            if(rank[rootx] == rank[rooty]) rank[rootx] += 1;
            --count;
        }
    }
    int getCount() {
        return count;
    }
    void swap(int x, int y) {
        int tmp = x;
        x = y;
        y = tmp;
    }
    public int numIslands(char[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        visited = new boolean[m][n];
        UnionFind uf = new UnionFind(grid);
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(!visited[i][j] && grid[i][j] == '1') {
                    visited[i][j] = true;
                    for(int k = 0; k < 4; ++k) {
                        int ni = i + dir[k][0];
                        int nj = j + dir[j][0];
                        if(0 <= ni && ni < m && 0 <= nj && nj < n && !visited[ni][nj] && grid[ni][nj] == '1') {
                            uf.unite(ni*m + nj, i*m+j);
                        }
                    }
                }
            }
        }
        return uf.getCount();
    }
}