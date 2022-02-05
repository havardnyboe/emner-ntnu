#include "std_lib_facilities.h"
#include "uitilities.h"

void testCallByValue() {
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    int result = incrementByValueNumTimes(v0, increment, iterations);
    std::cout << "v0: " << v0
              << " increment: " << increment
              << " iterations: " << iterations
              << " result: " << result << std::endl;
}

void testCallByValueReference() {
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    std::cout << "v0: " << v0
              << " increment: " << increment
              << " iterations: " << iterations;
    incrementByValueNumTimesRef(v0, increment, iterations);
    std::cout << " result: " << v0 << std::endl;
}
void testString() {}