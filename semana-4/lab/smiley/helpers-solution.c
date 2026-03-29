#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width]) {
  for(int r = 0; r < height; r++) {
    
    for(int c  = 0; c < width; c++) {
      
      RGBTRIPLE p = image[r][c];
      if (p.rgbtBlue == 0x00 && p.rgbtGreen == 0x00 && p.rgbtRed == 0x00) {
	p.rgbtBlue  = 0xff;
	p.rgbtGreen = 0x00;
	p.rgbtRed   = 0x00;
	image[r][c] = p;
      }
      
    }
  }
}
