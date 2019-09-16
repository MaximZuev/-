#include <iostream>
#include "WordCounter.h"

int main(int argc, char **argv) {
    if(argc != 3)
        std::cout << "Wrong input\n";
    else {
        WordCounter counter;
        counter.Count(argv[1]);
        counter.Write(argv[2]);
    }
    return 0;
}
