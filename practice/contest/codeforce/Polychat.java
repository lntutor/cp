// http://codeforces.com/problemset/problem/5/A

import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
        Map<String, String> map = new HashMap<>();
        String line = "";
        String name = "";
        String message = "";
        long result = 0;

        while (scanner.hasNextLine()){
            line = scanner.nextLine();
            if (line.charAt(0) == '+') {
                name = line.substring(1);
                map.put(name, name);
            } else if (line.charAt(0) == '-') {
                name = line.substring(1);
                map.remove(name);
            } else {
                name = line.substring(0, line.indexOf(':'));
                message = line.substring(line.indexOf(':')+1, line.length());
                result += message.length()*map.keySet().size();
            }
        }
        System.out.println(result);
    }
}