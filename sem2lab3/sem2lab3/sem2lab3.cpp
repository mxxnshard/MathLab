#include <iostream>
#include <vector>
#include <iomanip>

// Функция для метода Симпсона
double simpsonMethod(const std::vector<double>& y, double h) {
    // Проверяем, что у нас достаточно точек для метода Симпсона
    if (y.size() < 5) {
        std::cerr << "Simpson's method requires at least 5 points." << std::endl;
        return 0;
    }

    // Вычисляем значение интеграла
    double integral = y[0] + 4 * y[1] + 2 * y[2] + 4 * y[3] + y[4];
    integral *= h / 3.0;

    return integral;
}

int main() {
    // Значения x_i не нужны для вычисления интеграла методом Симпсона, если известен шаг h
    std::vector<double> y = { 0.43587, 0.43677, 0.43766, 0.43856, 0.43945 };
    double h = 0.001; // Шаг сетки, предполагаем что он равен 0.001

    // Вычисляем и выводим результат
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Simpson's method result: " << simpsonMethod(y, h) << std::endl;

    return 0;
}