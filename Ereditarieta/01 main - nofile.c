#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>

#include "canvas.h"
#include "string.h"

/*
type_of_object parameter_1 parameter_2 ... parameter_n

rectangle 0 0 79 24 *
point 5 15 ?
circle 10 10 4 @
circle 70 10 4 @
line 40 15 40 20 |
*/

/*void draw_file(FILE *f, canvas *c)
{
	char type[30];
	while (fscanf(f, "%29s", type) == 1) {
		if (strcmp(type, "point") == 0) {
			int x, y;
			char ch;
			fscanf(f, "%d%d %c", &x, &y, &ch);
			canvas_set(c, x, y, ch);
		}
		else if (strcmp(type, "line") == 0) {
			int x0, y0, x1, y1;
			char ch;
			fscanf(f, "%d%d%d%d %c", &x0, &y0, &x1, &y1, &ch);
			canvas_line(c, x0, y0, x1, y1, ch);
		}
		else if (strcmp(type, "rectangle") == 0) {
			int x0, y0, x1, y1;
			char ch;
			fscanf(f, "%d%d%d%d %c", &x0, &y0, &x1, &y1, &ch);
			canvas_rectangle(c, x0, y0, x1, y1, ch);
		}
		else if (strcmp(type, "circle") == 0) {
			int xm, ym, r;
			char ch;
			fscanf(f, "%d%d%d %c", &xm, &ym, &r, &ch);
			canvas_circle(c, xm, ym, r, ch);
		}
	}
}*/



int main(void)
{
	canvas* c = new_canvas(80, 25);

	/*
	FILE *f = fopen("drawing1.txt", "rt");
	if (f == NULL) return 1;
	draw_file(f, c);
	fclose(f);
	*/

	canvas_rectangle(c, 0, 0, 79, 24, '*');
	canvas_set(c, 5, 15, '?');
	canvas_circle(c, 10, 10, 4, '@');
	canvas_circle(c, 70, 10, 4, '@');
	canvas_line(c, 40, 15, 40, 20, '|');

	canvas_out(c, stdout);
	delete_canvas(c);
}