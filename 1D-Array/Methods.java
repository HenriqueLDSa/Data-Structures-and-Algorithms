import java.util.*;

public class Methods {

	public static void loadArray(int[] myArray) {

		for (int i = 1; i <= myArray.length; i++) {

			ArraysAssignment var = new ArraysAssignment(); // allows the use of variables from other classes

			var.randNumbers = var.rand.nextInt(100) + 1; // gets random number between 1 and 100

			myArray[i - 1] = var.randNumbers; // populates the array with the random numbers

		} // end for loop

		Arrays.sort(myArray);

	}// end loadArray

	public static void displayArray(int[] myArray) {
		int[] frequency = new int[myArray.length];
		int i, j, count;
		
		System.out.println("\nThe elements in the array are:");

		for (i = 0; i < myArray.length; i++) {
//			System.out.println(i + ". " + myArray[i - 1]); // prints the position and its value
			frequency[i] = 1;

		} // end for loop
		
		for (i = 0; i < myArray.length; i++) {
			count = 1;
			
			for(j = i + 1; j < myArray.length; j++) {
				if(myArray[i] == myArray[j]) {
					count++;
					frequency[j] = 0;
				} // end if statement
				
			} // end for loop
			if(frequency[i] != 0) {
				frequency[i] = count;
			}
			
		} // end for loop
		
		for (i = 0; i < myArray.length; i++) {
			System.out.printf(myArray[i] + " (displayed %d times)\n", frequency[i]); // prints the position and its value

		} // end for loop
	} // end displayArray

	public static void calcArrayValues(int[] myArray) {
		int smallest = myArray[0];
		int largest = myArray[0];
		int total = 0;
		double average;

		for (int i = 1; i <= myArray.length; i++) {
			if (myArray[i - 1] < smallest)
				smallest = myArray[i - 1]; // finds the smallest value in array
			if (myArray[i - 1] > largest)
				largest = myArray[i - 1]; // finds the smallest value in array

		} // end for loop

		for (int i : myArray) {
			total += i;
		} // end enhanced for loop

		average = total / myArray.length;

		System.out.printf("\nThe smallest value in the array is: %d", smallest);
		System.out.printf("\nThe largest value in the array is: %d", largest);
		System.out.printf("\nThe average of values in the array is: %.1f\n", average);

	}// end calcArrayValues

	public static void searchInArray(int[] myArray) {
		int value;
		int index;

		System.out.print("\nEnter the number you want to look for in the array: ");
		value = ArraysAssignment.input.nextInt();

		index = Arrays.binarySearch(myArray, value);

		if (index >= 0) {
			System.out.printf("The value %d is contained in the array, its index is %d", value, index);
		} // end if statement
		else {
			System.out.println("Value was not found in the array!");
		} // end else statement

	} // end searchInArray

}// end class Methods
