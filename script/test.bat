cls
bazel test --test_output=all --test_summary=terse //test/src/maths-tests:vector_tests
bazel test --test_output=all --test_summary=terse //test/src/maths-tests:binary_ops_tests
bazel test --test_output=all --test_summary=terse //test/src/common-tests:array_tests
