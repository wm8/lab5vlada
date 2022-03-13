// Copyright 2022 wm8

#ifndef LAB5_STACK_H
#define LAB5_STACK_H
#include <iostream>
using std::size_t;



template <typename T>
class Stack
{
 private:
  struct Node
  {
    Node(T _i) {current = _i; }
    T current;
    Node* previous;

  };
  Node* latest;
 public:
  Stack();
  explicit Stack(T* item);
  Stack(const Stack& st) = delete;
  Stack(const Stack&& st) noexcept;
  ~Stack();
  auto operator=(const Stack& st) -> Stack& = delete;
  auto operator=(Stack&& st) -> Stack&;
  void push(T&& value);
  template <typename ... Args>
  void push_emplace(Args&&... value);
  void push(T& value);
  T pop();
  const T& head() const;
  bool isEmpty(){ return latest == nullptr;}
};
template <typename T>
Stack<T>::Stack()
{
  latest = nullptr;
}
template <typename T>
Stack<T>::Stack(T* item)
{
  latest = new Node(*item);
}
template <typename T>
void Stack<T>::push(T&& value)
{
  if(latest == nullptr)
    latest = new Node(std::move(value));
  else
  {
    auto* t = latest;
    latest = new Node(std::move(value));
    latest->previous = t;
    if(latest == latest->previous)
      throw std::runtime_error("");
  }
}
template <typename T>
void Stack<T>::push(T& value)
{
  if(latest == nullptr)
    latest = new Node(value);
  else
  {
    auto* t = latest;
    latest = new Node(value);
    latest->previous = t;
  }
}
template <typename T>
T Stack<T>::pop()
{
  if(latest == nullptr)
    return nullptr;

  auto res = latest->current;
  auto* previous = latest->previous;
  latest->current = T();
  latest->previous = nullptr;
  delete(latest);
  latest = previous;
  return res;
}
template <typename T>
const T& Stack<T>::head() const {
  return latest->current;
}
template <typename T>
Stack<T>::Stack(const Stack&& st) noexcept
{
  this->latest = std::move(st.latest);
}
template <typename T>
auto Stack<T>::operator=(Stack&& st) -> Stack& {
  this->latest = std::move(st.latest);
}
template <typename T>
Stack<T>::~Stack() {
  delete(latest);
}
template <typename T>
template <typename... Args>
void Stack<T>::push_emplace(Args&&... args)
{
  if(latest == nullptr)
    latest = new Node(*(new T(std::forward<Args>(args)...)));
  else
  {
    auto* t = latest;
    latest = new Node(*(new T(std::forward<Args>(args)...)));
    latest->previous = t;
  }
}
#endif  // LAB5_STACK_H
