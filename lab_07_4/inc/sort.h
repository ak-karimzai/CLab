typedef int (*compare)(void *lhs, void *rhs);
int compare_int(void *lhs, void *rhs);
void mysort(void *arr_lhs, size_t num_of_elements, const size_t size, compare comp);