#pragma once

int stricmp(char *s1, char *s2);

int search_list_sequential(MYLIST *ptr, char*string_to_search);
int search_ordered_list_sequential(MYLIST *ptr, char*stringToSearch);
int bin_search_iterative(MYLIST *ptr, char*string_to_search);
int bin_search_recursive(MYLIST *ptr, char*string_to_search);
int bin_search_recursive_stat(MYLIST *ptr, char*string_to_search);
