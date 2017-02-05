/*

Program-1
Jackson Tran
This program will read in rgb values and use functions to flip the image
that the values create vertically, horizontally, and then greyscale the image
1063 Data Structures
Spring 2017
January 3, 2017

*/

#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;

struct rgb {
	int r;
	int g;
	int b;
};

/*
Function name: flipVert
Description: This function will loop through the 2D array and position
each row so that the image will be flipped vertically
Parameters:
rgb** image - The rgb values will be held in this 2D array
int width - Basically the columns of the array
int height - Basically the rows of the array
Returns: void
*/
void flipVert(rgb** image, int width, int height) {
	for (int i = 0; i < height / 2; i++) {
		for (int j = 0; j < width; j++) {
			rgb hi, lo;
			hi = image[i][j];
			lo = image[height - 1 - i][j];
			image[i][j] = lo;
			image[height - 1 - i][j] = hi;
		}
	}
	
}
/*
Function name: flipHorz
Description: This function will loop through the 2D array and position
each column so that the image will be flipped horizontally
Parameters:
rgb** image - The rgb values will be held in this 2D array
int width - Basically the columns of the array
int height - Basically the rows of the array
Returns: void
*/
void flipHorz(rgb** image, int width, int height) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width/2; j++) {
			rgb hi, lo;
			hi = image[i][j];
			lo = image[i][width - 1 - j];
			image[i][j] = lo;
			image[i][width - 1 - j] = hi;
		}
	}
	
}
/*
Function name: greyScale
Description: This function will loop through the 2D array and use a formula
to assign a value to each rgb value to essentially turn the image grey
Parameters:
rgb** image - The rgb values will be held in this 2D array
int width - Basically the columns of the array
int height - Basically the rows of the array
Returns: void
*/
void grayScale(rgb** image, int width, int height) {
	int grayColor;
	for (int i = 0; i < height; i++) {
		for(int j = 0; j < width; j++){
			grayColor = (image[i][j].r + image[i][j].g + image[i][j].b) / 3;
			image[i][j].r = grayColor;
			image[i][j].g = grayColor;
			image[i][j].b = grayColor;
		}

	}
	
}


int main() {
	ifstream ifile;          
	ofstream ofile;
	ifile.open("bot.txt");
	ofile.open("bot2.txt");

	int width;              
	int height;              

	rgb **imgArray;      

	ifile >> width >> height;  

	imgArray = new rgb*[height];   

	for (int i = 0; i<height; i++) {
		imgArray[i] = new rgb[width];
	}

	for (int i = 0; i<height; i++) {
		for (int j = 0; j<width; j++) {
			ifile >> imgArray[i][j].r >> imgArray[i][j].g >> imgArray[i][j].b;
		}
	}

	flipVert(imgArray, width, height);
	flipHorz(imgArray, width, height);
	grayScale(imgArray, width, height);

	ofile << width << " " << height << endl;
	for (int i = 0; i<height; i++) {
		for (int j = 0; j<width; j++) {
			ofile << imgArray[i][j].r << " " << imgArray[i][j].g << " " << imgArray[i][j].b << " ";
		}
		ofile << endl;
	}



	return 0;
}

