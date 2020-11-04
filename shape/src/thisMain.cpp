//
// Created by yanGw on 2020/11/4.
//

#include "../include/sphere.h"
#include "../include/triangle.h"
#include<iostream>

using namespace std;

int main() {
    //shape* ps0 = new shape;  //shape是抽象类，不能被实例化
    shape* ps = new sphere;
    shape* ps1 = new triangle;
    ps -> draw();
    ps1 -> draw();

    //调用shape::draw
    ps -> shape::draw();

    getchar();
}