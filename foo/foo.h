#ifndef SMALLIDEA_CPP_BAZEL_FOO_H
#define SMALLIDEA_CPP_BAZEL_FOO_H

#include <string>

class Foo {
public:
    std::string hi() const noexcept;

    int calculateMagicNumberBasedOn(int a, int b) const;
};

#endif //SMALLIDEA_CPP_BAZEL_FOO_H