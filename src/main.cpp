#include <iostream>
#include <boost/format.hpp>

int main()
{
    []() {
        std::cout << boost::format("hola %1%") % 123 << std::endl;
    }();
    return 0;
}
