//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=424
import java.io.IOException;
import java.util.*;

public class Main {


    public static String reverseWord(String word) {
        char[] charArray = word.toCharArray();
        for (int i = 0; i < charArray.length/2; i++) {

            char first = charArray[i];
            char second = charArray[charArray.length-1-i];

            char temp = first;
            charArray[i] = second;
            charArray[charArray.length-1-i] = temp;
        }
        return new String(charArray);
    }

    public static void main(String[] args) throws IOException {
        Scanner read = new Scanner(System.in);
        String line;
        int i = 0;
        while (true) {
            line = read.nextLine();
            if (line.isEmpty()) {
                break;
            }
            String[] array = line.split(" ");

            line = "";
            for (String word : array) {
                line += " " + reverseWord(word);
            }
            System.out.println(line.trim());
        }
    }
}
