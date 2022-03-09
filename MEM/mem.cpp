#include "mem.h"

string data_memory(string write_data, string address, string mem_write, string mem_read) {
    if (mem_write == mem_read) {
        // error
        return "ERROR";
    }
    if (mem_write == "1") {
        data_memory.insert(make_pair(address, write_data));
        // return nothing possibly?
    }

    if (mem_read == "1") {
        return data_memory.at(address);
    }
}