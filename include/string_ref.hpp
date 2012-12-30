#include <cstddef>
#include <string>

namespace std {

  // basic_string_ref helpers
  template <class charT, class String>
  inline const charT* string_ref_begin(const String& s)
  {
    return s.c_str();
  }
  template <class charT, class String>
  inline const charT* string_ref_end(const String& s)
  {
    return s.c_str() + s.size();
  }

  // class basic_string_ref
  template <typename charT, typename traits = char_traits<charT>>
  class basic_string_ref {
    public:
    // types
    typedef charT value_type;
    typedef const charT* pointer;
    typedef const charT* const_pointer;
    typedef const charT& reference;
    typedef const charT& const_reference;
    typedef const charT* const_iterator; // See [string.ref.iterators]
    typedef const charT* iterator; // [Footnote: Because basic_string_ref refers to a constant sequence, iterator and const_iterator are the same type. --end footnote]
//    typedef std::reverse_iterator<const_iterator> const_reverse_iterator; typedef const_reverse_iterator reverse_iterator;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    static /*constexpr*/ const size_type npos = size_type(-1);

    // [string.ref.cons], construct/copy
    /*constexpr*/ basic_string_ref() /*noexcept*/;
    /*constexpr*/ basic_string_ref(const basic_string_ref&) /*noexcept*/ /*= default*/;
    basic_string_ref& operator=(const basic_string_ref&) /*noexcept*/ /*= default*/;
    /*constexpr*/ basic_string_ref(const charT* str);
    /*constexpr*/ basic_string_ref(const charT* str, size_type len);

    template <class String>
    basic_string_ref(const String& s)
      : _beg(string_ref_begin<charT>(s)), _end(string_ref_end<charT>(s)) {}

    // [string.ref.iterators], iterators
    /*constexpr*/ const_iterator begin() const /*noexcept*/ { return _beg; }
    /*constexpr*/ const_iterator end() const /*noexcept*/ { return _end; }

    // [string.ref.capacity], capacity
    /*constexpr*/ size_type size() const /*noexcept*/ { return _end - _beg; }
    /*constexpr*/ size_type length() const /*noexcept*/;
    /*constexpr*/ size_type max_size() const /*noexcept*/;
    /*constexpr*/ bool empty() const /*noexcept*/ { return size() == 0; }

  private:
    const charT* _beg;
    const charT* _end;
  };

  typedef basic_string_ref<char> string_ref;

}  // namespace std
