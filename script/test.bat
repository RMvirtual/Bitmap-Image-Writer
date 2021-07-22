cls
cd ../test/src/maths-tests
bazel test --test_output=errors --test_summary=terse //src/maths-tests:hello_test
cd ../../../script
