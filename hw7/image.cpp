/*
image.cpp
created on 3/26/16
by Farhan Zaki,  James le, Seymour Lubbers
*/
#include <iostream>
#include "Complex.h"
#include <stdio.h>

#include <stdlib.h>

#include <string.h>
using namespace std;

#define HEIGHT 500
#define WIDTH  500
#define X_START -1.5
#define X_END    0.5
#define Y_START -1.0
#define Y_END    1.0

/*** 
Function to write 2d arrays of RGB values into a bitmap image
pre-condition :	red, green, and blue are integer 2d arrays (of size HEIGHT x WIDTH) with colors for each pixel
post-condition: writes a file called img.bmp with the image in the array
Adapted from http://stackoverflow.com/questions/2654480/writing-bmp-image-in-pure-c-c-without-other-libraries
***/
void writeBMP(int red[HEIGHT][WIDTH], int green[HEIGHT][WIDTH], int blue[HEIGHT][WIDTH])
{
    int r, g, b, x, y, area = HEIGHT * WIDTH;
    FILE *f;
    unsigned char *img = NULL;
    int filesize = 54 + 3 * area;  
    if( img )
	free( img );
    img = (unsigned char *)malloc(3*area);
    memset(img, 0, 3*area * sizeof(unsigned char));
    
    for(int i = 0; i < WIDTH; i++)
    {
	for(int j = 0; j < HEIGHT; j++)
	{
	    x=i; y=(HEIGHT-1)-j;
	    r = red[i][j];
	    g = green[i][j];
	    b = blue[i][j];
	    if (r > 255) r=255;
	    if (g > 255) g=255;
	    if (b > 255) b=255;
	    img[(x+y*WIDTH)*3+2] = (unsigned char)(r);
	    img[(x+y*WIDTH)*3+1] = (unsigned char)(g);
	    img[(x+y*WIDTH)*3+0] = (unsigned char)(b);
	}
    }
    
    unsigned char bmpfileheader[14] = {'B','M', 0,0,0,0, 0,0, 0,0, 54,0,0,0};
    unsigned char bmpinfoheader[40] = {40,0,0,0, 0,0,0,0, 0,0,0,0, 1,0, 24,0};
    unsigned char bmppad[3] = {0,0,0};
    
    bmpfileheader[ 2] = (unsigned char)(filesize    );
    bmpfileheader[ 3] = (unsigned char)(filesize>> 8);
    bmpfileheader[ 4] = (unsigned char)(filesize>>16);
    bmpfileheader[ 5] = (unsigned char)(filesize>>24);
    
    bmpinfoheader[ 4] = (unsigned char)(WIDTH    );
    bmpinfoheader[ 5] = (unsigned char)(WIDTH>> 8);
    bmpinfoheader[ 6] = (unsigned char)(WIDTH>>16);
    bmpinfoheader[ 7] = (unsigned char)(WIDTH>>24);
    bmpinfoheader[ 8] = (unsigned char)(HEIGHT   );
    bmpinfoheader[ 9] = (unsigned char)(HEIGHT>> 8);
    bmpinfoheader[10] = (unsigned char)(HEIGHT>>16);
    bmpinfoheader[11] = (unsigned char)(HEIGHT>>24);
    
    f = fopen("img.bmp","wb");
    fwrite(bmpfileheader,1,14,f);
    fwrite(bmpinfoheader,1,40,f);
    for(int i=0; i<HEIGHT; i++)
    {
	fwrite(img+(WIDTH*(HEIGHT-i-1)*3),3,WIDTH,f);
	fwrite(bmppad,1,(4-(WIDTH*3)%4)%4,f);
    }
    fclose(f);
}


int main()
{
	int red[HEIGHT][WIDTH], green[HEIGHT][WIDTH], blue[HEIGHT][WIDTH];
    //defining variables
   	float real;
	float imag;
	float sum;
	int count=0;
	
    
    //with the two for loops we go trough all the pixels in the image.
	for (int i=0;i<HEIGHT;++i)          //for loop that goes trough all the pixels in height
	{

		for( int j=0;j<WIDTH;++j)       //for loop that goes trough all the pixels in width
		{
	
			 Complex z(0,0);            //sets the complex number c to '0 + 0i'
			 float cx= i/250.0-1.5;     //this computes the real part of c
			 float cy= j/250.0-1.0;     //this computes the imaginary part of c
			
			 Complex c(cx,cy);          //c is set to a complex number with real part cx and imaginary part cy
		
		
			 while(true)                    //this while loop computes 'z=(z*z)+c' until the sum of the square of the real and the squeare of the imaginary part of z is more than 2.0 or it has run more than 32 times.
             {

				count++;                    //this counts how often the loop has run.
				z=(z*z)+c;                  //this is the computation itselves.
				real =z.getReal();
				imag =z.getImag();
				sum=real*real+imag*imag;    //this computes to sum, which has to be more than 2.0 for the loop to stop.
		
				if(sum>2.0)
				{
                    //here the red, green and blue values of each pixel are set. one of them has to be fixed.
					red[i][j]=256-8*count;;
					green[i][j]= 256-8*count;;
					blue[i][j]= 255;
					count=0;                    //count is set back to zero for the next iteration.
					break;
                }
                
                //if more than 32 iterations have happened the pixel is set to black.
				else if(count>32)
                {
					red[i][j]=0;
					green[i][j]=0;
					blue[i][j]=0;
					count=0;                    //count is set back to zero for the next iteration
					break;	
				}
			}
	
        }
 	 }
		
	

    writeBMP(red, green, blue);

    return 0;
}

