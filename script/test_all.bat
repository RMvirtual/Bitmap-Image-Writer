cls

@echo off

bazel test --test_output=all --test_summary=detailed //test/src:all_tests

@echo on