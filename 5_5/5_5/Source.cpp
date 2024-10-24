#include <iostream>
#include <cmath>
#include <iomanip> 

using namespace std;

double recursive_sequence(int n, int level, int& depth) {
    if (level > depth) {
        depth = level;
    }
    cout << "level = " << level << endl;

    if (n == 1) {
        return 1.0;
    }
    else {
        double prev = recursive_sequence(n - 1, level + 1, depth);
        return (1.0 / 3.0) * (2 * prev + 8 / pow(prev, 2));
    }
}

double find_limit(int max_iterations, double tolerance, int& depth, int level) {
    double prev = 1.0;
    double current;

    for (int n = 2; n <= max_iterations; n++) {
        current = (1.0 / 3.0) * (2 * prev + 8 / pow(prev, 2));
        if (fabs(current - prev) < tolerance) {
            cout << "The sequence coincides with n = " << n << " to the value: " << current << endl;
            return current;
        }
        prev = current;
    }

    cout << "No agreement was reached in " << max_iterations << " iterations." << endl;
    return current;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    int depth = 0;
    int level = 1;

    double result = recursive_sequence(n, level, depth);
    cout << "Value of a_" << n << " = " << fixed << setprecision(6) << result << endl;

    cout << "Recursion depth: " << depth << endl;

    int max_iterations = 1000;
    double tolerance = 1e-6;
    double limit = find_limit(max_iterations, tolerance, depth, level);

    cout << "Limit of the sequence: " << fixed << setprecision(6) << limit << endl;

    return 0;
}
