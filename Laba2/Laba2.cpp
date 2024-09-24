#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

// Функция для расчета работы изотермического расширения
double calculateIsothermalWork(double R, double T, double V1, double V2) {
    return R * T * log(V2 / V1);
}

// Функция для расчета работы адиабатического расширения
double calculateAdiabaticWork(double R, double T, double V1, double V2, double n) {
    return (R * T) / (n - 1) * (1 - pow(V1 / V2, n - 1));
}

int main() {

    setlocale(LC_ALL, "rus");

    // Заданные параметры
    double R = 8.31;  // Газовая постоянная, кДж/град
    double n = 1.2;   // Показатель адиабаты
    double T = 320.0; // Температура процесса, градусы K
    double V1 = 2.0;  // Начальный объем газа, м^3

    // Конечные объемы газа
    std::vector<double> V2_values = { 2.2, 2.4, 2.6, 2.8, 3.0, 4.0, 5.0, 6.0, 7.0 };

    // Вывод результатов
    std::cout << std::fixed << std::setprecision(3);
    std::cout << std::setw(8) << "V2 (м^3)" << "\t" << std::setw(8) << "A1 (кДж)" << "\t" << std::setw(8) << "A2 (кДж)" << std::endl;
    std::cout << "---------------------------------" << std::endl;

    // Цикл с предусловием
    for (double V2 : V2_values) {
        double A1 = calculateIsothermalWork(R, T, V1, V2);
        double A2 = calculateAdiabaticWork(R, T, V1, V2, n);
        std::cout << std::setw(8) << V2 << "\t" << std::setw(8) << A1 << "\t" << std::setw(8) << A2 << std::endl;
    }

    std::cout << std::endl;

    // Цикл с постусловием
    auto it = V2_values.begin();
    do {
        double V2 = *it;
        double A1 = calculateIsothermalWork(R, T, V1, V2);
        double A2 = calculateAdiabaticWork(R, T, V1, V2, n);
        std::cout << std::setw(8) << V2 << "\t" << std::setw(8) << A1 << "\t" << std::setw(8) << A2 << std::endl;
        ++it;
    } while (it != V2_values.end());

    return 0;
}