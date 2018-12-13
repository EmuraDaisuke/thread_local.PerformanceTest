


#include	<vector>
#include	<thread>
#include	"./Lapse.h"



constexpr unsigned int nTest = 0x1000000;



struct Test {
	~Test(){}
	
	Test():mp(ma){}
	
	char* Func(){ return mp++; }
	
	char ma[nTest];
	char* mp;
};

thread_local Test v;

Test& get_v(){ return v; }



void test()
{
	std::vector<std::thread> at(std::thread::hardware_concurrency());
	
	{	// 
		Lapse l;
		for (auto& t : at) t = std::thread([=]{ for (unsigned int n = nTest; n; --n) v.Func(); });
		for (auto& t : at) t.join();
	}
	
	{	// 
		Lapse l;
		for (auto& t : at) t = std::thread([=]{ decltype(auto) rv = get_v(); for (unsigned int n = nTest; n; --n) rv.Func(); });
		for (auto& t : at) t.join();
	}
}



int main(int argc, char* argv[])
{
	test();
	test();
	return 0;
}
