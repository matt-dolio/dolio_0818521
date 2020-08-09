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

int maximum(int a, int b, int c)
{
	int max = ( a < b ) ? b : a;
	return ( ( max < c ) ? c : max );
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

/*
   float percentage = float(i) / width;
   unsigned int new_r = (unsigned int)in[R(i, j)] + (percentage * 255);   //Divide the value of red by half

   if (new_r > 255) new_r = 255; //Saturate
   */
void set_rekt(unsigned char out[], int x_min, int y_min, int x_max, int y_max) {
	for (int i = x_min; i <= x_max; i++) {
		for (int j = y_min; j <= y_max; j++) {
			out[R(i, j)] = 255;
			out[G(i, j)] = 0;
			out[B(i, j)] = 0;
		}
	}
}

//Darken by 50%
void filter1(unsigned char in[], unsigned char out[]) {
	//Note: i is the x coordinate, j is the y coordinate
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) { //At each pixel...
			out[R(i, j)] = in[R(i, j)] / 2;
			out[G(i, j)] = in[G(i, j)] / 2;
			out[B(i, j)] = in[B(i, j)] / 2;
		}
	}
	//set_rekt(out, 200, 10, 210, 100); //Draw a rectangle on the image

	return;
}

//This filter is a placeholder - it just copies the input image to the output image
void filter2(unsigned char *in, unsigned char *out) {
	const int stride = width * height;
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			out[R(i, j)] = in[R(i, j)] * 1;
			out[G(i, j)] = in[G(i, j)] * 1;
			out[B(i, j)] = in[B(i, j)] * 1;
		}
	}
	return;
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
	CImg<unsigned char> image2(image.width(), image.height(), 1, 3, 0); //Holds result after 1st filter
	CImg<unsigned char> image3(image.width(), image.height(), 1, 3, 0); //Holds result after 2nd filter
	clock_t end_time = clock();
	cerr << "Image load time: " << double (end_time - start_time) / CLOCKS_PER_SEC << " secs\n";

	//Uncomment this next line to get debugging on the image data loaded
	//print_image(image,image.width(),image.height());

	//PHASE 2 - Darken the image
	start_time = clock();
	filter1(image, image2); //Read from image, write to image2
	end_time = clock();
	cerr << "Filter 1 time: " << double (end_time - start_time) / CLOCKS_PER_SEC << " secs\n";

	//PHASE 3 - Sepia tone the image
	start_time = clock();
	//filter2(image, image3); //Sepia tone the original image
	filter2(image2, image3); //Sepia tone the darkened image
	end_time = clock();
	cerr << "Filter 2 time: " << double (end_time - start_time) / CLOCKS_PER_SEC << " secs\n";

	//PHASE 3 - Write the image
	start_time = clock();
	//Write the darkened image to a PNG file - high quality, huge size
	//darkimage.save_png("darken.png");
	image2.save_jpeg("output.jpg", 50); //Output result after filter 1
	image3.save_jpeg("output2.jpg", 50); //Output result after filter 2
	//Write the sepia toned file to a JPEG with 50% quality
	end_time = clock();
	cerr << "Image write time: " << double (end_time - start_time) / CLOCKS_PER_SEC << " secs\n";
}

