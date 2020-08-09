// Equivalent to #include <scanner>
import java.util.Scanner;
// Equivalent to #include <cmath>
import java.lang.Math;

// Every programming language does the same six or seven things:
// 1. I/O (Input and output)
//	cout: System.out.println()
//	cin: java.util.Scanner() scan = new java.util.Scanner(System.in); scan.nextInt();
// 2. Make variables
//	primitives are (mostly) the same
// 3. Do algebra
//	yeah, the same
// 4. Have branches (if statements)
//	the same
// 5. Loops
//	the same
// 6. Functions
	
// 7. Arrays/vectors
// 8. Classes

class HelloWorld {
	static double hypot(double a, double b) {
		return Math.sqrt(a*a+b*b);
	}
	static double bob(double a, double b) {
		if (a > b) return 2*a;
		else return Math.abs(2*b);
	}
	public static void main(String[] args) {
		java.util.Scanner cin = new java.util.Scanner(System.in); // Makes variable that's basically cin
		//System.out.println("Enter how many times you want to say Hello World:");
		System.out.println("Enter a value for side 1:");
		int x = cin.nextInt();
		System.out.println("Enter a value for side 2:");
		int y = cin.nextInt();
		System.out.println("Value of hypotenuse: " + Double.toString(hypot(x, y)));
		
		//if (x < 10) {
		//	for (int i = 0; i < x; i++) {
		//		System.out.println("Hello World!");
		//	}
		//} else if (x == 42) {
		//	System.out.println("Secret!");
		//} else {
		//	int y = 2*x - 3;
		//	System.out.println(Integer.toString(y));
		//}
	}
}
