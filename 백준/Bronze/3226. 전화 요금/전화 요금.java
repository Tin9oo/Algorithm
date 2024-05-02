import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        int answer = 0;

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n;
        n = Integer.parseInt(br.readLine());

        for(int i = 0; i < n; i++) {
            String s = br.readLine();

            int hour = Integer.parseInt(s.substring(0, 2));
            int min = Integer.parseInt(s.substring(3, 5));
            int elapse = Integer.parseInt(s.substring(6, 8));

            int time = hour * 60 + min;
            for(int j = 0; j < elapse; j++, time++) {
                if(time == 24 * 60) {
                    time = 0;
                }

                if(0 * 60 <= time && time < 7 * 60) {
                    answer += 5;
                } else if(7 * 60 <= time && time < 19 * 60) {
                    answer += 10;
                } else if (19 * 60 <= time && time < 24 * 60) {
                    answer += 5;
                }
            }
        }

        System.out.print(answer);
    }
}