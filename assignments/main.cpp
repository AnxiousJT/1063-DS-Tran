
#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;

struct rgb {
	int r;
	int g;
	int b;
};
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
	//flipHorz(imgArray, width, height);
	//grayScale(imgArray, width, height);

	ofile << width << " " << height << endl;
	for (int i = 0; i<height; i++) {
		for (int j = 0; j<width; j++) {
			ofile << imgArray[i][j].r << " " << imgArray[i][j].g << " " << imgArray[i][j].b << " ";
		}
		ofile << endl;
	}



	return 0;
}

