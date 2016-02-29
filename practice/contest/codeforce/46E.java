//http://codeforces.com/problemset/problem/46/E
import java.io.IOException;
import java.util.*;

public class Main {

    public static int [][] BOARD;

    public static List<Integer> ARRAY;
    public static int N;
    public static int M;

    private static boolean isSafe(int row, int col) {
        if (BOARD[row][col] == 0) return false;
        if (ARRAY.size() == 0) return true;
        if (ARRAY.size()%2 == 1) {
            return ARRAY.get(ARRAY.size()-1) > BOARD[row][col];
        } else {
            return ARRAY.get(ARRAY.size()-1) < BOARD[row][col];
        }
    }

    private static boolean solveProblem(int row) {
        if (row >= N) {
            if (ARRAY.size() == N)
                return true;
            else
                return false;
        }
        for (int i = 0; i < M; i++) {
            if (isSafe(row, i)) {
                ARRAY.add(BOARD[row][i]);
                if (solveProblem(row + 1)) return true;
                ARRAY.remove(ARRAY.size()-1);
            }
        }
        return false;
    }



    public static void main(String[] args) throws IOException {
        ARRAY = new LinkedList<>();

        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt();
        M = scanner.nextInt();
        BOARD = new int [N][M];
        for (int i = 0; i<N; i++) {
            for (int j = 0; j<M; j++) {
                BOARD[i][j] = scanner.nextInt();
            }
        }
        solveProblem(0);
        for (int i = 0 ; i < ARRAY.size(); i++)
            System.out.println(ARRAY.get(i));

    }
}
