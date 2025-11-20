#include <string>
#include <vector>

import Libio;

template<typename T>
    requires std::is_integral_v<T> || std::is_floating_point_v<T>
struct Summator {
private:
    std::vector<T> nums;

    [[nodiscard]] T get_sum() const {
        T sum = 0;
        for (auto &i: nums) {
            if (i % 3 == 0) {
                sum += i;
            }
        }
        return sum;
    }

    [[nodiscard]] int get_count() const {
        int size = 0;
        for (auto &i: nums) {
            if (i % 3 == 0) {
                ++size;
            }
        }
        return size;
    }

    static bool is_useful(const int num) {
        return num % 3 == 0;
    }

public:
    Summator() = default;

    ~Summator() = default;

    void operator()(const std::vector<T> &nums) {
        this->nums = nums;
        libio::output::print(std::string("[IN]: "));
        libio::output::lineArrayOutput(nums, " ", "\n");
        libio::output::print("[OUT]: get_sum() = " + std::to_string(get_sum()) + "\n");
        libio::output::print("[OUT]: get_count() = " + std::to_string(get_count()) + "\n");
    }
};

int main() {
    Summator<int> summator;
    const std::vector nums = {4, 1, 3, 6, 25, 54};
    summator(nums);
}
