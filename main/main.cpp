#include <iostream>
#include "foo/foo.h"

int main(int argc, char **argv) {
    std::string who = "world";
    if (argc > 1) {
        who = argv[1];
    }

    std::cout << "Hello " << who << std::endl;

    Foo foo;
    std::cout << foo.hi() << std::endl;
    return 0;
}
