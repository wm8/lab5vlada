// Copyright 2022 wm8

#include <gtest/gtest.h>
#include "Stack.h"
#include <string>
#include "TestStruct.h"
using std::string;
TEST(unit_test, head_test)
{
  Stack<string> stack{};
  for(int i=0; i != 5; i++) {
    std::string s = std::to_string(i);
    stack.push(s);
  }
  ASSERT_EQ("4", stack.head());
}
TEST(unit_test, pop_test1)
{
  Stack<string> stack{};
  for(int i=0; i != 5; i++) {
    std::string s = std::to_string(i);
    stack.push(s);
  }
  [[maybe_unused]] auto t = stack.pop();
  ASSERT_EQ("4", t);
}
TEST(unit_test, pop_test2)
{
  Stack<string> stack{};
  for(int i=0; i != 5; i++) {
    std::string s = std::to_string(i);
    stack.push(s);
  }
  [[maybe_unused]] auto t = stack.pop();
  ASSERT_EQ("3", stack.head());
}
TEST(unit_test, struct_test)
{
  Stack<TestStruct> stack;
  for(int i=0; i !=5; i++) {
    TestStruct t(i);
    stack.push(t);
  }
  [[maybe_unused]] auto t = stack.pop();
  ASSERT_EQ(3, stack.head().id);
}

