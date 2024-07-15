#include <iostream>
#include <cmath>
#include <vector>
#include <functional>

#define M_PI 3.14159265358979323846


// Функция для интегрирования
double f(double x) {
    return std::cos(x);
}

// Формула Гаусса-Лежандра
double gaussLegendreQuadrature(const std::vector<double>& weights, const std::vector<double>& nodes, int n) {
    double integral = 0.0;
    for (int i = 0; i < n; ++i) {
        integral += weights[i] * f(nodes[i]);
    }
    return integral;
}

// Формула Чебышева
double chebyshevQuadrature(int n) {
    double integral = 0.0;
    for (int i = 1; i <= n; ++i) {
        integral += f(std::cos((2 * i - 1) * M_PI / (2 * n)));
    }
    integral *= M_PI / n;
    return integral;
}

// Переменная замена с [a, b] на [-1, 1]
double changeOfInterval(std::function<double(double)> func, double a, double b, double integral) {
    return (b - a) / 2 * integral;
}

int main() {
    // Задаём интервал [a, b]
    double a = -M_PI / 2, b = M_PI / 2;
    int n = 6; // Число разбиений

    // Веса и узлы для формулы Гаусса для n=6 (примерные значения, для точности нужны таблицы)
    std::vector<double> weights = { 0.1713244923791704, 0.3607615730481386, 0.4679139345726910,
                                   0.4679139345726910, 0.3607615730481386, 0.1713244923791704 };
    std::vector<double> nodes = { -0.9324695142031521, -0.6612093864662645, -0.2386191860831969,
                                 0.2386191860831969, 0.6612093864662645, 0.9324695142031521 };

    // Вычисляем интеграл методом Гаусса-Лежандра
    double gaussResult = changeOfInterval(f, a, b, gaussLegendreQuadrature(weights, nodes, n));
    std::cout << "Интеграл методом Гаусса: " << gaussResult << std::endl;

    // Вычисляем интеграл методом Чебышева
    double chebResult = changeOfInterval(f, a, b, chebyshevQuadrature(n));
    std::cout << "Интеграл методом Чебышева: " << chebResult << std::endl;

    // Точное значение интеграла
    double exactResult = std::sin(b) - std::sin(a);
    std::cout << "Точное значение интеграла (Ньютона-Лейбница): " << exactResult << std::endl;

    return 0;
}