typedef int (*compare)(void *lhs, void *rhs);

void mysort(void *arr_lhs, void *arr_rhs, const size_t size, compare comp);
int compare_int(void *lhs, void *rhs);