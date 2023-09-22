#include <stdio.h>
#include <windows.h>
#include <math.h>


#define M_PI 3.14159265358979323846

const char gradient[] = "-#@#-";
const float size = 0.1;
const int width = 120, height = 30;

void Field(char *pixel, float y, float field)
{
	if (field < -0.7)
	{
		int index = y;
		*pixel = gradient[index];
	}

}

void gradientJ(char *pixel, float figure)
{
	if (figure < 0.5 && figure > size)
	{
		int index = figure * 10;
		*pixel = gradient[index];
	}
}

void draw(char back[], float cx, float cy)
{
   for (int i = 0; i < height; i++)
   {
      for (int j = 0; j < width; j++)
      {
         char pixel = ' ';
         float my = (float)i / height * 2 - 1 + cy;
         float mx = (float)j / width * 2 - 1 + cx;
         float figure = (mx * mx * 4 + my * my);
         float field = (-my);

         gradientJ(&pixel, figure);
         Field(&pixel, my, field);

         float shadowFigure = ((mx + 0.3) * 2 * (mx + 0.3) + 3 * (my - 1) * (my - 1));
         if (shadowFigure < 0.5 && shadowFigure > size)
            pixel = ' ';

         back[j + i * width] = pixel;
      }
   }
   Sleep(10);
   printf(back);
}


int main()
{
	char *back = new char[width * height + 1];
	back[width * height] = '\0';
	float cx = 0.0, cy = 0.0;
	int grad = 0;
	while (1)
	{
		draw(back, cx, cy);
		cx = sin(grad * M_PI / 180.0);
		cy = cos(grad * M_PI / 180.0);
		grad = grad + 1;	//grad регулирует скорость передвижение 
	}

}
