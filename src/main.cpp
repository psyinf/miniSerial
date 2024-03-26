#include <iostream>
#include <serial/serial.h>
#include <fmt/format.h>

using namespace std;

void serialReadToStandardOut(serial::Serial& serialPort)
{
    string message{};
    serialPort.readline(message);
    // TODO: maybe implement verbose version
    cout << message << endl;
}

int main(int argc, char** argv)
try
{
    /* definition */
    constexpr auto port = "COM1"; // TODO: inmplement port detection
    string         message{};
    auto           serialPort = serial::Serial(port, 115200);

    /* beging user interaction */
    cout << "Using Port: ";
    cout << port << endl;

    /* check for port*/
    if (!serialPort.isOpen()) { throw std::runtime_error(fmt::format("Port {} not open", port)); }

    /* begin serial communication with cc*/
    serialPort.write("\n");
    serialReadToStandardOut(serialPort);

    /* login cc*/
    serialPort.write("root");
    serialReadToStandardOut(serialPort);
    serialPort.write("trumpf123");
    serialReadToStandardOut(serialPort);

    /* user interaction */
    cout << "Please insert USB-device and press enter" << endl;
    cin.ignore();

    /* begin copy process from usb*/
    serialPort.write("\n");
    serialReadToStandardOut(serialPort);
    serialPort.write("cp /media/usb/interfaces /etc/network/interfaces");
    serialReadToStandardOut(serialPort);
     serialPort.write("cp /media/usb/dnsmasq_eth0.conf /home/etc/");
    serialReadToStandardOut(serialPort);
   serialPort.write("cp /media/usb/dnsmasq_eth1.conf /home/etc/");
    serialReadToStandardOut(serialPort);
		serialPort.write("reboot");

		//TODO: wait for reboot, detect finished boot
		//
		//TODO: ping 192.168.3.7 to check, if the issue is fixed

    return 0;
}
catch (const exception& e)
{
    cerr << "Exception: " << e.what() << endl;
}
catch (...)
{
    cerr << " Unhandled unstructured Exception: " << endl;
}
