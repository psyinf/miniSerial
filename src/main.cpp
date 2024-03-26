#include <iostream>
#include <serial/serial.h>
#include <fmt/format.h>

int main(int argc, char** argv)
try
{
    constexpr auto port = "COM1";

    std::cout << "Using Port: ";
    std::cout << port << std::endl;
    auto serialPort = serial::Serial(port, 115200);
    if (!serialPort.isOpen()) { throw std::runtime_error(fmt::format("Port {} not open", port)); }
    serialPort.write("Hello, World!\n");
    std::string message{};
    serialPort.readline(message);
    std::cout << message << std::endl;
    return 0;
}
catch (const std::exception& e)
{
    std::cerr << "Exception: " << e.what() << std::endl;
}
catch (...)
{
    std::cerr << " Unhandled unstructured Exception: " << std::endl;
}
