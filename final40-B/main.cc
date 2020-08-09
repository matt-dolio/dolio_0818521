#include <iostream>
#include <cmath>
#include "/public/colors.h"
#include "/public/read.h"
using namespace std;

const int ROWS = 10, COLS = 10; //We will draw on a 10x10 region of the top left of the screen

/*
   Functions in colors.h
   void setbgcolor(uint8_t R, uint8_t G, uint8_t B);
   void setcolor(uint8_t R, uint8_t G, uint8_t B);
   void resetcolor();
   void movecursor(uint32_t line, uint32_t col);
   void clearscreen();
   */

struct Line {
	//X is a column, y is a row, counting from (0,0) in the top left
	int x_min,y_min,x_max,y_max;
};

//Returns how far off the line point i,j is from l
double dist_from_line(const Line &l,int i, int j) {
	//Compute the distance from each endpoint of the line to the point
	double distance1 = hypot(abs(l.y_min-i),abs(l.x_min-j));
	double distance2 = hypot(abs(l.y_max-i),abs(l.x_max-j));
	//Compute the length of the line
	double distance3 = hypot(abs(l.y_min-l.y_max),abs(l.x_min-l.x_max));
	return abs((distance1+distance2)-distance3);
}

bool do_intersect(const Line &l1, const Line &l2) {
	//See if they're identical
	if (l1.x_min == l2.x_min and l1.x_max == l2.x_max and l1.y_min == l2.y_min and l1.y_max == l2.y_max)
		return true;

	//From https://stackoverflow.com/questions/35473936/find-whether-two-line-segments-intersect-or-not-in-c
	float ax = l1.x_max - l1.x_min;     // direction of line a
	float ay = l1.y_max - l1.y_min;     // ax and ay as above

	float bx = l2.x_min - l2.x_max;     // direction of line b, reversed
	float by = l2.y_min - l2.y_max;     // really -by and -by as above

	float dx = l2.x_min - l1.x_min;   // right-hand side
	float dy = l2.y_min - l1.y_min;

	float det = ax * by - ay * bx;

	if (det == 0) return false;

	float r = (dx * by - dy * bx) / det;
	float s = (ax * dy - ay * dx) / det;

	return !(r < 0 || r > 1 || s < 0 || s > 1);
}

//Draw a sort of inaccurate rendering of the lines
void render(const Line &l, bool line1) {
	//Line1 gets rendered as blue, Line2 as red
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			double dist = dist_from_line(l,i,j);
			if (dist < 0.01) { //Right on line
				if (line1) setbgcolor(0,0,255);
				else setbgcolor(255,0,0);
				movecursor(i,j);
				cerr << " ";
			}
			else if (dist < 0.1) { //A bit off line
				if (line1) setbgcolor(0,0,128);
				else setbgcolor(128,0,0);
				movecursor(i,j);
				cerr << " ";
			}
			else if (dist < 0.2) { //Well off line
				if (line1) setbgcolor(0,0,50);
				else setbgcolor(50,0,0);
				movecursor(i,j);
				cerr << " ";
			}
		}
	}
	resetcolor();
}

int main() {
	Line first, second;
	clearscreen();
	movecursor(10,0); //Move the text to output below where the lines will appear
	cout << "Reading in the first line. (0,0) is the top left of the screen, (9,9) the bottom right.\n";
	first.x_min = read<int>("Please enter x_min for the first line:\n");
	first.x_max = read<int>("Please enter x_max for the first line:\n");
	first.y_min = read<int>("Please enter y_min for the first line:\n");
	first.y_max = read<int>("Please enter y_max for the first line:\n");
	render(first,true);
	movecursor(19,0); //Move the cursor back down after rendering
	second.x_min = read<int>("Please enter x_min for the second line:\n");
	second.x_max = read<int>("Please enter x_max for the second line:\n");
	second.y_min = read<int>("Please enter y_min for the second line:\n");
	second.y_max = read<int>("Please enter y_max for the second line:\n");
	render(second,false);
	movecursor(26,0); //Move the cursor back down after rendering
	cout << "Do the lines intersect? Survey says: " << boolalpha << do_intersect(first,second) << endl;
}

/*
   bool do_intersect(const Line &l1, const Line &l2) {
//See if they're identical
if (l1.x_min == l2.x_min and l1.x_max == l2.x_max and l1.y_min == l2.y_min and l1.y_max == l2.y_max)
return true;
struct Point { double x,y; };
Point a = {double(l1.x_max-l1.x_min),double(l1.y_max-l1.y_min)}; //Turn it into a vector pointing out of the origin
movecursor(28,0);
cout << a.x << " " << a.y << endl;
double len = hypot(a.x,a.y);
a.x /= len;
a.y /= len;
Point b = {double(l2.x_min-l1.x_min),double(l2.y_min-l1.y_min)}; //Make a vector from l1 min to l2 min
len = hypot(b.x,b.y);
b.x /= len;
b.y /= len;
Point c = {double(l2.x_max-l1.x_min),double(l2.y_max-l1.y_min)}; //Make a vector from l1 min to l2 max
len = hypot(c.x,c.y);
c.x /= len;
c.y /= len;
//Dot product a and b
double dot_product1 = a.x*b.x + a.y*b.y;
double dot_product2 = a.x*c.x + a.y*c.y;
cout << a.x << " " << a.y << endl;
cout << b.x << " " << b.y << endl;
cout << c.x << " " << c.y << endl;
cout << dot_product1 << " " << dot_product2 << endl;
//There is an intersection if the dot product is positive exactly once
if (dot_product1 >= 0 and dot_product2 <= 0) return true;
if (dot_product1 <= 0 and dot_product2 >= 0) return true;
return false;
}
*/
