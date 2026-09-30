import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class GridColoringI {

    static int[][] neighbors = {{0, -1},{0, 1},{-1, 0},{1, 0}};
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int m, n;
        String line = br.readLine();
        n = Integer.parseInt(line.split(" ")[0]);
        m = Integer.parseInt(line.split(" ")[1]);

        char[][] grid = new char[n][m];

        for(int i=0; i<n; ++i) {
            String row = br.readLine();
            for(int j=0;j<m;++j) {
                grid[i][j] = row.charAt(j);
            }
        }

        boolean[][] visited = new boolean[n][m];
        boolean possible = dfs(grid, 0, 0, visited, n, m);
        if(possible) {
            for(int i=0;i<n;++i) {
                System.out.println(new String(grid[i]));
            }
        } else 
            System.out.println("IMPOSSIBLE");

    }

    static boolean dfs(char[][] grid, int x, int y, boolean[][] visited, int n, int m) {
        if(x<0 || x >= n || y < 0 || y >= m)
            return true;
        if(visited[x][y])
            return true;
        boolean[] choices = {true, true, true, true};
        choices[grid[x][y]-'A'] = false;
        char initColor = grid[x][y];
        boolean possible = false;
        visited[x][y] = true;
        for(int i=0;i<4 && !possible; ++i) {
            if(choices[i]) {
                char toColor = (char)('A'+i);
                boolean canColor = true;
                for(int j=0;j<4; ++j) {
                    int nx = neighbors[j][0]+x;
                    int ny = neighbors[j][1]+y;
                    if(!(nx<0 || nx >= n || ny < 0 || ny >= m)) {
                        if(visited[nx][ny] && grid[nx][ny] == toColor) {
                            canColor = false;
                            break;
                        }
                    }
                }
                if(canColor) {
                    grid[x][y] = toColor;
                    for(int k = 0; k<4; ++k) {
                        int nx = neighbors[k][0]+x;
                        int ny = neighbors[k][1]+y;
                        possible = dfs(grid, nx, ny, visited, n, m);
                    }
                }
            }
        }
        if(!possible) {
            visited[x][y] = false;
            grid[x][y] = initColor;
        }
        
        return possible;

    }
}