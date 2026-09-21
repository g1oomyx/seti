#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>
using namespace std;
int main() {

    string filename1 = "..\\..\\klient.txt";
    string filename2 = "..\\..\\server.txt";
    while (true) {
        ifstream in(filename1, ios::app);
        if (!in.is_open()) {
            cerr << "Wrong\n";
            return 1;
        }
        double ves, rost;
        in >> ves >> rost;
        in.close();
        double imt;
        imt = ves / (rost*rost);
        ofstream out(filename2);
        out << imt <<"\n";
        out.close();
        this_thread::sleep_for(chrono::seconds(1));
    }
}
