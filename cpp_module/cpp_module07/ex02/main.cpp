#include <iostream>
#include <Array.hpp>

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++) {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++) {
        if (mirror[i] != numbers[i]) {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try {
        numbers[-2] = 0;
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    try {
        numbers[MAX_VAL] = 0;
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++) {
        numbers[i] = rand();
    }
    delete [] mirror;//

    std::cout << "test = [0, 1, 2, 3, 4]" << std::endl;
    Array<int> test(5);
    for (int i = 0; i < 5; i++) {
        test[i] = i;
    }
    std::cout << "test.size() : " << test.size() << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << test[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "copytest = [0, 1, 4, 9, 16]" << std::endl;
    Array<int> copyTest(test);
    for (int i = 0; i < 5; i++) {
        copyTest[i] = i * i;
    }
    std::cout << "copyTest.size() : " << copyTest.size() << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << copyTest[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "test = [0, 1, 2, 3, 4]" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << test[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
