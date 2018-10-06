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
    if (option == "-e" || option == "--encode") {
        try {
            encoder e(src_name, dst_name);
            e.encode();
        }
        catch (std::exception &ex) {
            print_error(ex.what());
            cout << fixed << setprecision(0) << "TIME = " << clock() / (long double)CLOCKS_PER_SEC * 1000 << " ms\n";

            return 1;
        }
    } else if (option == "-d" || option == "--decode") {
        try {
            decoder d(src_name, dst_name);
            d.decode();
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