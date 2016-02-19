//cal fibo number using dynamic programming

public class Fibo {
	private int [] array;
	private int n;

	public Fibo(int n) {
		this.n = n;
		this.array = new int[n];
	}

	public void printFibo(){
		System.out.println(fib(n-1));
	}

	private int fib(int n) { // n-th Fibo number
		if (n<=1) {
			array[n] = 1;
		} else if (array[n] == 0 && array[n-2] != 0) {
			array[n] = array[n-1] + array[n-2];
		} else {
			array[n] = fib(n-1) + fib(n-2);
		}
		return array[n];
	}

}