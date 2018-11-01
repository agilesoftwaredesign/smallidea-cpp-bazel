#include <gmock/gmock.h>
#include "foo/foo.h"

using namespace ::testing;

class FooFixture : public ::testing::Test {
public:
    Foo unit_;
    const Foo &const_unit_{unit_};
};

TEST_F(FooFixture, hi_typical) {
    std::cout << "hi_typical" << std::endl;
    ASSERT_THAT(unit_.hi(), Eq("hi"));
}

TEST_F(FooFixture, bar) {
    ASSERT_THAT(const_unit_.calculateMagicNumberBasedOn(2, 3), Eq(13));
}