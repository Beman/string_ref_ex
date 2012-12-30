#include "../include/string_ref.hpp"
#include <string>
#include <iostream>
#include <cassert>
#include <memory>
#include <cstring>

void f(const std::string_ref& sr)
{
  std::cout << std::string(sr.begin(), sr.end()) << std::endl;
  assert(sr.size() == 3U);
  assert(*sr.begin() == 'f');
  assert(*(sr.begin()+1) == 'o');
  assert(*(sr.begin()+2) == 'o');
}

class MyString
{
public:
  MyString(const char* s)
    : _size(std::strlen(s)), _ptr(new char [_size+1])
  {
    std::strcpy(_ptr.get(), s);
  }
  std::size_t length() const { return _size; }
  const char* cptr() const { return _ptr.get(); }

private:
  std::size_t _size;
  std::shared_ptr<char> _ptr;
};

template <class charT>
inline const char* string_ref_begin(const MyString& s)
{
  return s.cptr();
}

template <class charT>
inline const char* string_ref_end(const MyString& s)
{
  return s.cptr() + s.length();
}

int main()
{
  std::string s("foo");
  f(s);
  MyString ms("foo");
  f(ms);
  return 0;
}
