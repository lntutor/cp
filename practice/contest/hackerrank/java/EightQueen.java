public class EightQueen {

	private final int COUNT = 8;
	private int [][] matrix;
	private int numOfResult = 0;
	
	public EightQueen(){
		matrix = new int[8][8];
		numOfResult = 0;
	}

	private void printResult() {
		numOfResult++;
		System.out.println("Result " + numOfResult + " :");
		printArray();
	}

	private void printArray(){
		System.out.println("**********************");
 		for (int i = 0; i < COUNT; i++) {
 			for (int j = 0; j < COUNT; j++) {
 				System.out.print(matrix[i][j]);
 			}
 			System.out.println("");
 		}
		System.out.println("**********************");
	}

	private boolean check(int row, int col) {

		int i, j;
		// can not be the same column
		i = row - 1;
		while (i >=0) {
			if(matrix[i][col] == 1) {
				return false;
			}
			i--;
		}

		// can not be the same diagnal
		i = row - 1;
		j = col - 1;
		while (i >= 0 && j >= 0) {
			if (matrix[i][j] == 1) {
				return false;
			}
			i--;
			j--;
		}

		i = row - 1;
		j = col + 1;
		while (i >= 0 && j < COUNT) {
			if (matrix[i][j] == 1) {
				return false;
			}
			i--;
			j++;
		}

		return true;
	}

	public void solve(int row) {

		for(int i = 0; i <COUNT; i++){// try on all columns
			matrix[row][i] = 1;
			if (check(row, i)) {
				if (row == COUNT - 1) {
					printResult();
				} else {
					solve(row+1);
				}
			}
			matrix[row][i] = 0;//roll back
		}
	}
}