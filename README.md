# SmallIdea of a project in Bazel
Take a look at the code and the scripts:

* ```build-run-spec.sh```
* ```build-run-acceptance-spec.sh```
* ```build-run-coveragereport.sh```
* ```start-fitnesse.sh```

[Bazel](https://bazel.build/) is used as a build tool. Bazel optimize among other things for
* incremental and
* reliable builds.

## Using in CLion
Fetch the [Bazel IDE integration](https://docs.bazel.build/versions/master/ide.html)
for [CLion](https://plugins.jetbrains.com/plugin/9554-bazel).

CLion uses the ```.bazelproject``` to determine which rules (targets) to build,
which folders to display and which additional language to support. 

## Running in CLI
Build all

    bazel build //...
    
Build all starting from local folder
    
    bazel build ...

Building only one specific rule

    bazel build //libfoo:libfoo_test

Running one specific rule

    bazel run //main:main

Running all test

    bazel test //... --test_output=all

## Using Docker
By using a minimal docker container, you fix and provide a minimal viable environment for building.

    FROM ubuntu:18.04
    COPY bazel-0.18.0-installer-linux-x86_64.sh /
    RUN apt-get update && \
      apt-get install -y --no-install-recommends git=1:2.17.1-1ubuntu0.3 ca-certificates=20180409 unzip=6.0-21ubuntu1 && \
      apt-get install -y --no-install-recommends gcc=4:7.3.0-3ubuntu2.1 g++=4:7.3.0-3ubuntu2.1 && \
      chmod +x bazel-0.18.0-installer-linux-x86_64.sh && \
      /bazel-0.18.0-installer-linux-x86_64.sh --user && \
      rm /bazel-*
