#define cimg_display 0
#include "CImg.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
using namespace cimg_library;
using namespace std;

//This will dump the contents of an image file to the screen
//Useful for debugging your code
void print_image(unsigned char in[], int width, int height) {
	for (int i = 0; i < width * height * 3; i++)
		cout << (unsigned int) in[i] << endl;
}

// Due to some differences in source files, I will be adding some necessary adjustments.
int width = 0;
int height = 0;
int stride = 0; // Width * Height

int b_width = 0;
int b_height = 0;
int b_stride = 0;

//These are helper functions that will return the red, green, or blue value at
// any given location, or allow you to set the value there as well.
//We're accessing a 1D array as if it was a 3D array
int R(int i, int j) {
	return j * width + i;
}
int G(int i, int j) {
	return stride + j * width + i;
}
int B(int i, int j) {
	return stride + stride + j * width + i;
}

//image time, 32x32
int RW(int i, int j) {
	return j * b_width + i;
}
int GW(int i, int j) {
	return b_stride + j * b_width + i;
}
int BW(int i, int j) {
	return b_stride + b_stride + j * b_width + i;
}


void set_rekt(unsigned char out[], unsigned char img[], int x_min, int y_min, int x_max, int y_max) {
	for (int i = x_min; i <= x_max; i++) {
		for (int j = y_min; j <= y_max; j++) {
			int img_r = img[RW(i - x_min, j - y_min)];
			int img_g = img[GW(i - x_min, j - y_min)];
			int img_b =  img[BW(i - x_min, j - y_min)];
			if (img_r != 0 or img_g != 0 or img_b != 0) {
				out[R(i, j)] = img_r;
				out[G(i, j)] = img_g;
				out[B(i, j)] = img_b;
			}
		}
	}
}

// The purpling!!! Dolio says it's time to mult red by 3, blue by 2, and don't touch green! Nerd!
void the_purpling(unsigned char in[], unsigned char out[], int width, int height) {
	stride = width * height;
	//Note: i is the x coordinate, j is the y coordinate
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) { //At each pixel...
			float temp_r = in[R(i, j)] * 1.25;
			if (temp_r > 255) temp_r = 255;
			out[R(i, j)] = (int)round(temp_r);  //Divide the value of red by half...
			float temp_g = in[G(i, j)] * 0.9;
			if (temp_g > 255) temp_g = 255;
			out[G(i, j)] = (int)round(temp_g);  //Divide the value of green by half...
			float temp_b = in[B(i, j)] * 1.25;
			if (temp_b > 255) temp_b = 255;
			out[B(i, j)] = (int)round(temp_b);  //Divide the value of blue by half...
		}
	}
	return;
}

void the_marking(unsigned char in[], unsigned char out[], int width, int height) {
	// Just setting the output image to the input
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) { //At each pixel...
			out[R(i, j)] = in[R(i, j)];
			out[G(i, j)] = in[G(i, j)];
			out[B(i, j)] = in[B(i, j)];
		}
	}
	// Watermark
	CImg<unsigned char> block("question.png");
	b_height = block.height();
	b_width = block.width();
	b_stride = b_height * b_width;
	set_rekt(out, block, (int)round(width*0.6), 200, b_width + (int)round(width*0.6), b_height + 200);
	// I did hashtag after processing :shrug:
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
	width = image.width();
	height = image.height();
	stride = width * height;
	CImg<unsigned char> image2(image.width(), image.height(), 1, 3, 0);
	CImg<unsigned char> image3(image.width(), image.height(), 1, 3, 0);
	clock_t end_time = clock();
	cerr << "Image load time: " << double (end_time - start_time) / CLOCKS_PER_SEC << " secs\n";

	//Uncomment this next line to get debugging on the image data loaded
	//print_image(image,image.width(),image.height());

	//PHASE 2 - Purplize the image
	start_time = clock();
	the_marking(image, image2, image.width(), image.height());
	end_time = clock();
	cerr << "Marking time: " << double (end_time - start_time) / CLOCKS_PER_SEC << " secs\n";

	//PHASE 3 - Sepia tone the image
	start_time = clock();
	the_purpling(image2, image3, image.width(), image.height());
	unsigned char black[] = {0, 0, 0};
	unsigned char purple[] = {255, 0, 255};
	image3.draw_text(image.width() / 2, 5, "#mmmpurple", purple);
	end_time = clock();
	cerr << "Purpling time: " << double (end_time - start_time) / CLOCKS_PER_SEC << " secs\n";

	//PHASE 3 - Write the image
	start_time = clock();
	//Uncomment this if you want to see the darkened image, and in .PNG format
	//image.save_jpeg("output1.jpg", 100);
	//image2.save_jpeg("output2.jpg", 100);
	image3.save_jpeg("output.jpg", 100);
	//sepia_image.save_jpeg ("output.jpg", 50); //50% quality
	end_time = clock();
	cerr << "Image write time: " << double (end_time - start_time) / CLOCKS_PER_SEC << " secs\n";
}

