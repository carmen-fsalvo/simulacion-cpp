 #include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

double funcion(double x, double k) {
    return (2.0/M_PI)*(1.0/sqrt(1-pow(k*sin(x),2.0)));
}

double simpsons_13_simple(double a, double b, double k) {
    return (b - a) / 6.0 * (funcion(a, k) + 4 * funcion((a + b) / 2.0, k) + funcion(b, k));
}

double simpsons_38_simple(double a, double b, double k) {
    return (b - a) / 8.0 * (funcion(a, k) + 3 * funcion(a + (b - a) / 3.0, k) +
                            3 * funcion(a + 2 * (b - a) / 3.0, k) + funcion(b, k));
}

// Simpson's 1/3 rule
double simpsons_13_compuesta(double (*func)(double, double), double a, double b, int n, double k) {
    double h = (b - a) / n;
    double result = func(a, k) + func(b, k);

    for (int i = 1; i < n; i += 2) {
        result += 4 * func(a + i * h, k);
    }

    for (int i = 2; i < n - 1; i += 2) {
        result += 2 * func(a + i * h, k);
    }

    return h / 3 * result;
}


// Simpson's 3/8 rule
double simpsons_38_compuesta(double (*func)(double, double), double a, double b, int n, double k) {
    double h = (b - a) / n;
    double sum = func(a, k) + func(b, k);

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 3 == 0) {
            sum += 2 * func(a + i * h, k);
        } else {
            sum += 3 * func(a + i * h, k);
        }
    }

    return (3 * h * sum / 8);
}


double trapezoidal(double (*func)(double, double), double a, double b, int n, double k) {
    double h = (b - a) / n;
    double sum = 0.5 * (func(a, k) + func(b, k));

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += func(x, k);
    }

    return h * sum;
}

int main() {
    double theta[31], k, T13c[31], T38c[31], Ttra[31], T38s[31], T13s[31]; 
    double a = 0.0;  // lower limit of integration
    double b = M_PI / 2.0;  // upper limit of integration
    int n = 1200;  // number of intervals (multiple of 3 and 2)

    theta[0] = 0.0;
    for (int i = 1; i <= 30; i++) {
        theta[i] = theta[i - 1] + 5.0;
    }



    for (int j = 0; j <= 30; j++) {
        k = sin(theta[j] * (M_PI / 180.0) / 2.0);
        T13c[j] = simpsons_13_compuesta(funcion, a, b, n, k) ;
        T38c[j] = simpsons_38_compuesta(funcion, a, b, n, k) ;
        T13s[j] = simpsons_13_simple(a, b, k) ;
        T38s[j] = simpsons_38_simple(a, b, k) ;
        Ttra[j] = trapezoidal(funcion, a, b, n, k) ;
    }

std::ofstream file1("P72_theta.txt");
for (int j = 0; j <= 30; j++) {
    file1 << theta[j] << ", ";
}
file1.close();

std::ofstream file2("P72_T13c.txt");
for (int j = 0; j <= 30; j++) {
    file2 << T13c[j] << ", ";
}
file2.close();

std::ofstream file3("P72_T38c.txt");
for (int j = 0; j <= 30; j++) {
    file3 << T38c[j] << ", ";
}
file3.close();

std::ofstream file4("P72_Ttra.txt");
for (int j = 0; j <= 30; j++) {
    file4 << Ttra[j] << ", ";
}
file4.close();

std::ofstream file5("P72_T13s.txt");
for (int j = 0; j <= 30; j++) {
    file5 << T13s[j] << ", ";
}
file5.close();

std::ofstream file6("P72_T38s.txt");
for (int j = 0; j <= 30; j++) {
    file6 << T38s[j] << ", ";
}
file6.close();

return 0;
}