import java.util.Random;

public class ArrayShuffle {

	public static int [] shuffle (int [] array) {
		int length = array.length;
		Random rand = new Random(); 

		while(length>0) {
			length--;
			//System.out.println("length " + length);
			int index = rand.nextInt(length + 1);
			int tmp = array[index];
			array[index] = array[length];
			array[length] = tmp;
		}
		return array;
	}
}