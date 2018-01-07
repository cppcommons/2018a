#include <variant>
#include <string>
#include <iostream>
#include <boost/variant.hpp>
using namespace std;

struct do_double : boost::static_visitor<void>
{
	template<typename T>
	  void operator()( T& t ) const { t = t + t; }
};

int main()
{
	//typedef std::variant<int, std::string, long double> myvar;
	typedef std::variant<int, char *, long double> myvar;
	std::cout << sizeof(myvar) << std::endl;
	typedef boost::variant<int, char *> myvar3;
	std::cout << sizeof(myvar3) << std::endl;
	//std::variant<int, std::string> v;
	myvar vv;
	vv = 123;
	std::cout << vv.index() << std::get<int>(vv) << std::endl;
	vv = (char *)"abc";
	//std::cout << std::get<std::string>(v) << std::endl;
	std::cout << vv.index() << std::get<char *>(vv) << std::endl;

	typedef boost::variant<int,double,string> myvar2;
	std::cout << sizeof(myvar2) << std::endl;
	//boost::variant<int,double,string> v;
	myvar2 v;
	v = -2;
	assert( v.which() == 0 );           // 中身がintなことを確認
	cout << boost::get<int>(v) << endl; // intを取り出し

	v = 3.14;
	assert( v.which() == 1 ); // 中身がdoubleなことを確認
	cout << v << endl;        // 実は表示だけならget<...>は要らない

	v = "hoge";
	assert( v.which() == 2 );        // 中身がstringなことを確認
	apply_visitor( do_double(), v ); // Visitorを投げる
	cout << v << endl;

	return 0;
}
