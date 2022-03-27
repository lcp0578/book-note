## 第9章 字符串
- C++字符串是基于`basic_string`模板类的。

		typedef basic_string<char, char_traits<char>, allocator<char> > string;
		typedef basic_string<wchar_t, char_traits<wchar_t>, allocator<wchar_t> > wstring;
		typedef basic_string<char16_t, char_traits<char16_t>, allocator<char16_t> > u16string;
		typedef basic_string<char32_t, char_traits<char32_t>, allocator<char32_t> > u32string;