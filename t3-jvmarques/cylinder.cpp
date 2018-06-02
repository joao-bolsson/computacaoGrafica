#include "cylinder.h"

#include <iostream>

Cylinder::Cylinder(int r, int h, Point *c):Solid(c) {
    this->r = r;
    this->h = h;

    //h precisa ser par

    this->maxL = h / 2;
    this->maxC = 12; // 2PI/(PI/6) = 30

    int startY = c->getY() - h/2;
    int endY = c->getY() + h/2;
    int stepY = h/4;

    float alfa = 0.52; // 30 * pi / 180

    for (int y = startY; y < endY; y += stepY) {
        vector<Point*> points;
        // calcula pontos da circunferencia base
        for (float factorAlfa = 0.01; factorAlfa < maxC; factorAlfa++) {
            Point *point = new Point(ceil(r * cos(alfa * factorAlfa)), y, ceil(r * sin(alfa * factorAlfa)));
            points.push_back(point);

//            cout << "point: (" << point->getX() << ", " << point->getY() << ", " << point->getZ() << ")" << endl;

        }
        matrix.push_back(points);
    }

}

void Cylinder::draw(Canvas2D *canvas) {
    /*
for(l=0; l<M; l++)
{
for(c=0; c<N; c++)
{
line(M[l,c], M[l ,c+1]); //linha horizontal
line(M[l,c], M[l+1,c ]); //linha vertical
line(m[l,c], M[l+1,c+1]); //linha diagonal
}
}
      */


//    for (auto v : matrix) {
//        for (auto point : v) {
//            if (point->getZ() == 0) {
//                cout << "z eh zero" << endl;
//            }
//            cout << "point: (" << point->getX() << ", " << point->getY() << ", " << point->getZ() << ")" << endl;
//        }
//    }

    int size = matrix.size();
    for (int l = 0; l < size - 1; l++) {
        auto v = matrix.at(l);
        auto v1 = matrix.at(l+1);
        for (int col = 0; col < maxC - 1; col++) {
            auto p = v.at(col);
            auto p1 = v.at(col+1);
            auto pp1 = v1.at(col);
            auto pp2 = v1.at(col+1);

            canvas->line(p->getX2d(), p->getY2d(), p1->getX2d(), p1->getY2d());
            canvas->line(p->getX2d(), p->getY2d(), pp1->getX2d(), pp1->getY2d());
            canvas->line(p->getX2d(), p->getY2d(), pp2->getX2d(), pp2->getY2d());
        }
    }

}
