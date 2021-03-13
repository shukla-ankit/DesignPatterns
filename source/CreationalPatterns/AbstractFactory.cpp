#include <iostream>
using namespace std;
/*Provides an interface for creating families of related or dependant objects without specifying
their concrete class*/
class Shape{
    public:
        virtual void draw() = 0;
};
class Rectangle : public Shape {
    public:
        void draw(){cout << "draw() -> Rectangle" << endl;}
};
class Circle : public Shape {
    public:
        void draw(){ cout << "draw() -> Circle" << endl;}
};
class Cuboid : public Shape {
    public:
        void draw(){ cout << "draw() -> Cuboid" << endl;}
};
class Sphere : public Shape {
    public:
        void draw(){ cout << "draw() -> Sphere" << endl;}
};
class AbstractFactory{
    public:
        virtual Shape* getShape(string shapeType) = 0;
};
class CornersShapeFactory: public AbstractFactory{
    public:
        Shape* getShape(string shapeType){
            if(shapeType == "Rectangle")
                return new Rectangle();
            if(shapeType == "Cuboid")
                return new Cuboid();
        }
};
class NoCornersShapeFactory: public AbstractFactory{
    public:
        Shape* getShape(string shapeType){
            if(shapeType == "Circle")
                return new Circle();
            if(shapeType == "Sphere")
                return new Sphere();
        }
};

class FactoryProducter{
    public:
    static AbstractFactory* getFactory(bool bIsCornered){
        if(bIsCornered)
            return new CornersShapeFactory();
        else
            return new NoCornersShapeFactory();
    }
};

int main(){
    AbstractFactory* pAbsFactory = FactoryProducter::getFactory(false);
    if(pAbsFactory == nullptr)
        return 1;
    
    Shape* pCircleShape = pAbsFactory->getShape("Circle");
    if(pCircleShape == nullptr)
        return 2;

    pCircleShape->draw();    

    return 0;
}