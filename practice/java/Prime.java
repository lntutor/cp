public class Prime {
	
	public static boolean isPrime(int number) {
		if (number <=1) {
			return false;
		} else if (number <=3) {
			return true;
		} else if (number%2==0) {
			return false;
		} else {
			int sqrt = (int) Math.sqrt(number) + 1;
			int i = 3;
			while (i<sqrt) {
				if (number % i ==0) {
					return false;
				}
				i+=2;
			}
		}
		return true;
	}

}