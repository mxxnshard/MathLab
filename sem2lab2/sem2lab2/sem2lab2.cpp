#include <iostream>
#include <vector>
#include <iomanip>

// Метод левых прямоугольников
double leftRectangleMethod(const std::vector<double>& y, double h) {
    double integral = 0.0;
    for (size_t i = 0; i < y.size() - 1; ++i) {
        integral += y[i];
    }
    return integral * h;
}

// Метод правых прямоугольников
double rightRectangleMethod(const std::vector<double>& y, double h) {
    double integral = 0.0;
    for (size_t i = 1; i < y.size(); ++i) {
        integral += y[i];
    }
    return integral * h;
}

// Метод трапеций
double trapezoidalMethod(const std::vector<double>& y, double h) {
    double integral = y.front() + y.back();
    for (size_t i = 1; i < y.size() - 1; ++i) {
        integral += 2 * y[i];
    }
    return integral * h / 2.0;
}

int main() {
    std::vector<double> x = { 0.451, 0.452, 0.453, 0.454, 0.455 };
    std::vector<double> y = { 0.43587, 0.43677, 0.43766, 0.43856, 0.43945 };
    double h = x[1] - x[0]; // Расстояние между узлами

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Left Rectangle Method: " << leftRectangleMethod(y, h) << std::endl;
    std::cout << "Right Rectangle Method: " << rightRectangleMethod(y, h) << std::endl;
    std::cout << "Trapezoidal Method: " << trapezoidalMethod(y, h) << std::endl;

    return 0;
}