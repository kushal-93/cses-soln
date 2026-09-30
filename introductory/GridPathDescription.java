import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class GridPathDescription {

    static int count;
    static int[][] moves = { { 0, -1 }, { 0, 1 }, { -1, 0 }, { 1, 0 } };

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        // String path = "??????R??????U??????????????????????????LD????D?";
        //String path = "????";
        String path = reader.readLine();
        boolean[][] visited = new boolean[7][7];
        //visited[0][0] = true;
        count = 0;
        helper(0, path, 0, 0, visited);
        System.out.println(count);
    }

    static void helper(int index, String path, int x, int y, boolean[][] visited) {
        if (x < 0 || x > 6 || y < 0 || y > 6)
            return;
        if (visited[x][y])
            return;
        if (x == 6 && y == 0) {
            if(index == path.length())
                ++count;
            return;
        }
        if(index >= path.length())
            return;

        if((y-1<0 || visited[x][y-1]) && (y+1>6 || visited[x][y+1])) {
            if(x-1>=0 && !visited[x-1][y] && x+1<7 && !visited[x+1][y])
                return;
        }

        if((x-1<0 || visited[x-1][y]) && (x+1>6 || visited[x+1][y])) {
            if(y-1>=0 && !visited[x][y-1] && y+1<7 && !visited[x][y+1])
                return;
        }
        
        char c = path.charAt(index);
        visited[x][y] = true;
        switch (c) {
            case 'U':
                helper(index + 1, path, x - 1, y, visited);
                break;
            case 'D':
                helper(index + 1, path, x + 1, y, visited);
                break;
            case 'L':
                helper(index + 1, path, x, y - 1, visited);
                break;
            case 'R':
                helper(index + 1, path, x, y + 1, visited);
                break;
            default:
                for (int[] move : moves) {
                    helper(index + 1, path, x + move[0], y + move[1], visited);
                }
        }
        visited[x][y] = false;
    }

}
