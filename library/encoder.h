#ifndef HUFFMAN_ENCODER_H
#define HUFFMAN_ENCODER_H

#include "basic_coder.h"


class encoder : basic_coder {
public:
    encoder(std::istream &sr,  std::ostream &dst);

    void encode();

private:
    void count_bytes();

    void compress();
};


#endif //HUFFMAN_ENCODER_H
