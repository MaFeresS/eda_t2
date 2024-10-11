/* implementation of the class Point2D
 */
#include"image/point2D.hpp"
#include <fstream>
#include <iostream>


 namespace image{
    Point2D::Point2D(): x(0), y(0) {

    }

	Point2D::Point2D(int _x, int _y): x(_x), y(_y){

    }
    void Point2D::setX(int _x){
        x = _x;
    }
    void Point2D::setY(int _y){
        y = _y;
    }
    int Point2D::getX(){
        return x;
    }
    int Point2D::getY(){
        return y;
    }
    Point2D::~Point2D(){
        
    }
 }