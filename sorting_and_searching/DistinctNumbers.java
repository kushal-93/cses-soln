import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;

public class DistinctNumbers {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[] arr = new String[n];
        arr = br.readLine().split(" ");
        HashSet<String> set = new HashSet<>();
        for(int i=0; i<n; i++) {
            set.add(arr[i]);
        }
        System.out.println(set.size());
    }
}