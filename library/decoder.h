#ifndef HUFFMAN_DECODER_H
#define HUFFMAN_DECODER_H


#include "basic_coder.h"

class decoder : basic_coder {
public:
    decoder(std::istream &sr,  std::ostream &dst);

    void decode();

private:
    void decompress();

    void read_dictionary();
};


#endif //HUFFMAN_DECODER_H
