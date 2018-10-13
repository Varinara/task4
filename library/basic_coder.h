#ifndef HUFFMAN_BASIC_CODER_H
#define HUFFMAN_BASIC_CODER_H

#include <iostream>
#include <fstream>
#include <utility>
#include <memory>
#include "tree.h"

class basic_coder {
protected:

    std::istream &src_file;
    std::ostream &dst_file;

    size_t buffer_size;

    std::unique_ptr<tree> h_tree;

    basic_coder(std::istream &src, std::ostream &dst, size_t buf_sz);

    ~basic_coder();
};


#endif //HUFFMAN_BASIC_CODER_H
