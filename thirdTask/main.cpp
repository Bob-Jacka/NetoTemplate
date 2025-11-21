#include <string>
#include <vector>

import Libio;

template<typename T>
    requires std::is_integral_v<T> || std::is_floating_point_v<T>
struct Summator {
private:
    T sum = 0;
    int count = 0;

public:
    Summator() = default;

    ~Summator() = default;

    [[nodiscard]] T get_sum() const {
        return sum;
    }

    [[nodiscard]] int get_count() const {
        return count;
    }

    void operator()(T num) {
        if (num % 3 == 0) {
            sum += num;
            ++count;
        }
    }
};

int main() {
    Summator<int> summator;
    const std::vector nums = {4, 1, 3, 6, 25, 54};

    for (const auto &num: nums) {
        summator(num);
    }
    libio::output::print(std::string("[IN]: "));
    libio::output::lineArrayOutput(nums);

    libio::output::println("\n[OUT]: get_sum() = " + std::to_string(summator.get_sum()));
    libio::output::println("[OUT]: get_count() = " + std::to_string(summator.get_count()));
}
