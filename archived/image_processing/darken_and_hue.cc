#define cimg_display 0
#include "CImg.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#define NUM_COLOR 39
#define ERROR 75
#define THRESH 75
using namespace cimg_library;
using namespace std;

typedef struct color{
	int count, red, green, blue;
} color;

vector<color*>vec_color;

void make_color (int red, int green, int blue){
	color* temp = (color*)malloc(sizeof(color));
	temp->count = 1;
	temp->red = red;
	temp->green = green;
	temp->blue = blue;
	vec_color.push_back(temp);

}

bool within_er (int r1, int r2, int g1, int g2, int b1, int b2, int error){
				int distcolor_r = (r1 - r2); 
				int distcolor_g = (g1 - g2);
				int distcolor_b = (b1 - b2);
				distcolor_r = distcolor_r >= 0 ? distcolor_r : -distcolor_r;			
				distcolor_g = distcolor_g >= 0 ? distcolor_g : -distcolor_g;
				distcolor_b = distcolor_b >= 0 ? distcolor_b : -distcolor_b;
				int distcolor = (distcolor_r + distcolor_g + distcolor_b);
				return distcolor < error;
}
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
//Pickle Rick 101x128
int RW(int i, int j) {
    return j * 101 + i;
}
int GW(int i, int j) {
    return 12928 + j * 101 + i;
}
int BW(int i, int j) {
    return 12928 + 12928 + j * 101 + i;
}


/*
   float percentage = float(i) / width;
   unsigned int new_r = (unsigned int)in[R(i, j)] + (percentage * 255);   //Divide the value of red by half

   if (new_r > 255) new_r = 255; //Saturate
   */
void set_rekt(unsigned char out[], unsigned char rick[], int x_min, int y_min, int x_max, int y_max) {
	for (int i = x_min; i <= x_max; i++) {
		for (int j = y_min; j <= y_max; j++) {
			int rick_r = rick[RW(i-x_min,j-y_min)];
			int rick_g = rick[GW(i-x_min,j-y_min)];
			int rick_b =  rick[BW(i-x_min,j-y_min)];
			if (rick_r != 0 || rick_g != 0 || rick_b != 0) { 
				out[R(i, j)] = rick[RW(i-x_min,j-y_min)];
				out[G(i, j)] = rick[GW(i-x_min,j-y_min)];
				out[B(i, j)] = rick[BW(i-x_min,j-y_min)];
			}
		}
	}
}


void filter1 (unsigned char in[], unsigned char out[]) {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			int red = (in[R(i,j)]);// / 15) * 15;
			int green = (in[G(i,j)]);// / 15) * 15;
			int blue = (in[B(i,j)]);// / 15) * 15;
bool invec = false;
			for (auto c:vec_color){
				if (within_er(red,c->red,green,c->green,blue,c->blue,ERROR)) {
					invec = true;
					c->count+=1;
					break;
					}
				}
			if (invec == false) {
				make_color(red, green, blue);
				
			}
		}
	}
	CImg<unsigned char> rick("picklerick.png");
	int r_height = rick.height();
	int r_width = rick.width();
	set_rekt(in, rick, 25, 150, r_width + 25, r_height + 150 );
	vector<color*>lastcolor;
	for (int i = 0; i < NUM_COLOR; i++) {
		auto it = vec_color.begin();
		int lmao = 0;
		color* temp;
		for (int i = 0; i < vec_color.size(); i++){
			if (vec_color.at(i)-> count >= lmao){
				lmao = vec_color.at(i)->count;
				temp = vec_color.at(i);
				vec_color.erase(vec_color.begin()+i); 
			}
		}
		lastcolor.push_back(temp);
	}

	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			int r = in[R(i,j)];
			int g = in[G(i,j)];
			int b = in[B(i,j)];
			int r2, g2, b2;
			int prevcolor = 1000;
			for (auto c:lastcolor) {
				int distcolor_r = (c->red - r); 
				int distcolor_g = (c->green - g);
				int distcolor_b = (c->blue - b);
				distcolor_r = distcolor_r >= 0 ? distcolor_r : -distcolor_r;			
				distcolor_g = distcolor_g >= 0 ? distcolor_g : -distcolor_g;
				distcolor_b = distcolor_b >= 0 ? distcolor_b : -distcolor_b;
				distcolor_r = r > fmax(g, b) ? distcolor_r : distcolor_r;
				distcolor_g = g > fmax(r , b) ? distcolor_g : distcolor_g;		
				distcolor_b = b > fmax(g , r) ? distcolor_b : distcolor_b;
				int distcolor = (distcolor_r + distcolor_g + distcolor_b);
				//distcolor = distcolor >= 0 ? distcolor : -distcolor;
				if (distcolor < prevcolor ){
					r2 = c->red;
					g2 = c->green;
					b2 = c->blue;
					prevcolor = distcolor;
					
				}
			}
					out[R(i,j)] = r2;
					out[G(i,j)] = g2;
					out[B(i,j)] = b2;
		}
	}
/*	int preR = 0, preG = 0, preB = 0;
	for (int i = 0; i < width; i++) {
		preR = out[R(i,0)];
		preG = out[G(i,0)];
		preB = out[B(i,0)];
		for (int j = 0; j < height; j++) {
			int	r = out[R(i,j)];
			int	g = out[G(i,j)];
			int	b = out[B(i,j)];		
			if (((r < preR-THRESH ||  r > preR+THRESH) || 
				((b < preB - THRESH) || ( b > preB + THRESH)) || 
				((g < preG-THRESH) || (g > preG+THRESH))))
			{
				preR = out[R(i,j)];
				preG = out[G(i,j)];
				preB = out[B(i,j)];
				out[R(i,j)] = 0;
				out[G(i,j)] = 0;
				out[B(i,j)] = 0;
			}
		}
	}*/
}/*
//Darken by 50%
void filter1(unsigned char in[], unsigned char out[]) {
	//Note: i is the x coordinate, j is the y coordinate
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) { //At each pixel...
			out[R(i, j)] = (in[R(i, j)] / 100) * 105;
			out[G(i, j)] = (in[G(i, j)] / 100) * 105;
			out[B(i, j)] = (in[B(i, j)] / 100) * 105;
		}
	}//
	int preR = 0, preG = 0, preB = 0;
	for (int i = 0; i < width; i++) {
		preR = out[R(i,0)];
		preG = out[G(i,0)];
		preB = out[B(i,0)];
		for (int j = 0; j < height; j++) {
			if (out[R(i,j)] != preR || out[G(i,j)] != preG || out[B(i,j)] != preB){
				preR = out[R(i,j)];
				preG = out[G(i,j)];
				preB = out[B(i,j)];
				out[R(i,j)] = 0;
				out[G(i,j)] = 0;
				out[B(i,j)] = 0;
			}
		}
	}	
}*/
//This filter raises red (saturating so it doesn't overflow) and lowers G&B by 10%
void filter2(unsigned char *in, unsigned char *out) {
	const int stride = width * height;
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			int r =  in[R(i, j)];
			if (r > 255) r = 255;
			out[R(i, j)] = r;
			out[G(i, j)] = in[G(i, j)];
			out[B(i, j)] = in[B(i, j)];
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
	unsigned char black[] = {0,0,0};
	unsigned char white[] = {255, 255, 255};
	image3.draw_text(5,5,"#Teehee",black);
	end_time = clock();
	cerr << "Filter 2 time: " << double (end_time - start_time) / CLOCKS_PER_SEC << " secs\n";

	//PHASE 3 - Write the image
	start_time = clock();
	//Write the darkened image to a PNG file - high quality, huge size
	//darkimage.save_png("darken.png");
	image2.save_jpeg("output.jpg", 100); //Output result after filter 1
	image3.save_jpeg("output2.jpg", 100); //Output result after filter 2
	//Write the sepia toned file to a JPEG with 50% quality
	end_time = clock();
	cerr << "Image write time: " << double (end_time - start_time) / CLOCKS_PER_SEC << " secs\n";
}

