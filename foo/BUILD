cc_library(
    name = "foo",
    srcs = ["foo.cpp"],
    hdrs = ["foo.h"],
    visibility = [
        "//acceptance_spec:__pkg__",
        "//main:__pkg__",
    ],
)

cc_test(
    name = "foo_test",
    timeout = "short",
    srcs = ["foo_spec.cpp"],
    deps = [
        ":foo",
        "@googletest//:gtest_main",
    ],
)
