## 第9章 字符串
- C++字符串是基于`basic_string`模板类的。

		typedef basic_string<char, char_traits<char>, allocator<char> > string;
		typedef basic_string<wchar_t, char_traits<wchar_t>, allocator<wchar_t> > wstring;
		typedef basic_string<char16_t, char_traits<char16_t>, allocator<char16_t> > u16string;
		typedef basic_string<char32_t, char_traits<char32_t>, allocator<char32_t> > u32string;
- 字符串应用

		#include <iostream>
		#include <fstream>
		#include <string>
		#include <vector>
		
		using namespace std;
		
		class header_body
		{
			string body;
		public:
			header_body() = default;
			header_body(const string& b) : body(b) {}
			string get_body() const { return body; }
			vector<pair<string, string>> subitems() {
				vector<pair<string, string>> subitems;
				if (body.find(";") == body.npos) return subitems;
				size_t start = 0;
				size_t end = start;
				while (end != body.npos) {
					while (start != body.length() && isspace(body[start])) {
						start++;
					}
					if (start == body.length()) break;
		
					string name = "";
					string value = "";
					size_t eq = body.find('=', start);
					end = body.find(';', start);
		
					if (eq == body.npos) {
						if (end == body.npos)
							name = body.substr(start);
						else
							name = body.substr(start, end - start);
					}
					else {
						if (end == body.npos) {
							name = body.substr(start, eq - start);
							value = body.substr(eq + 1);
						}
						else {
							if (eq < end) {
								name = body.substr(start, eq - start);
								value = body.substr(eq + 1, end - eq -1);
							}
							else {
								name = body.substr(start, end - start);
							}
						}
					}
					subitems.push_back(make_pair(name, value));
					start = end + 1;
				}
				return subitems;
			}
		};
		
		class email
		{
			using iter = vector<pair<string, header_body>>::iterator;
			vector<pair<string, header_body>> headers;
			string body;
		public:
			email() : body("") {}
		
			//访问器
			string get_body() const { return body; }
			string get_headers() const {
				string all = "";
				for (auto a : headers) {
					all += a.first + ": " + a.second.get_body();
					all += "\n";
				}
				return all;
			};
			iter begin() { return headers.begin(); }
			iter end() { return headers.end(); }
		
			//第二阶段构造
			void parse(istream& fin);
		private:
			void process_headers(const vector<string>& lines);
		
		};
		
		void email::parse(istream& fin) {
			string line;
			vector<string> headerLines;
			while (getline(fin, line)) {
				if (line.empty()) {
					break;
				}
				headerLines.push_back(line);
			}
		
			process_headers(headerLines);
			while (getline(fin, line)) {
				if (line.empty()) 
					body.append("\n");
				else
					body.append(line);
			}
		}
		
		void email::process_headers(const vector<string>& lines) {
			string header = "";
			string body = "";
			for (string line : lines) {
				if (isspace(line[0])) {
					body.append(line);
				}
				else {
					if (!header.empty()) {
						headers.push_back(make_pair(header, body));
						header.clear();
						body.clear();
					}
		
					size_t pos = line.find(":");
					header = line.substr(0, pos);
					pos++;
					while (isspace(line[pos])) pos++;
					body = line.substr(pos);
				}
			}
		
			if (!header.empty()) {
				headers.push_back(make_pair(header, body));
			}
		}
		
		void usage()
		{
			cout << "usage: emlai_paser file" << endl;
		}
		
		int main(int argc, char* argv[])
		{
			if (argc <= 1) {
				usage();
				return 1;
			}
		
			ifstream stm;
			stm.open(argv[1], ios_base::in);
			if (!stm.is_open()) {
				usage();
				cout << "cannot open " << argv[1] << "\n";
				return 1;
			}
		
			email eml;
			eml.parse(stm);
			//cout << "get_headers"<< "\n" << eml.get_headers() << "\n";
			for (auto header : eml) {
				cout << header.first << " : ";
				vector<pair<string, string>> subItems = header.second.subitems();
				if (subItems.size() == 0) {
					cout << header.second.get_body() << "\n";
				}
				else {
					cout << "\n";
					for (auto sub : subItems) {
						cout << " " << sub.first;
						if (!sub.second.empty())
							cout << " = " << sub.second;
						cout << "\n";
					}
				}
			}
			cout << "get_body" << "\n" << eml.get_body() << "\n";
			return 0;
		}