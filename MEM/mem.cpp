#include "mem.h"

string data_memory(string write_data, string address, string mem_write, string mem_read) {
    if (mem_write == mem_read) {
        // error
        return "ERROR";
    }
    if (mem_write == "1") {
        data.insert(make_pair(address, write_data));
        // return nothing
        return "0";
    }

    if (mem_read == "1") {
        return data.at(address);
    }
}

// TODO: write a one time function to add stuff into data memory