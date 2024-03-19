#include <iostream>
#include <cmath>

using namespace std;
/////////////////////////////////////////////////////////////////////////////////////////////МЕНЯТЬ F, FSECOND, FFOURTH. Это функция и ее производные


//Производная 4-го порядка
double ffourth(double x)
{
    return (4*x*(pow(x,2)-6)*cos(x)+(pow(x, 4)-12*pow(x,2)+24)*sin(x))/(pow(x, 5));
}



//Производная второго порядка
double fsecond(double x)
{
    return (((2-pow(x, 2))*sin(x))-(2*x*cos(x)))/pow(x,3);
}

double f(double x)
{
    return sin(x) / x;
}

//Поиск наибольшего значения производной. Грубо, но что поделать
double find_max_abs_value(double a, double b, double f(double)) {
    double max_abs_value = abs(f(a));
    double x_max_abs_value = a;

    for (double x = a + 0.01; x <= b; x += 0.01) {
        double abs_value = abs(f(x));
        if (abs_value > max_abs_value) {
            max_abs_value = abs_value;
            x_max_abs_value = x;
        }
    }

    return max_abs_value;
}

int multiply_until_integer(double number) {
    int num_multiplications = 0;

    while ((number / 1) < 1) {
        number *= 10;
        num_multiplications++;
    }

    return num_multiplications;
}

double trunc_float(double number, int count)
{
    double result = ceil(number * pow(10, count)) / pow(10, count);
    return result;
}
//Поиск числа промежутков
double find_n(double a, double b, double maxf, double eps) {

    double x = sqrt((maxf*pow((b-a),3)/(12*eps)));

    return x;
}

double find_n_simp(double a, double b, double maxf, double eps) {

    double x = sqrt(sqrt((maxf * pow((b - a), 5) / (180 * eps))));

    return x;
}
//Число -- степень двойки. Удобно, всегда четное, да и вообще красивое
unsigned next_power_of_two(int value) {
    unsigned result = 1;

    while (result < value) {
        result *= 2;
    }

    return result;
}

int main() {
    //cin >> a >> b;
    float PI = 3.14159265359;
    /////////////////////////////////////////////////////////////////////////////////////////////МЕНЯТЬ A, B, EPS.
    double a = 2*PI, b = 3*PI, eps = 0.001;

    cout << "Трапеции" << endl;
    double max_abs_value = find_max_abs_value(2*PI, 3*PI, fsecond);
    double maxf = trunc_float(max_abs_value, multiply_until_integer(max_abs_value));
    cout << "Функция принимает значения меньше чем " << maxf << endl;
    unsigned n = ceil(find_n(2 * PI, 3 * PI, maxf, eps));
    cout << "Число промежутков: " << n << endl;
    double h = (b - a) / n;
    double sum = 0;
    for (int i = 1; i < n; i++)
    {
        sum += f(a+i*h);
    }
    sum = (f(a) + f(b)+2*sum)*(h/2);
    cout << sum << endl;

    cout << "Симпсон" << endl;
    max_abs_value = find_max_abs_value(2 * PI, 3 * PI, ffourth);
    maxf = trunc_float(max_abs_value, multiply_until_integer(max_abs_value));
    cout << "Функция принимает значения меньше чем " << maxf << endl;
    n = next_power_of_two(ceil(find_n_simp(2 * PI, 3 * PI, maxf, eps)));
    cout << "Число промежутков: " << n << endl;
    unsigned m = n / 2;
    h = (b - a) / n;
    double sum1 = 0;
    double sum2 = 0;

    for (int i = 1; i <= m; i++) {
        sum1 += f(a + (2 * i - 1) * h);
    }

    for (int i = 1; i < m; i++) {
        sum2 += f(a + 2 * i * h);
    }

    double s = (h / 3) * (f(a) + f(b) + 4 * sum1 + 2 * sum2);

    cout << "Интеграл: " << s << endl;
    return 0;
}