public class Permutation {

	private int [] array  = {1,2,3,4,5,6,7};

	public Permutation(int[] array) {
		this.array = array;
	}

	public void setArray(int []array) {
		this. array = array;  
	}

	public void swap(int i, int j) {
		int tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
	}

	public void permutate(int left, int right) {
		if (left == right) {
			Utils.printArray(array);
		} else {
			for (int i = left; i <= right; i++) {
				swap(left, i);
				permutate(left + 1, right);
				swap(left, i);
			}
		}
	}

	public void printPermutate(){
		permutate(0, array.length - 1);
	}

}