#define cimg_display 0
#include "CImg.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace cimg_library;
using namespace std;

//This will dump the contents of an image file to the screen
//Useful for debugging your code
void print_image(unsigned char in[], int width, int height) {
	for (int i = 0; i < width * height * 3; i++)
		cout << (unsigned int) in[i] << endl;
}

//Globals for our current image
//FIXME: You will need to make a second set for a watermark image if you use it
int width = 0;
int height = 0;
int stride = 0; //width*height

//These are helper functions that will return the red, green, or blue value at
// any given location, or allow you to set the value there as well.
//We're accessing a 1D array as if it was a 3D array

//FIXME: You will need to make a second set for a watermark image if you do it
int R(int i, int j) {
	return j * width + i;
}
int G(int i, int j) {
	return stride + j * width + i;
}
int B(int i, int j) {
	return stride + stride + j * width + i;
}

void bandw(unsigned char in[], unsigned char out[], unsigned char threshold) {
	//Note: i is the x coordinate, j is the y coordinate
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) { //At each pixel...
			//If you don't convert to an int, you will OVERFLOW
			//Unsigned chars hold 0 to 255. 
			//Black is (0,0,0), White is (255,255,255) Red is (255,0,0) Blue is (0,0,255), Green is (0,255,0)
			//Purple (255,0,255)
			//I convert to an int so that we have 2 billion numbers, not just 255
			int sum = int(in[R(i, j)]) + in[G(i, j)] + in[B(i, j)];
			int avg = sum / 3;
			if (avg > threshold) { //If the average is over the threshold
				out[R(i, j)] = 255; //Set the pixel to white
				out[G(i, j)] = 255;
				out[B(i, j)] = 255;
			} else {
				out[R(i, j)] = 0; //Otherwise set the pixel to black
				out[G(i, j)] = 0;
				out[B(i, j)] = 0;
			}
		}
	}
}

void usage() {
	cout << "Error: this program needs to be called with a command line parameter indicating what file to open.\n";
	cout << "For example, a.out kyoto.jpg\n";
	exit(1);
}

int main(int argc, char **argv) {
	if (argc != 2) usage(); //Check command line parameters

	//PHASE 1 - Load the image
	clock_t start_time = clock();
	CImg<unsigned char> image(argv[1]);
	//FIXME: change this if you load two images of different sizes
	width = image.width(); //Set globals.
	height = image.height();
	stride = width * height;
	CImg<unsigned char> image2(image.width(), image.height(), 1, 3, 0);
	CImgList<unsigned char> gif(0, image.width(), image.height(), 1, 3);
	clock_t end_time = clock();
	cerr << "Image load time: " << double (end_time - start_time) / CLOCKS_PER_SEC << " secs\n";

	//PHASE 2 - Darken the image
	start_time = clock();
	for (int i = 0; i < 512; i = i + 20) {
		int thresh = i;
		if (thresh >= 256) thresh = 512 - thresh;
		bandw(image, image2, thresh);
		gif.push_back(image2);
	}
	end_time = clock();
	cerr << "Bandw time: " << double (end_time - start_time) / CLOCKS_PER_SEC << " secs\n";

	//PHASE 3 - Write the image
	start_time = clock();
	string filename = argv[1];
	filename = filename + ".gif";
	gif.save_gif_external(filename.c_str(), 25, 0); //Animated gif
	end_time = clock();
	cerr << "Image write time: " << double (end_time - start_time) / CLOCKS_PER_SEC << " secs\n";
}

