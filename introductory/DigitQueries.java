import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.IOException;

public class DigitQueries {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int q = Integer.parseInt(br.readLine());
        //int q = 1;

        while(q-- > 0) {
            long k = Long.parseLong(br.readLine());
            //long k = 672274832941907421L;
            
            int i = 1;
            int n = 1;
            long prev = 0;
            while(true) {
                long sumN = (1 - (n+1) * (long)Math.pow(10, n) + n * (long)Math.pow(10, n+1))/9;
                if(k-sumN <= 0) {
                    break;
                }
                if(sumN < 0) {
                    break;
                }
                ++n;
                ++i;
                prev = sumN;
            }

            k-=prev;

            long base = (long)Math.pow(10, i-1);
            int digits = i;
            long position = (k+digits-1)/digits;
            long finalNumber = base + position - 1;

            k = k - ((position-1) * digits);

            String finalNumberString = Long.toString(finalNumber);

            System.out.println(finalNumberString.charAt((int)k-1));

        }

    }
}