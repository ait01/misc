#include <iostream>
#include <chrono>
#include "version.hh"
#include "misc.hh"

int main([[maybe_unused]] int argc, char *argv[])
{
    std::cout << argv[0] << " Version " << VERSION_MAJOR << "." << VERSION_MINOR << std::endl;
    std::cout << "The C++ version is " << __cplusplus << '.' << std::endl;
    auto begin = std::chrono::steady_clock::now();

    checkTypes();
    checkLocale();
    checkIo();
    checkRandom();

    auto end = std::chrono::steady_clock::now();
    std::cout << "The program took " << (end-begin).count() << std::endl;
    std::cout << "The program took " << std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count() << " nanoseconds." << std::endl;
    std::cout << "The program took " << std::chrono::duration_cast<std::chrono::microseconds>(end-begin).count() << " microseconds." << std::endl;
    std::cout << "The program took " << std::chrono::duration_cast<std::chrono::milliseconds>(end-begin).count() << " milliseconds." << std::endl;

    return 0;
}
