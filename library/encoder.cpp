#include "encoder.h"

void encoder::count_bytes() {
    std::vector<char> buffer(buffer_size);
    while (src_file) {
        src_file.read(buffer.data(), buffer_size);
        h_tree->update_dict(buffer.data(), static_cast<size_t>(src_file.gcount()));
    }
}

void encoder::compress() {
    bit_sequence bs(1);
    std::vector<char> buffer(buffer_size);
    while (src_file) {
        src_file.read(buffer.data(), buffer_size);
        auto compressed = h_tree->compress(buffer.data(), static_cast<size_t>(src_file.gcount()), bs);
        dst_file.write((char *) compressed->get_data(), compressed->size());
    }
    if (bs.bit_size() > 0)
        dst_file.write((char *) bs.get_data(), 1);
}

void encoder::encode() {
    count_bytes();
    h_tree->build();
    auto dict = h_tree->get_dict();
    dst_file.write(dict.data(), dict.size());
    src_file.clear();
    src_file.seekg(0, std::ifstream::beg); // pointer in the begin
    compress();
}

encoder::encoder(std::ifstream &sr, std::ofstream &dst) : basic_coder(sr, dst, 8 * 1024 * 1024) {}
