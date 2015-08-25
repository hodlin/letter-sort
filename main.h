#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <fstream>

size_t input_size(const char *f_name);

void read_set(const char *f_name, char* set);

void selection_sort(char* set, size_t set_size);

void write_set(const char *f_name, char* set, size_t in_size);

#endif // MAIN_H

