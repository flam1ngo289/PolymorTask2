#include <iostream>
#include <string>

class Figure {
protected:
    std::string name;
public:
    Figure(const std::string& figure_name) {
        name = figure_name;
    }
    
   virtual void print_info() {
        std::cout << name << std::endl;
    }
};

class Triangle : public Figure{
protected:
    int a, b, c;
    int A, B, C;
    
public:
    Triangle(int side1, int side2, int side3, int angle1, int angle2, int angle3) : Figure("Треугольник"), a(side1), b(side2), c(side3), A(angle1), B(angle2), C(angle3){}
    
    void print_info() override {
        std::cout << name << ":" << std::endl;
        std::cout << "Стороны: " << "a=" << a << " b=" << b << " c=" << c << std::endl;
        std::cout << "Углы: " << "A=" << A << " B=" << B << " C=" << C << std::endl;
        std::cout << std::endl;
    }
};

class RightTriangle : public Triangle{
public:
    RightTriangle(int side1, int side2, int side3, int angle1, int angle2) : Triangle(side1, side2, side3, angle1, angle2, 90) {
        name = "Прямоугольный треугольник";
    }
};

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(int side1, int side2, int angle1, int angle2) : Triangle(side1, side2, side1, angle1, angle2, angle1){
        name = "Равнобедренный треугольник";
    };
};

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(int side1) : Triangle(side1, side1, side1, 60, 60, 60){
        name = "Равносторонний треугольник";
    }
};

class Quadrangle : public Figure {
protected:
    int a, b, c, d;
    int A, B, C, D;
public:
    Quadrangle(int side1, int side2, int side3, int side4, int angle1, int angle2, int angle3, int angle4) : Figure("Четырехугольник"), a(side1), b(side2), c(side3), d(side4), A(angle1), B(angle2), C(angle3), D(angle4){}
    
    void print_info() override {
        std::cout << name << ":" << std::endl;
        std::cout << "Стороны: " << "a=" << a << " b=" << b << " c=" << c << " d="<< d << std::endl;
        std::cout  << "Углы: " << "A=" << A << " B=" << B << " C=" << C << " D="<< D << std::endl;
        std::cout << std::endl;
    }
};
class Parallelogram : public Quadrangle{
public:
    Parallelogram(int side1, int side2, int angle1, int angle2) : Quadrangle(side1, side2, side1, side2, angle1, angle2, angle1, angle2){
        name = "Параллелограмм";
    }
};

class Rectangle : public Parallelogram{
public:
    Rectangle(int side1, int side2) : Parallelogram(side1, side2, 90, 90){
        name = "Прямоугольник";
    }
};

class Square : public Rectangle{
public:
    Square(int side1) : Rectangle(side1, 90){
        name = "Квадрат";
    }
};

class Rhombus : public Parallelogram {
public:
    Rhombus(int side1, int angle1, int angle2) : Parallelogram(side1, side1, angle1, angle2){
        name = "Ромб";
    }
};

void print_info(Figure* figure){
    figure->print_info();
}

int main(int argc, const char * argv[]) {

    Triangle triangle(10, 20, 30, 50, 60 ,70);
    print_info(&triangle);     //triangle.print_info();
    
    RightTriangle rightTriangle(10, 20, 30, 50, 60);
    print_info(&rightTriangle);     //rightTriangle.print_info();
    
    IsoscelesTriangle isoscelesTriangle(10, 20, 50, 60);
    print_info(&isoscelesTriangle);     //isoscelesTriangle.print_info();
    
    EquilateralTriangle equilateralTriangle(30);
    print_info(&equilateralTriangle);    //equilateralTriangle.print_info();
    
    Quadrangle quadrangle(10,20,30,40,50,60,70,80);
    print_info(&quadrangle);     //quadrangle.print_info();
    
    Rectangle rectangle(10, 20);
    print_info(&rectangle);     //rectangle.print_info();
    
    Parallelogram parallelogram(20,30, 30, 40);
    print_info(&parallelogram);     //parallelogram.print_info();
    
    Rhombus rhombus(30, 30, 40);
    print_info(&rhombus);     //rhombus.print_info();

        return 0;
}
