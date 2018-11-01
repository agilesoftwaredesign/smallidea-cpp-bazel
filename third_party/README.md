# third_party
Following the [guide for third party](https://docs.bazel.build/versions/master/best-practices.html#third-party-dependencies) on bazel:
 
    * Either declare them as remote repositories in the WORKSPACE file.
    * Or put them in a directory called third_party/ under your workspace directory.

## googletest
[Googletest](https://github.com/google/googletest/) has been referenced in the `WORKSPACE` file.

## fitnesse-cppslim
Source: https://github.com/Kosta-Github/fitnesse-cppslim, Commit: 75afa54827685737b49352cbed86f9562bd7227b

fitnesse-cppslim has been directly added to the `third_party` folder as the github source does contains an outdated
version of standalone fitnesse server.

Alternative, fitnesse-cppslim in `WORKSPACE`:

    new_git_repository(
      name = "kosta_github_fitnessecppslim",
      remote = "https://github.com/Kosta-Github/fitnesse-cppslim.git",
      commit = "75afa54827685737b49352cbed86f9562bd7227b",
      build_file_content = """cc_library(
        name = "fitnessecppslim",
        srcs = ["SampleFixtures/main.cpp"],
        hdrs = glob(["fitnesse/cppslim/*.h"]),
        licenses = ["unencumbered"],
        linkopts = ["-pthread"],
        visibility = ["//visibility:public"],
        deps = ["@boost//:system"],
    )"""
    )