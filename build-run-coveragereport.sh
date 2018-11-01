#!/bin/bash
set -e

bazel coverage //...

COVERAGE_FILES=$(find bazel-out/ -name coverage.dat)
COVERAGE_HTML="\nCoverage output:"

for coverage_file in $COVERAGE_FILES; do
  DIR=$(dirname $coverage_file)/html
  rm -rf $DIR && mkdir $DIR

  lcov --rc lcov_branch_coverage=1 --remove ${coverage_file} "external/*" -o ${DIR}/info.dat # remove output for external libraries
  genhtml --branch-coverage --show-details -o ${DIR} -t "${coverage_file} test coverage" --num-spaces 4 ${DIR}/info.dat

  COVERAGE_HTML="${COVERAGE_HTML}\n${DIR}/index.html"
done
echo -e $COVERAGE_HTML