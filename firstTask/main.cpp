#include <string>
#include <vector>

import Libio;

template<typename T>
    requires std::is_integral_v<T>
T pow_quad(const T &value) {
    T result = value * value;
    libio::output::print("[IN]: " + std::to_string(value) + "\n");
    libio::output::print("[OUT]: " + std::to_string(result) + "\n");
    return result;
}

template<typename T>
    requires std::is_integral_v<T>
std::vector<T> pow_quad(std::vector<T> &input_vector) {
    libio::output::print("[IN]: " + std::string("")); //weird construction does not work without std::string
    libio::output::lineArrayOutput(input_vector, ", ");
    for (auto &elem: input_vector) {
        elem *= elem;
    }
    libio::output::print("\n" + std::string("")); //weird construction does not work without std::string
    libio::output::print("[OUT]: " + std::string("")); //weird construction does not work without std::string
    libio::output::lineArrayOutput(input_vector, ", ");
    return input_vector;
}

int main() {
    constexpr int f_value = 4;
    std::vector input_vector = {-1, 4, 8};
    pow_quad(f_value);
    pow_quad(input_vector);
}
