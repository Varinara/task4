#include "basic_coder.h"

basic_coder::basic_coder(std::istream &sr, std::ostream &dst, size_t buf_sz) :
        src_file(sr), dst_file(dst),
        buffer_size(buf_sz){
    h_tree = std::unique_ptr<tree>(new tree());
}

basic_coder::~basic_coder() = default;
