#include <iostream>

class hello_world{
    public:
        hello_world() { 
            std::cout << "hello world" << std::endl;
        }
};

int main() {
    hello_world hw;
    return 0;
}
