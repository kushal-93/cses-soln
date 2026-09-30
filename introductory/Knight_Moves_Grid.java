import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Knight_Moves_Grid {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        int[][] grid = new int[n][n];

        for(int i=0;i<n;++i) {
            for(int j=0;j<n;++j)
                grid[i][j] = -1;
        }

        grid[0][0] = 0;

        for(int i=0;i<n;++i) {
            for(int j=0;j<n;++j) {
                if(grid[i][j] != -1)
                    helper(grid, i, j);
            }
        }
    }

    void helper(int[][] grid, int i, int j) {
        
        int[] init = {i, j};

        Queue<int[]> q = new LinkedList<>();
        q.offer(init);
        int minMove = Integer.MAX_VALUE;
        int moves = 0;

        while(!q.isEmpty()) {
            int size = q.size();
            while(size-- > 0) {
                int[] cell = q.poll();
                if(grid[cell[0]][cell[1]] != -1) {

                }


                ++moves;
            }
        }


    }
}