#include <string>
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include "tree.h"
#include "encoder.h"
#include "decoder.h"

using namespace std;

void print_error(std::string message) {
    std::cerr << "Error! " << message << std::endl;
    std::cout.flush();
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        print_error("Wrong number of arguments: " + std::to_string(argc));
        cout << fixed << setprecision(0) << "TIME = " << clock() / (long double)CLOCKS_PER_SEC * 1000 << " ms\n";

        return 0;
    }
    std::string option = argv[1];
    std::string src_name = argv[2];
    std::string dst_name = argv[3];

    std::ifstream src_file(src_name, std::ios::in | std::ios::binary);
    std::ofstream dst_file(dst_name, std::ios::out | std::ios::binary);

    if (!src_file.is_open()) {
        std::cout << "Source file doesn't exist\n";
        return 0;
    }
    if (!dst_file.is_open()) {
        std::cout << "Destination file name is invalid\n";
        return 0;
    }
    std::istream& s = src_file;
    std::ostream& d = dst_file;

    if (option == "-e" || option == "--encode") {
        try {
            encoder e(s, d);
            e.encode();
        }
        catch (std::exception &ex) {
            print_error(ex.what());
            cout << fixed << setprecision(0) << "TIME = " << clock() / (long double)CLOCKS_PER_SEC * 1000 << " ms\n";

            return 1;
        }
    } else if (option == "-d" || option == "--decode") {
        try {
            decoder x(s, d);
            x.decode();
        }
        catch (std::exception &ex) {
            print_error(ex.what());
            cout << fixed << setprecision(0) << "TIME = " << clock() / (long double)CLOCKS_PER_SEC * 1000 << " ms\n";

            return 1;
        }
    } else {
        print_error("Unknown option: " + std::string(option));
        cout << fixed << setprecision(0) << "TIME = " << clock() / (long double)CLOCKS_PER_SEC * 1000 << " ms\n";

        return 0;
    }
    cout << fixed << setprecision(0) << "TIME = " << clock() / (long double)CLOCKS_PER_SEC * 1000 << " ms\n";

    return 0;
}