module;

/**
 Custom library for actions in Netology C++ course.
 Version - 1.14.0
 This library could be a module, but yes, later rewritten to module with experimental functions.
 Some kind of Boost library for poor people.
*/

#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>
#include <sstream>

// #define EXPERIMENTAL //uncomment this line to turn on experimental library features

#ifdef EXPERIMENTAL //define functions and include other libraries if experimental tag is defined
#include <filesystem>
#include <cmath>
#endif

export module Libio;

/**
 * Unified namespace for libio.
 */
export namespace libio {
    using cint [[maybe_unused]] = const int; //constant custom integer type

    /**
     * Contains different output logic
     */
    namespace output {
        /**
         * Print given generic message in console with new line. By default, equal to "".
         * @warning If using C++23 - use std::println.
         * @param str string to output
         * @tparam T generic parameter of type to console print
         */
        template<typename T = std::string>
        void println(const T &str = "\n") {
            if (std::cout.good()) {
                std::cout << str << std::endl;
            }
        }

        /**
         * Print given generic message in console without new line.
         * @warning If using C++23 - use std::print.
         * @tparam T generic type
         * @param str string to output
         * @param separator text separator
         */
        template<typename T>
        void print(const T &str, std::string separator = "") {
            if (std::cout.good()) {
                std::cout << str << separator;
            }
        }

        /**
         * Function for array output with separator.
         * Older brother of dynamicArrayOutput
         * @param array generic array pointer
         * @param array_size size of array.
         * @param separator separator value between elements
         * @param is_inline I do not know why I do this.
         */
        template<typename T>
        void lineArrayOutput(const T *array, const int array_size, const std::string &separator = " ",
                             const bool is_inline = false) {
            for (int i = 0; i < array_size - 1; ++i) {
                std::cout << array[i] << separator;
            }
            std::cout << array[array_size - 1];

            if (!is_inline) {
                std::cout << std::endl;
            }
        }

        /**
         * Output container from STL into console
         * @tparam T generic type
         * @param array standard container
         * @param separator separator string
         * @param endsymbol symbol at the end of output sequence
         */
        template<typename T>
            requires std::copyable<T>
        void lineArrayOutput(T array, const std::string &separator = " ", const std::string &endsymbol = "") {
            const size_t array_size = array.size();
            int i = 0;
            for (; i < array_size - 1; ++i) {
                std::cout << array[i] << separator;
            }
            std::cout << array[i] << endsymbol;
        }

        /**
         * New technology parametrized function for array output with old innovations
         * @tparam T generic type
         * @param array generic array pointer.
         * @param size size of the array.
         * @param reverse order of array output, seq or reverse.
         * @param separator separator value between elements
         */
        template<typename T>
        void dynamicArrayOutput(const T *array, const int size, const bool reverse = false, const std::string &separator = " ") {
            if (reverse) {
                for (int i = size - 1; i >= 0; --i) {
                    std::cout << array[i] << separator;
                }
            } else {
                for (int i = 0; i < size; ++i) {
                    std::cout << array[i] << separator;
                }
            }
            std::cout << std::endl;
        }

#ifdef EXPERIMENTAL
        /**
        * Print pyramid object one line by line
        * @param array
        * @param n
        */
        export void print_pyramid(const int *array, const int n) {
            for (int i = 0; i < n; ++i) {
                const int level = (i == 0) ? 0 : static_cast<int>(std::floor(std::log2(static_cast<double>(i + 1))));

                if (i == 0) {
                    std::cout << level << " root " << array[i] << '\n';
                } else {
                    const int p = (i - 1) / 2;
                    const char *side = (i == 2 * p + 1) ? "left" : "right";
                    std::cout << level << " " << side << " (" << array[p] << ") " << array[i] << '\n';
                }
            }
        }

        /**
         *
         * @param array pyramid object in array
         * @param i
         */
        export void print_one_element(const int *array, const int i) {
            const int level = (i == 0) ? 0 : static_cast<int>(std::floor(std::log2(static_cast<double>(i + 1))));

            if (i == 0) {
                std::cout << level << " root " << array[i] << '\n';
            } else {
                const int p = (i - 1) / 2;
                const char *side = (i == 2 * p + 1) ? "left" : "right";
                std::cout << level << " " << side << " (" << array[p] << ") " << array[i] << '\n';
            }
        }

#endif
    }

    /**
     * Namespace for string actions in libio
     */
    namespace string {
        std::vector<std::string> split(std::string const &input) {
            std::stringstream ss(input);
            std::vector<std::string> result;
            std::string word;
            while (ss >> word) {
                result.push_back(word);
            }
            return result;
        }
    }

    /**
     * Contains different input logic.
     */
    namespace input {
        /**
         * Writes down int value into variable by address
         * @param variableAddress address of variable to output data to it.
         */
        inline void intUserInput(int &variableAddress) {
            if (std::cin.good()) {
                std::cin >> variableAddress;
            }
        }

        /**
         * Writes down long value into variable by address
         * @param variableAddress address of variable to output data to it.
         */
        inline void longUserInput(long &variableAddress) {
            if (std::cin.good()) {
                std::cin >> variableAddress;
            }
        }

        /**
         * Writes down string into variable by address
         * @param variableAddress address of variable to output data to it.
         */
        inline void stringUserInput(std::string &variableAddress) {
            if (std::cin.good()) {
                std::cin >> variableAddress;
            }
        }

        /**
         * Writes down value into variable by address.
         * @tparam T generic type.
         * @param variableAddress address of variable to output data to it.
         */
        template<typename T>
        void userInput(T &variableAddress) {
            if (std::cin.good()) {
                std::cin >> variableAddress;
            }
        }
    }

    /**
     * Contains arrays actions
     */
    namespace array {
        /**
         * Delete dynamically allocated array
         * @tparam T generic type.
         * @param array array of generic type.
         * @param rows rows count in this array.
         */
        template<typename T>
        void deleteDynamicArray(T *array, const int rows) {
            for (int i = 0; i < rows; ++i) {
                delete[] array[i];
            }
            delete[] array;
        }

        /**
         * Create one dimensional array of generic type
         * @tparam T type for values in array
         * @param rows rows count
         * @return constructed array of generic type
         */
        template<typename T>
        T *create1DArray(const int rows) {
            const auto dyn_array = new T[rows];
            for (int i = 0; i < rows; ++i) {
                dyn_array[i] = 0;
            }
            return dyn_array;
        }

        /**
         * Inline function for creating 2d generic array
         * @param rows rows of the array
         * @param cols columns of the array
         * @tparam T generic param for type of the objects in array
         * @return: initialized 2d generic array
         */
        template<typename T>
        T **create2DArray(const int rows, const int cols) {
            const auto dyn_array = new T *[rows];
            for (int i = 0; i < rows; ++i) {
                dyn_array[i] = new T *[cols];
            }
            return dyn_array;
        }

#ifdef EXPERIMENTAL
        /**
         * Inline function for creating Nd (arrays upper more than 2) generic array
         * @param rows rows of the array
         * @param cols columns of the array`
         * @return: initialized Nd generic array
         */
        template<typename T>
        T **createNDArray(const int rows, const int cols) {
            const auto dyn_array = new T *[rows];
            for (int i = 0; i < rows; ++i) {
                dyn_array[i] = new T *[cols];
            }
            return dyn_array;
        }

        std::tuple<int *, int, int> increase_dynamic_array(int *arr, int logical_size, int actual_size) {
            if (arr != nullptr) {
                actual_size *= 2;
                auto new_arr = new int[actual_size];
                for (int i = 0; i < logical_size; ++i) {
                    new_arr[i] = arr[i];
                }
                delete[] arr;
                return {new_arr, logical_size, actual_size};
            }
            std::cerr << "Ошибка! Невозможно выделить дополнительную память для массива" << "\n";
            throw;
        }
#endif
    }

    /**
     * Contains file actions.
     * Ex. write or create.
     */
    namespace file {
        /**
         * Creates file for read and write.
         * @param fileName name of the file, create if not exists.
         * @return file handler.
         */
        inline std::ofstream createWriteFile(const std::string &fileName) {
            std::ofstream file(fileName);
            return file;
        }

        /**
         * Read file line by line.
         * @param fileName name of the file.
         * @return vector with lines.
         */
        inline std::vector<std::string> readFile(const std::string &fileName) {
            auto lines = std::vector<std::string>();
            if (std::ifstream file(fileName); file.is_open()) {
                std::string line;
                while (std::getline(file, line)) {
                    lines.emplace_back(line);
                }
                file.close();
                return lines;
            }
            std::cerr << "Error reading file " << fileName << std::endl;
            return {};
        }

        /**
         * Write file line by line.
         * @param fileName name of the file to write into.
         * @param lines vector value of lines of text.
         * @return output file handler.
         */
        inline std::ofstream writeFile(const std::string &fileName, const std::vector<std::string> &lines) {
            auto out = std::ofstream(fileName);
            for (const auto &line: lines) {
                out << line << std::endl;
            }
            return out;
        }

        /**
         * Function for receiving few lines from file.
         * @tparam T generic type.
         * @param fileName name of the file.
         * @param count how many lines to get.
         * @return vector with string values.
         */
        template<typename T>
        std::vector<T> getFewLinesFrom(const std::string &fileName, const int count) {
            std::ifstream file(fileName);
            auto lines = std::vector<T>();
            int inner_counter = 0;
            std::string line;
            while (std::getline(file, line)) {
                ++inner_counter;
                if (inner_counter == count) {
                    break;
                }
                lines.emplace_back(line);
            }
            return lines;
        }

#ifdef EXPERIMENTAL
        /**
         * Platform independent filepath getter.
         * @deprecated because crashes program due to strange path get.
         * @return string value of current path
         */
        inline std::string getCwd() {
                const std::filesystem::path currentPath = std::filesystem::current_path();
                return currentPath.string();
        }

#endif
    }
}
