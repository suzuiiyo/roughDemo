//
// Created by yanGw on 2020/11/4.
//

#ifndef CLIONCODE_SHAPEEXT_H
#define CLIONCODE_SHAPEEXT_H

#include<iostream>

using namespace std;

class shape {
public:
    //shape();

    virtual void draw() const = 0;

    virtual ~shape();
};

#endif //CLIONCODE_SHAPEEXT_H
