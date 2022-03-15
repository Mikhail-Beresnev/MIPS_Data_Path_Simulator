#include "mem.h"

string data_memory(string write_data, string address, string mem_write, string mem_read) {
    if (mem_write == mem_read && mem_write == "1") {
        // error
        return "ERROR";
    }
    if (mem_write == "1") {
        dataX[address] = write_data;
        // dataX.insert(make_pair(address, write_data));
        // return nothing
        return "ERROR"; // if this is accesed, it is an error
    }

    if (mem_read == "1") {
        return dataX[address];
    }
    return "0";

}

// TODO: write a one time function to add stuff into dataX memory