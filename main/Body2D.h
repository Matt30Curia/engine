#pragma once
#include "Point.h"
#include <string>
#include <iostream>
#include <algorithm>
#include "Node.h"
#include "Sprite.h"
#include "NodeManager.h"

class Body2D : public Point
{
 
    public:
       Body2D(const std::string& child,const std::string& uuid) : Point(Vector2D{10,10}, uuid) , _child(child){} //TO-DO implentiting copy and move constructor

       void init();
       inline std::string type() override { return _uuid; }
       void move(Vector2D& velocity, float delta);
       float lookAt(const Vector2& position);
       inline void draw() { for (auto sprite :sprites)sprite->draw(); }
        

       ~Body2D() {}

private:

    std::vector<RenderObj*> sprites;
    std::string _child;
    double m;

};

//cambiare getchild(di renderobj) con argiomenti e tipi restituiti