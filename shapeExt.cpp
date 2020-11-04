//
// Created by yanGw on 2020/11/4.
//

#include <iostream>

using namespace std;

class shape {
public:
    shape();

    virtual ~shape();

    virtual void draw() const = 0;
};

shape::shape() {}

shape::~shape() {}

void shape::draw() const {
    cout << "draw shape\n";
}

class sphere : public shape {
public:
    sphere();

    virtual ~sphere();

    virtual void draw() const;
};

sphere::sphere() {}

sphere::~sphere() {}

void sphere::draw() const {
    cout << "draw sphere\n";
}

class triangle : public shape {
public:
    triangle();

    virtual ~triangle();

    virtual void draw() const;
};

triangle::triangle() {}

triangle::~triangle() {}

void triangle::draw() const {
    cout << "draw triangle\n";
}

int main() {
    shape *psp = new sphere;
    shape *ptr = new triangle;

    psp->draw();
    ptr->draw();

    psp->shape::draw();
    getchar();
}