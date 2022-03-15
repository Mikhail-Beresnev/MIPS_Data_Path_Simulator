#include "mem.h"

string data_memory(string write_data, string address, string mem_write, string mem_read) {
    if (mem_write == mem_read && mem_write == "1") {
        // error
        return "ERROR";
    }
    if (mem_write == "1") {
        data[address] = write_data;
        // data.insert(make_pair(address, write_data));
        // return nothing
        return "ERROR"; // if this is accesed, it is an error
    }

    if (mem_read == "1") {
        return data[address];
    }
    return "0";

}

// TODO: write a one time function to add stuff into data memory