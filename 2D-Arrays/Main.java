package jaggedArrays;

public class Main {
	static int loC = 1;
	static int hiC = 20;
	static int randomNum;

	public static void main(String[] args) {
		int[][] array = new int[50][];

		loadArray(array);
		displayArray(array);
	} // end main

	public static void loadArray(int[][] array) {

		for (int i = 0; i < array.length; i++) {
			randomNum = (int) (Math.random() * (hiC - loC + 1) + loC);
			array[i] = new int[randomNum];

			for (int j = 0; j < array[i].length; j++) {
				if (randomNum <= 20) {
					array[i][j] = randomNum++;
				}

			} // end for loop
		} // end for loop

	} // end loadArray

	public static void displayArray(int[][] array) {
		for (int i = 0; i < array.length; i++) {

			for (int j = 0; j < array[i].length; j++) {

				if (array[i][j] != 0)
					System.out.print(array[i][j] + "\t");

			} // end for loop

			System.out.println();
		} // end for loop
	} // end displayArray
} // end class TestClassJagged