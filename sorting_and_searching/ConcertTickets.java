import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.TreeMap;

public class ConcertTickets {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] nm = br.readLine().split(" ");
        int n = Integer.parseInt(nm[0]), m = Integer.parseInt(nm[1]);
        TreeMap<Long, Integer> pmap = new TreeMap<>();
        String[] prices = br.readLine().split(" ");
        for (String ps : prices) {
            long p = Long.parseLong(ps);
            pmap.put(p, pmap.getOrDefault(p, 0)+1);
        }
        //System.out.println(list);
        String[] custs = br.readLine().split(" ");
        for(int i=0; i<m; i++) {
            long c = Long.parseLong(custs[i]);
            Long ub = pmap.floorKey(c);
            if(ub == null) {
                System.out.println("-1");
            } else {
                System.out.println(ub);
                if(pmap.get(ub) == 1) {
                    pmap.remove(ub);
                } else {
                    pmap.put(ub, pmap.get(ub)-1);
                }
            }
        }

    }
}