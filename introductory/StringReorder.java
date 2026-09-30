import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;

public class StringReorder {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        // String str = "TATTIVTTAT";

        int[] freq = new int[26];
        int maxFreq = 0;

        for (int i = 0; i < str.length(); ++i) {
            freq[str.charAt(i) - 'A']++;
        }

        PriorityQueue<Character> maxHeap = new PriorityQueue<>((a, b) -> (freq[b - 'A'] - freq[a - 'A']));

        for (int i = 0; i < 26; ++i) {
            if (freq[i] > 0) {
                maxHeap.offer((char) ('A' + i));
                maxFreq = Math.max(maxFreq, freq[i]);
            }
        }

        if (maxFreq > (str.length() + 1) / 2) {
            System.out.println("-1");
            return;
        }

        char prev = '#';
        StringBuilder sb = new StringBuilder();
        int n = str.length();
        while (!maxHeap.isEmpty()) {
            char mostFrequent = maxHeap.peek();
            if (2 * freq[mostFrequent - 'A'] - 1 >= n) {
                mostFrequent = maxHeap.poll();
                sb.append(mostFrequent);
                prev = mostFrequent;
                freq[mostFrequent - 'A']--;
                if (freq[mostFrequent - 'A'] > 0) {
                    maxHeap.offer(mostFrequent);
                }
            } else {
                char smallest = getSmallest(freq, -1);
                if (smallest == prev) {
                    smallest = getSmallest(freq, smallest - 'A');
                }
                sb.append(smallest);
                maxHeap.remove(smallest);
                prev = smallest;
                freq[smallest - 'A']--;
                if (freq[smallest - 'A'] > 0) {
                    maxHeap.offer(smallest);
                }
            }
            --n;

        }

        System.out.println(sb.toString());

    }

    static char getSmallest(int[] freq, int index) {
        for (int i = index + 1; i < freq.length; ++i) {
            if (freq[i] > 0) {
                return (char) (i + 'A');
            }
        }

        return '#';
    }
}
