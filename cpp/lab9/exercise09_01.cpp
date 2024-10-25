// Diego Martinez
// Created July 24, 2024
#include <iostream>
using namespace std;

class Rectangle{
    public:
        // Data Fields
        double width;
        double height;

        // Constructors
        Rectangle(){
            width = 1;
            height = 1;
        }
        Rectangle(double w, double h){
            width = w;
            height = h;
        }

        // Accessors and Mutators
        double getWidth(){
            return width;
        }
        void setWidth(double w){
            width = w;
        }
        double getHeight(){
            return height;
        }
        void setHeight(double h){
            height = h;
        }

        // Functions
        double getArea(){
            return (width*height);
        }
        double getPerimeter(){
            return ((2*width)+(2*height));
        }
        void printRectangle(){
            cout<< "The area of a rectangle with width " << width <<
            " and height " << height << " is " << getArea() << 
            " and perimeter is " << getPerimeter() << endl;
        }
};

int main(){
    Rectangle rect1(4, 40);
    Rectangle rect2(3.5, 35.9);
    rect1.printRectangle();
    rect2.printRectangle();

    return 0;
}
// Output
/*
    The area of a rectangle with width 4 and height 40 is 160 and perimeter is 88
    The area of a rectangle with width 3.5 and height 35.9 is 125.65 and perimeter is 78.8
*/