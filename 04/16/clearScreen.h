#include <iostream>

inline void clearScreen() { std::cout << "\033[2J\033[1;1H"; }