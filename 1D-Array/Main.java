import java.util.*;

public class Main {

	static Scanner input = new Scanner(System.in);
	Random rand = new Random();
	int randNumbers;

	public static void main(String[] args) {
		int size;
		int[] myArray;

		System.out.print("Enter the size of the array here: ");
		size = input.nextInt();

		while (size < 0) {
			System.out.println("The size of the array must be above 0!");
			System.out.print("\nEnter the size of the array here: ");
			size = input.nextInt();
		} // end while loop

		if (size > 0) {

			myArray = new int[size];

			Methods.loadArray(myArray);
			Methods.displayArray(myArray);
			Methods.calcArrayValues(myArray);
			Methods.searchInArray(myArray);

		} // end if statement

	}// end main

}// end class ArraysAssignment
