#include <iostream>
#include <serial/serial.h>
#include <fmt/format.h>
int main(int argc, char** argv)
try
{
    constexpr auto port = "COM20";

    auto serialPort = serial::Serial(port, 9600);
    if (!serialPort.isOpen()) { throw std::runtime_error(fmt::format("Port {} not open", port)); }
    // for testing write
    serialPort.write("Hello, World!");
    // read one character
    auto ret_buffer = std::vector<std::uint8_t>(1); // TODO: @Tim use std::byte for cstddef header if available
    if (0 < serialPort.read(ret_buffer)) 
    {
        //interpret the received value as number of spam-bytes
        //spam the receiver
        for (auto i = static_cast<int>(ret_buffer.at(0)); i-- > 0;)
        {
            serialPort.write("Haha\n");
        }
    }

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
