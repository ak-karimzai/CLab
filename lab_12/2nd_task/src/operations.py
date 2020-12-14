from ctypes import *

lib = None
try:
    lib = CDLL("./libarr.so")
except:
    print("Library wrong path or not created!")
    exit(-1)

_left_rotation = _copy_perf_nums =  None
try:
    _left_rotation = lib.left_rotation
    _left_rotation.argtypes = (POINTER(c_int), c_int, c_int)
    _left_rotation.restype = (c_int)
    _copy_perf_nums = lib.copy_perf_nums
    _copy_perf_nums.argtypes = (POINTER(c_int), c_int, POINTER(c_int), c_int)
    _copy_perf_nums.restype = (c_int)
except:
    print('cant load library!')
    exit(-1)

def left_rotation(arr, n):
    c_arr = (c_int * len(arr))(*arr)
    arr_len = c_int(len(arr))
    pos = c_int(n)
    res = _left_rotation(c_arr, arr_len, pos)
    return res, list(c_arr)

def get_full_sq_nums(arr):
    c_arr = (c_int * len(arr))(*arr)
    arr_size = c_int(len(arr))
    arr_res = None
    res_size = c_int(0)
    res = _copy_perf_nums(c_arr, arr_size, None, res_size)
    if res:
        arr_res = (c_int * res)()
        res_size = c_int(res)
        res = _copy_perf_nums(c_arr, arr_size, arr_res, res_size)
    return res, list(arr_res)