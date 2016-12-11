import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
    public static int count_cell(int [][] grid, int i, int j) {
      if (i < 0 || j < 0 || i >= grid.length  || j >= grid[0].length) return 0;

      if (grid[i][j] == 0) return 0;

      grid[i][j] = 0;//mark as visited
      int count = 1;
      count += count_cell(grid, i - 1, j - 1);
      count += count_cell(grid, i - 1, j);
      count += count_cell(grid, i - 1, j+1);
      count += count_cell(grid, i , j - 1);
      count += count_cell(grid, i , j + 1);
      count += count_cell(grid, i +1 , j - 1);
      count += count_cell(grid, i +1 , j);
      count += count_cell(grid, i +1 , j + 1);
      return count;
    }

    public static int getBiggestRegion(int[][] grid) {
        int MAX = 0;
        for (int i = 0; i < grid.length ; i++) {
            for (int j = 0; j < grid[0].length; j++){
                MAX = Math.max(MAX, count_cell(grid, i, j));
            }
        }
        return MAX;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        int grid[][] = new int[n][m];
        for(int grid_i=0; grid_i < n; grid_i++){
            for(int grid_j=0; grid_j < m; grid_j++){
                grid[grid_i][grid_j] = in.nextInt();
            }
        }
        System.out.println(getBiggestRegion(grid));
    }
}
