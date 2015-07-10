#include <X11/Xlib.h>
#include <X11/X.h>

#include <stdlib.h>
#include <stdio.h>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

int main()
{
  Display *display = XOpenDisplay(NULL);
  Window root = DefaultRootWindow(display);

  XWindowAttributes gwa;

  XGetWindowAttributes(display, root, &gwa);
  int width = gwa.width;
  int height = gwa.height;

  XImage *image = XGetImage(display,root, 0, 0, width, height, AllPlanes, ZPixmap);

  char array[width * height * 3];

  long count = 0;
  unsigned long pixel;

  char *rgb = malloc(image->width * image->height * 3);

  for(int i=0, j = 0; i <  image->width * image->height * 4; i = i + 4){
    rgb[j] = image->data[i+2];
    rgb[j+1] = image->data[i+1];
    rgb[j+2] = image->data[i];
    j = j + 3;
  }

  int result = stbi_write_png("test.png", image->width, image->height, 3, rgb, image->width *  3);
  XFree(image);
  printf("result was %d\n", result);

  return 0;
}
