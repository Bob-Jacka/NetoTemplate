#include "Table.hpp"
import Libio;

int main() {
    Table<int> table(2, 3);
    table[0][0] = 100;
    table[1][2] = 42;

    libio::output::println(table[0][0]);
    libio::output::println(table[1][2]);
    libio::output::println(table.size()); //size
}
