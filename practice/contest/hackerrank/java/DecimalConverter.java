public class DecimalConverter {
	int decimal;
	public DecimalConverter(int decimal) {
		this.decimal = decimal;
	}

	public String convertToBinary(int decimal){
		return convertToBase(decimal, 2);	
	}

	public String convertToHexa(int decimal){
		String result = "";
		while(decimal > 0) {
			int rem = decimal % 16;
			decimal /=16;
			String remainder = "";
			switch(rem) {
				case 15:
					remainder = "F";
					break;
				case 14:
					remainder = "E";
					break;
				case 13:
					remainder = "D";
					break;
				case 12:
					remainder = "C";
					break;
				case 11:
					remainder = "B";
					break;
				case 10:
					remainder = "A";
					break;
				default:
					remainder = rem + "";
				break;

			}

			result = remainder + "" + result;
		}
		return result;
	}

	public String convertToOcto(int decimal){
		return convertToBase(decimal, 8);	
	}

	public String convertToBase(int decimal, int base){
		String result = "";
		while(decimal > 0) {
			int rem = decimal % base;
			decimal /=base;
			result = rem + "" + result;
		}
		return result;
	}

	public void printAll(){
		String binary = convertToBinary(decimal);
		System.out.println("Binary of " + decimal + " is " + binary);

		String hexa = convertToHexa(decimal);
		System.out.println("Hexa of " + decimal + " is " + hexa);

		String octo = convertToOcto(decimal);
		System.out.println("Octo of " + decimal + " is " + octo);

	}
}