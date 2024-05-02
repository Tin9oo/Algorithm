import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        int answer = 0;

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String s;
        int a, b;
        while(true) {
            s = br.readLine();
            a = Integer.parseInt(s.split(" ")[0]);
            b = Integer.parseInt(s.split(" ")[1]);
            if(a == 0 && b == 0) break;

            int total = calWatt(a);
            int low = 1;
            int high = total / 2;

            while(low <= high) {
                int mid = (low + high) / 2;

                int aCost = calCost(mid);
                int bCost = calCost(total - mid);

                int diff = Math.abs(aCost - bCost);
                if(diff < b) {
                    high = mid - 1;
                } else if(diff > b) {
                    low = mid + 1;
                } else {
                    System.out.println(calCost(mid));
                    break;
                }
            }
        }
    }

    public static int calWatt(int co) {
        if(co <= 200) {
            return co / 2;
        } else if(co <= (200 + 9900*3)) {
            return (co - 200) / 3 + 100;
        } else if(co <= (200 + 9900*3 + 990000*5)) {
            return (co - 200 - 9900*3) / 5 + 100 + 9900;
        } else {
            return (co - 200 - 9900*3 - 990000*5) / 7 + 100 + 9900 + 990000;
        }
    }

    public static int calCost(int wh) {
        if(wh <= 100) {
            return wh * 2;
        } else if(wh <= 10000) {
            return 100 * 2 + (wh - 100) * 3;
        } else if(wh <= 1000000) {
            return 100 * 2 + 9900 * 3 + (wh - 10000) * 5;
        } else {
            return 100 * 2 + 9900 * 3 + 990000 * 5 + (wh - 1000000) * 7;
        }
    }
}
