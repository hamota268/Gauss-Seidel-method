/* 
created by Youssef Mohamed @ computer science.
*/

#include <iostream>
#include <vector>

using namespace std;

// Function to perform Gauss-Seidel iteration
vector<double> gaussSeidel(const vector<vector<double>>& A, const vector<double>& b, int maxIterations, double tolerance) {
    int n = A.size();
    vector<double> x(n, 0.0); // Initial guess for solution
    vector<double> prevX(n, 0.0); // Store previous iteration solution

    int iteration = 0;
    double error = tolerance + 1;

    while (iteration < maxIterations && error > tolerance) {
        prevX = x;

        for (int i = 0; i < n; i++) {
            double sum = 0.0;

            for (int j = 0; j < n; j++) {
                if (j != i) {
                    sum += A[i][j] * x[j];
                }
            }

            x[i] = (b[i] - sum) / A[i][i];
        }

        // Calculate error
        error = 0.0;
        for (int i = 0; i < n; i++) {
            error += abs(x[i] - prevX[i]);
        }

        iteration++;
    }

    return x;
}

int main() {
    int n;

    cout << "Enter the number of variables: ";
    cin >> n;

    vector<vector<double>> A(n, vector<double>(n));
    vector<double> b(n);

    // Input matrix A
    cout << "Enter the coefficients of matrix A:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "A[" << i << "][" << j << "]: ";
            cin >> A[i][j];
        }
    }

    // Input vector b
    cout << "Enter the values of vector b:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "b[" << i << "]: ";
        cin >> b[i];
    }

    int maxIterations;
    double tolerance;

    cout << "Enter the maximum number of iterations: ";
    cin >> maxIterations;

    cout << "Enter the tolerance: ";
    cin >> tolerance;

    // Solve using Gauss-Seidel method
    vector<double> solution = gaussSeidel(A, b, maxIterations, tolerance);

    // Output the solution
    cout << "\nSolution:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "x[" << i << "]: " << solution[i] << endl;
    }

    return 0;
}
