import java.util.Scanner;
import java.lang.Math;
import java.util.Vector;
import java.util.Collections;

public class Rainfall {
	public static void main(String[] args) {
		java.util.Scanner cin = new java.util.Scanner(System.in); // Allow us to read input;
		Vector<Integer> vec = new Vector<Integer>();
		System.out.println("Welcome to Java Rainfall!");
		System.out.println("Please enter daily rainfall data (-1 to quit):");
		int x = 0;
		try {
			x = cin.nextInt(); // Read initial value of X
		}
		catch (Exception e) {
			System.out.println("BAD INPUT!");
			System.exit(0);
		}
		int max = Integer.MIN_VALUE;
		int min = Integer.MAX_VALUE;
		int count = 0;
		while (x != -1) {
			if (x > -1) {
				vec.addElement(x); // Add X to vector if greater than -1, otherwise ignore the value
				count++;
				if (x > max) max = x;
				if (x < min) min = x;
			}

			try {
				x = cin.nextInt(); // Read initial value of X
			}
			catch (Exception e) {
				System.out.println("BAD INPUT!");
				System.exit(0);
			}
		}	

		// Debugging lines, comment for debug
		//		System.out.println("Count of real nums: " + Integer.toString(count));
		//		System.out.print("Included real nums: ");
		//		for (int i = 0; i < vec.size(); i++) System.out.print(Integer.toString(vec.elementAt(i)) + " ");
		//		System.out.println("\nMax num: " + Integer.toString(max) + " Min num: " + Integer.toString(min));


		System.out.println("1) Average daily rainfall\n2) Average rainfall on rainy days\n3) Count of days that had rain\n4) Maximum rainfall\n5) Top 5 days of rain\n6) Quit");
		int y = 0;
		try {
			y = cin.nextInt(); // Read initial value of X
		}
		catch (Exception e) {
			System.out.println("BAD INPUT!");
			System.exit(0);
		}
		while (y != 6) {

			/* OPTION 1 */
			if (y == 1) {
				int sum = 0;
				if (vec.size() == 0) System.out.println("NO DATA");
				if (count == 0) System.out.println("NO DATA");
				else {
					for (int i = 0; i < vec.size(); i++) {
						sum += vec.elementAt(i);
					}
					// System.out.println("Average daily rainfall: " + Integer.toString(sum / count));
					System.out.println(Integer.toString(sum / count));
				}
			}

			/* OPTION 2 */
			else if (y == 2) {
				int sum = 0, rainyDays = 0;
				if (vec.size() == 0) System.out.println("NO DATA");
				else {
					for (int i = 0; i < vec.size(); i++) {
						if (vec.elementAt(i) > 0) {
							sum += vec.elementAt(i);
							rainyDays++;
						}
					}
					if (rainyDays == 0) System.out.println("NO DATA");
					//else System.out.println("Average rainfall on rainy days: " + Integer.toString(sum / rainyDays));
					else System.out.println(Integer.toString(sum / rainyDays));
				}
			}

			/* OPTION 3 */
			else if (y == 3) {
				int rainyDays = 0;
				for (int i = 0; i < vec.size(); i++) {
					if (vec.elementAt(i) > 0) rainyDays++;
				}
				//System.out.println("Count of days that had rain: " + Integer.toString(rainyDays));
				System.out.println(Integer.toString(rainyDays));
			}

			/* OPTION 4 */
			else if (y == 4) {
				//if (max > 0) System.out.println("Maximum rainfall: " + Integer.toString(max));
				if (max > 0) System.out.println(Integer.toString(max));
				else System.out.println("NO DATA");
			}

			/* OPTION 5 */
			else if (y == 5) {
				if (vec.size() == 0) System.out.println("NO DATA");
				else if (vec.size() < 5) {
					Collections.sort(vec, Collections.reverseOrder());
					Vector<Integer> temp = new Vector<Integer>();
					for (int i = 0; i < vec.size(); i++) {
						if (vec.elementAt(i) != 0) temp.addElement(vec.elementAt(i));
					}
					if (temp.size() == 0) System.out.println("NO DATA");
					else {
						if (temp.size() < 5) {
							for (int i = 0; i < temp.size(); i++) System.out.println(temp.elementAt(i));
						}
						else {
							for (int i = 0; i < 5; i++) System.out.println(temp.elementAt(i));
						}
					}
				}
				else {
					Collections.sort(vec, Collections.reverseOrder());
					for (int i = 0; i < 5; i++) {
						System.out.println(Integer.toString(vec.elementAt(i)));
					}
				}
			}

			System.out.println("1) Average daily rainfall\n2) Average rainfall on rainy days\n3) Count of days that had rain\n4) Maximum rainfall\n5) Top 5 days of rain\n6) Quit");
			try {
				y = cin.nextInt(); // Read initial value of X
			}
			catch (Exception e) {
				System.out.println("BAD INPUT!");
				System.exit(0);
			}
		}
	}
}
