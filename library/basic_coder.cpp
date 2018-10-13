#include "basic_coder.h"

basic_coder::basic_coder(std::istream &sr, std::ostream &dst, size_t buf_sz) :
        src_file(sr), dst_file(dst),
        buffer_size(buf_sz){
    if (!sr.good())
        throw std::runtime_error("Source file doesn't exist");
    if (!dst.good())
        throw std::runtime_error("Destination file name is invalid");
    h_tree = std::unique_ptr<tree>(new tree());
}

basic_coder::~basic_coder() = default;
