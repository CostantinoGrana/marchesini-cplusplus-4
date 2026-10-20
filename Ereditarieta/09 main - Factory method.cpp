#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <map>

#include "canvas.h"

#include <memory>

// abstract class
struct shape {
	int x_, y_;
	char c_;

	shape() {}
	shape(int x, int y, char c) : x_(x), y_(y), c_(c) {}
	virtual ~shape() = default;

	virtual shape* clone(std::istream& is) const = 0;

	virtual void draw(canvas& can) const = 0; // pure virtual

	void printpos() const {
		printf("Posizione: %d,%d\n", this->x_, this->y_);
	}
};
struct point : public shape {
	point(){}
	point(int x, int y, char c) : shape(x, y, c) {}
	point(std::istream& is) {
		is >> x_ >> y_ >> c_;
	}
	shape* clone(std::istream& is) const {
		return new point(is);
	}
	void draw(canvas& can) const override {
		can.set(x_, y_, c_);
	}
};
struct line : public shape {
	int x2_, y2_;
	line(){}
	line(int x, int y, int x2, int y2, char c) : shape(x, y, c), x2_(x2), y2_(y2) {}
	line(std::istream& is) {
		is >> x_ >> y_ >> x2_ >> y2_ >> c_;
	}
	shape* clone(std::istream& is) const {
		return new line(is);
	}
	void draw(canvas& can) const override {
		can.line(x_, y_, x2_, y2_, c_);
	}
};
struct circle : public shape {
	int r_;
	circle(){}
	circle(int x, int y, int r, char c) : shape(x, y, c), r_(r) {}
	circle(std::istream& is) {
		is >> x_ >> y_ >> r_ >> c_;
	}
	shape* clone(std::istream& is) const {
		return new circle(is);
	}
	void draw(canvas& can) const override {
		can.circle(x_, y_, r_, c_);
	}
};
struct rectangle : public shape {
	int x2_, y2_;
	rectangle(){}
	rectangle(int x, int y, int x2, int y2, char c) : shape(x, y, c), x2_(x2), y2_(y2) {}
	rectangle(std::istream& is) {
		is >> x_ >> y_ >> x2_ >> y2_ >> c_;
	}
	shape* clone(std::istream& is) const {
		return new rectangle(is);
	}
	void draw(canvas& can) const override {
		can.rectangle(x_, y_, x2_, y2_, c_);
	}
};

/* Explicit */
struct myint {
	int val_; 
	myint() : val_(42) {}
	explicit myint(int x) : val_(x) {}
	void print() const {
		std::cout << val_;
	}
};
void funzione(myint m) {
	m.print();
}

std::map<std::string, shape*> shapes_factory_map;

auto read_shapes(std::istream& is)
{
	using std::make_unique;

	std::vector<std::unique_ptr<shape>> shapes;

	std::string type;
	while (is >> type) {
		shape* obj = shapes_factory_map[type];
		shapes.emplace_back(obj->clone(is));
	}
	return shapes;
}

// CRTP : Curiously recurring template pattern

int main(void)
{
	shapes_factory_map["point"] = new point();
	shapes_factory_map["line"] = new line();
	shapes_factory_map["rectangle"] = new rectangle();
	shapes_factory_map["circle"] = new circle();

	/* example explicit */
	myint m(5); // ok
	//myint m = 5; // non ok
	funzione(myint(5)); // ok
	//funzione(5); // non ok

	canvas c(80, 25);

	std::ifstream is("drawing1.txt"/*, std::ios::binary*/);
	if (!is) return 1;
	auto shapes = read_shapes(is);


	/*
	std::unique_ptr<int> p;
	{
		std::unique_ptr<int> q(new int(7));

		std::cout << *q << "\n";

		p = move(q);
	}
	std::cout << *p << "\n";
	*/

	/*
	std::shared_ptr<int> p, r;
	{
		std::shared_ptr<int> q(new int(7));

		std::cout << *q << "\n";

		p = q;
		r = q;
	}
	std::cout << *p << "\n";
	p.reset();
	std::cout << *r << "\n";
	*/

	// std::vector<std::unique_ptr<shape>> shapes;
	// shapes.push_back(std::make_unique<rectangle>(0, 0, 79, 24, '*'));
	// shapes.push_back(std::make_unique<line>(40, 15, 40, 20, '|'));
	// shapes.push_back(std::make_unique<point>(5, 15, '?'));
	// shapes.push_back(std::make_unique<circle>(10, 10, 4, '@'));
	// shapes.push_back(std::make_unique<circle>(70, 10, 4, '@'));

	for (const auto& x : shapes) {
		x->draw(c);
	}

	c.out(std::cout);

	return 0;
}