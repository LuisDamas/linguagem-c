#pragma once

int compare_int(const void*p1, const void*p2);
int compare_string(const void*p1, const void*p2);
void *seq_search(const void *key, void *base, size_t n_items, size_t size, int (*compare)(const void *, const void*));
void *seq_search_v2(const void *key, void *base, size_t n_items, size_t size, int (*compare)(const void *, const void*));

void print_int_array(int v[], int n);
void print_string_array(char* v[], int n);
