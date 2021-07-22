cls
cd src/maths
bazel test --test_output=errors --test_summary=terse //src/maths:hello_test
cd ../..
