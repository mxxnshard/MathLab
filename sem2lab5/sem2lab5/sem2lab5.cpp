#include <iostream>
#include <vector>
#include <cmath>

// Определяем дифференциальное уравнение y' = f(x, y)
double f(double x, double y) {
    return pow(-1, 5) * y + 0.6 * x * x + 2.4;
}

double calculate(double x) {
    return -5.0 / 2.0 * exp(-x) + 3.0 / 5.0 * x * x - 6.0 / 5.0 * x + 7.0 / 2.0;
}

int main() {
    // Инициализация переменных
    double x0 = 0, y = 1; // Начальные условия: y(0) = 1
    double h = 0.2;       // Шаг
    int n = static_cast<int>((2 - x0) / h); // Количество шагов

    // Вектора для хранения решения
    std::vector<double> x_values(n + 1), y_values(n + 1), calculator_values(n + 1);

    // Начальные значения
    x_values[0] = x0;
    y_values[0] = y;
    calculator_values[0] = calculate(x0);

    // Реализация метода Эйлера
    for (int i = 1; i <= n; ++i) {
        y += h * f(x_values[i - 1], y_values[i - 1]);
        x_values[i] = x_values[i - 1] + h;
        y_values[i] = y;
        calculator_values[i] = calculate(x_values[i]);
        std::cout << "x" << i << ": " << x_values[i]
            << ",       y" << i << ": " << y_values[i]
            << ",        y_calc" << i << ": " << calculator_values[i]
            << std::endl;
    }

    return 0;
}