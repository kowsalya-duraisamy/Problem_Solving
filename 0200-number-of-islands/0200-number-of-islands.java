public class Solution {
    public void removeIsland(char[][] grid, int i, int j) {
        int n = grid.length;
        int m = grid[0].length;
        if (i < 0 || j < 0 || i >= n || j >= m) return;
        if (grid[i][j] == '1') {
            grid[i][j] = '0';
            int[] rows = {-1, 0, 1, 0};
            int[] cols = {0, 1, 0, -1};
            for (int index = 0; index < 4; index++) {
                int ri = rows[index] + i;
                int ci = cols[index] + j;
                removeIsland(grid, ri, ci);
            }
        }
    }

    public int numIslands(char[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        int isLands = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    isLands++;
                    removeIsland(grid, i, j);
                }
            }
        }
        return isLands;
    }
}