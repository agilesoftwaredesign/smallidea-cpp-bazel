#!/bin/bash
set -e

bazel build //acceptance_spec/...

BASE=$(dirname $(realpath $0))
FITNESSE_FIXTURE_BIN_PREFIX=${BASE}/bazel-bin/acceptance_spec/
FITNESSEJAR=${BASE}/third_party/fitnesse-standalone-2018-01-27.jar

cd ${BASE}/acceptance_spec/
java -Dslim.port=0 -Dfixture.path=${FITNESSE_FIXTURE_BIN_PREFIX} -jar ${FITNESSEJAR} -p 8080
