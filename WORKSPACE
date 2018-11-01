load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
  name = "googletest",
  url = "https://github.com/google/googletest/archive/release-1.8.1.zip",
  strip_prefix = "googletest-release-1.8.1",
  sha256 = "927827c183d01734cc5cfef85e0ff3f5a92ffe6188e0d18e909c5efebf28a0c7",
)

new_local_repository(
    name = "kosta_github_fitnessecppslim",
    path = "third_party/fitnesse-cppslim/",
    build_file = "third_party/BUILD.fitnesse-cppslim"
)

git_repository(
  name = "com_github_nelhage_rules_boost",
  commit = "239ce40e42ab0e3fe7ce84c2e9303ff8a277c41a",
  remote = "https://github.com/nelhage/rules_boost",
)

# initialize boost
load("@com_github_nelhage_rules_boost//:boost/boost.bzl", "boost_deps")
boost_deps()
