#include <vector>
#include <cmath>

using namespace std;

vector<size_t> smallSum3(vector<int>);

int exercise_1() {
    vector<int> a{2, -13, 3, 6, 4, 5, -14, 1, -15};
    auto r = smallSum3(a);

    printf("Sum=%d for elements "
                "a[%u]=%d, a[%u]=%d, a[%u]=%d\n",
                a[r[0]] + a[r[1]] + a[r[2]],
                r[0], a[r[0]], r[1], a[r[1]], r[2], a[r[2]]);
    return 0;
}

vector<size_t> smallSum3(vector<int> input_vector) {
    vector<size_t> output_vector(3);
    int smallest_abs_sum = abs(input_vector.at(0) + input_vector.at(1) + input_vector.at(2));

    for (int i = 0; i < input_vector.size(); i++) {
        for (int j = 0; j < input_vector.size(); j++) {
            for (int k = 0; k < input_vector.size(); k++) {
                int sum = abs(input_vector.at(i) + input_vector.at(j) + input_vector.at(k));

                if (sum < smallest_abs_sum && i != j && i != k && j != k) {
                    smallest_abs_sum = sum;
                    output_vector.clear();
                    output_vector.push_back(i);
                    output_vector.push_back(j);
                    output_vector.push_back(k);
                }
            }
        }
    }

    return output_vector;
}