// Copyright 2022 wm8

#ifndef LAB5_TESTSTRUCT_H
#define LAB5_TESTSTRUCT_H
struct TestStruct
{
  TestStruct()
  {
    id = 0;
  }
  ~TestStruct()
  {
    id = 0;
  }
  explicit TestStruct(int _id) {id = _id;}
  TestStruct(TestStruct* pStruct) {
    this->id = pStruct->id;
  }
  friend std::ostream& operator<< (std::ostream& stream, const TestStruct& t) {
    stream << t.id;
    return stream;
  }
  int id;
};
#endif  // LAB5_TESTSTRUCT_H
