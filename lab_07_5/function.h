int file_count_objs(FILE *file);
int *read_objs_from_file(FILE *file, const int num_of_objs);
int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);
void write_objs_in_file(FILE *file, const int *arr_lhs, const int *arr_rhs);
void mysort(void *arr_lhs, size_t num_of_elements, const size_t size, compare comp);