template<typename T>
class Test {
	int wrong;
	int correct;
public:
	Test() :wrong(0), correct(0) {}
	void test(const char* s, T elvart_kimenet, T bemenet) {
		if (elvart_kimenet == bemenet) {
			correct++;
			std::cout << "OK! " << s << std::endl;
		}
		else {
			std::cout << "FALSE! " << s << std::endl;
			wrong++;
		}
	}
	void report() {
		std::cout << std::endl << "ALL/OK " << wrong + correct << "/" << correct << std::endl << std::endl;
	}
};