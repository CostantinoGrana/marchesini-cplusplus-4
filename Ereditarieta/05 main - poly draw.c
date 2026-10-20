#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdlib.h>

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

typedef struct shape {
	int x_, y_;
	char c_;
	void (*draw)();
} shape;
void shape_draw(const shape* this, canvas* can) {
	canvas_set(can, this->x_, this->y_, this->c_); // Non bellissimo
}
shape* shape_constructor(shape* this, int x, int y, char c) {
	this->x_ = x;
	this->y_ = y;
	this->c_ = c;
	this->draw = shape_draw;
	return this;
}
shape* shape_destructor(shape* this) { return this; }
shape* new_shape(int x, int y, char c) {
	return shape_constructor(malloc(sizeof(shape)), x, y, c);
}
void delete_shape(shape *obj) {
	free(shape_destructor(obj));
}
void shape_printpos(const shape* this) {
	printf("Posizione: %d,%d\n", this->x_, this->y_);
}

typedef struct line {
	shape base_;
	int x2_, y2_;
} line;
void line_draw(const line* this, canvas* can) {
	canvas_line(can, this->base_.x_, this->base_.y_, this->x2_, this-> y2_, this->base_.c_);
}
line* line_constructor(line* this, int x, int y, int x2, int y2, char c) {
	shape_constructor((void*)this, x, y, c);
	this->base_.draw = line_draw;
	this->x2_ = x2;
	this->y2_ = y2;
	return this;
}
line* line_destructor(line* this) { 
	shape_destructor((void*)this);
	return this; 
}
line* new_line(int x, int y, int x2, int y2, char c) {
	return line_constructor(malloc(sizeof(line)), x, y, x2, y2, c);
}
void delete_line(line *obj) {
	free(line_destructor(obj));
}

typedef struct rectangle {
	shape base_;
	int x2_, y2_;
} rectangle;
void rectangle_draw(const rectangle* this, canvas* can) {
	canvas_rectangle(can, this->base_.x_, this->base_.y_, this->x2_, this-> y2_, this->base_.c_);
}
rectangle* rectangle_constructor(rectangle* this, int x, int y, int x2, int y2, char c) {
	shape_constructor((void*)this, x, y, c);
	this->base_.draw = rectangle_draw;
	this->x2_ = x2;
	this->y2_ = y2;
	return this;
}
rectangle* rectangle_destructor(rectangle* this) { 
	shape_destructor((void*)this);
	return this; 
}
rectangle* new_rectangle(int x, int y, int x2, int y2, char c) {
	return rectangle_constructor(malloc(sizeof(rectangle)), x, y, x2, y2, c);
}
void delete_rectangle(rectangle *obj) {
	free(rectangle_destructor(obj));
}

int main(void)
{
	canvas* c = new_canvas(80, 25);
	/*
	FILE *f = fopen("drawing1.txt", "rt");
	if (f == NULL) return 1;
	draw_file(f, c);
	fclose(f);
	*/

	rectangle* r = new_rectangle(0, 0, 79, 24, '*');
	line* ln = new_line(40, 15, 40, 20, '|');

	shape* arr[] = { (void*)r, (void*)ln };
	size_t nshapes = 2;

	for (size_t i = 0; i < nshapes; ++i) {
		arr[i]->draw(arr[i], c);
	}

	canvas_out(c, stdout);

	delete_line(ln);
	delete_rectangle(r);
	delete_canvas(c);
	return 0;
}