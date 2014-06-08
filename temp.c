#line 463

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>
#include <errno.h>

//#include <unordered_map>

#define INLINE __attribute__((always_inline)) static
#define PURE __attribute__((pure))
#define MAYBE __attribute__((unused))




#include "khash.h"
KHASH_INIT(the_hash, uint32_t, uint64_t, 1, kh_int_hash_func, kh_int_hash_equal)


//The audacity to just include a .c file
#include "bstrlib.c"

#include "count.h"


KHASH_INIT(bstring_to_bstring, bstring, bstring, 1, calc_bstring_hash, biseq)
KHASH_INIT(bstring_to_int, bstring, int, 1, calc_bstring_hash, biseq)


//returns new value
#define kh_increment(type,ptr,value) ({\
    khiter_t k = kh_get(type, ptr, value);\
    int is_missing = (k == kh_end(ptr));\
    if(is_missing){\
        int ret;\
        k = kh_put(type, ptr, value, &ret);\
        kh_value(ptr,k)=0;\
    }\
    kh_value(ptr,k)++;kh_value(ptr,k);})

//returns pointer to the value, or null
#define kh_get_val_ptr(type,ptr,value) ({\
    khiter_t k = kh_get(type, ptr, value);\
    int is_missing = (k == kh_end(ptr));\
    is_missing ? NULL : &(kh_value(ptr,k));})


    typedef uint16_t	string_id_0;
    typedef uint16_t	string_id_1;
    typedef uint8_t	string_id_2;
    typedef uint16_t	string_id_3;
    typedef uint8_t	string_id_4;
    typedef uint8_t	string_id_5;
    typedef uint8_t	string_id_6;
    typedef uint16_t	string_id_7;
    typedef uint8_t	string_id_8;
    typedef uint8_t	string_id_9;
    typedef uint8_t	string_id_10;
    typedef uint8_t	string_id_11;
    typedef uint8_t	string_id_12;
    typedef uint16_t	string_id_13;
    typedef uint16_t	string_id_14;
    typedef uint16_t	string_id_15;
    typedef uint8_t	string_id_16;
    typedef uint16_t	string_id_17;
    typedef uint8_t	string_id_18;

#pragma pack(push)  /* push current alignment to stack */
#pragma pack(1)     /* set alignment to 1 byte boundary */
        struct friends_0 {
        string_id_1 col_1;
        string_id_2 col_2;
        string_id_3 col_3;
        string_id_8 col_8;
        string_id_10 col_10;
        string_id_11 col_11;
        string_id_12 col_12;
        string_id_15 col_15;
        string_id_16 col_16;
        string_id_17 col_17;
        string_id_18 col_18;
    };
    struct friends_1 {
        string_id_10 col_10;
        string_id_11 col_11;
        string_id_12 col_12;
        string_id_15 col_15;
        string_id_16 col_16;
        string_id_17 col_17;
        string_id_18 col_18;
    };
    struct friends_2 {
        string_id_8 col_8;
        string_id_10 col_10;
        string_id_11 col_11;
        string_id_12 col_12;
    };
    struct friends_3 {
        string_id_1 col_1;
        string_id_2 col_2;
        string_id_4 col_4;
        string_id_8 col_8;
        string_id_10 col_10;
        string_id_11 col_11;
        string_id_12 col_12;
        string_id_13 col_13;
        string_id_14 col_14;
        string_id_15 col_15;
        string_id_16 col_16;
        string_id_17 col_17;
        string_id_18 col_18;
    };
    struct friends_4 {
        string_id_4 col_4;
        string_id_13 col_13;
        string_id_14 col_14;
    };
    struct friends_5 {
        string_id_4 col_4;
        string_id_11 col_11;
    };
    struct friends_6 {
        string_id_18 col_18;
    };
    struct friends_7 {
        string_id_16 col_16;
        string_id_17 col_17;
    };
    struct friends_8 {
        string_id_10 col_10;
        string_id_11 col_11;
        string_id_12 col_12;
    };
    struct friends_9 {
        string_id_11 col_11;
    };
    struct friends_10 {
        string_id_4 col_4;
        string_id_13 col_13;
    };
    struct friends_11 {
        string_id_4 col_4;
    };
    struct friends_12 {
        string_id_0 col_0;
    };
    struct value_0 {
        string_id_7 col_7;
    };
    struct value_1 {
        string_id_7 col_7;
    };
    struct value_2 {
        string_id_7 col_7;
    };
    struct value_3 {
        string_id_3 col_3;
    };
    struct value_4 {
        string_id_3 col_3;
    };
    struct value_5 {
        string_id_1 col_1;
    };
    struct value_6 {
        string_id_1 col_1;
    };
    struct value_7 {
        string_id_15 col_15;
    };
    struct value_8 {
        string_id_8 col_8;
    };
    struct value_9 {
        string_id_10 col_10;
    };
    struct value_10 {
        string_id_14 col_14;
    };
    struct value_11 {
        string_id_13 col_13;
    };
    struct value_12 {
        string_id_1 col_1;
        string_id_6 col_6;
        string_id_4 col_4;
    };
    struct val_plus_friends_0 {
        struct value_0 val;
        struct friends_0 friends;
    };
    struct val_plus_friends_1 {
        struct value_1 val;
        struct friends_1 friends;
    };
    struct val_plus_friends_2 {
        struct value_2 val;
        struct friends_2 friends;
    };
    struct val_plus_friends_3 {
        struct value_3 val;
        struct friends_3 friends;
    };
    struct val_plus_friends_4 {
        struct value_4 val;
        struct friends_4 friends;
    };
    struct val_plus_friends_5 {
        struct value_5 val;
        struct friends_5 friends;
    };
    struct val_plus_friends_6 {
        struct value_6 val;
        struct friends_6 friends;
    };
    struct val_plus_friends_7 {
        struct value_7 val;
        struct friends_7 friends;
    };
    struct val_plus_friends_8 {
        struct value_8 val;
        struct friends_8 friends;
    };
    struct val_plus_friends_9 {
        struct value_9 val;
        struct friends_9 friends;
    };
    struct val_plus_friends_10 {
        struct value_10 val;
        struct friends_10 friends;
    };
    struct val_plus_friends_11 {
        struct value_11 val;
        struct friends_11 friends;
    };
    struct val_plus_friends_12 {
        struct value_12 val;
        struct friends_12 friends;
    };

#pragma pack(pop)   /* restore original alignment from stack */

//#define struct_hash(struct_type) jenkins_hash((char *)(&struct_hash_val), sizeof(struct struct_type))

PURE INLINE uint32_t struct_hash_value_0 (struct value_0 val){
    return jenkins_hash((char *)(&val), sizeof(struct value_0));
}
PURE INLINE uint32_t struct_hash_value_1 (struct value_1 val){
    return jenkins_hash((char *)(&val), sizeof(struct value_1));
}
PURE INLINE uint32_t struct_hash_value_2 (struct value_2 val){
    return jenkins_hash((char *)(&val), sizeof(struct value_2));
}
PURE INLINE uint32_t struct_hash_value_3 (struct value_3 val){
    return jenkins_hash((char *)(&val), sizeof(struct value_3));
}
PURE INLINE uint32_t struct_hash_value_4 (struct value_4 val){
    return jenkins_hash((char *)(&val), sizeof(struct value_4));
}
PURE INLINE uint32_t struct_hash_value_5 (struct value_5 val){
    return jenkins_hash((char *)(&val), sizeof(struct value_5));
}
PURE INLINE uint32_t struct_hash_value_6 (struct value_6 val){
    return jenkins_hash((char *)(&val), sizeof(struct value_6));
}
PURE INLINE uint32_t struct_hash_value_7 (struct value_7 val){
    return jenkins_hash((char *)(&val), sizeof(struct value_7));
}
PURE INLINE uint32_t struct_hash_value_8 (struct value_8 val){
    return jenkins_hash((char *)(&val), sizeof(struct value_8));
}
PURE INLINE uint32_t struct_hash_value_9 (struct value_9 val){
    return jenkins_hash((char *)(&val), sizeof(struct value_9));
}
PURE INLINE uint32_t struct_hash_value_10 (struct value_10 val){
    return jenkins_hash((char *)(&val), sizeof(struct value_10));
}
PURE INLINE uint32_t struct_hash_value_11 (struct value_11 val){
    return jenkins_hash((char *)(&val), sizeof(struct value_11));
}
PURE INLINE uint32_t struct_hash_value_12 (struct value_12 val){
    return jenkins_hash((char *)(&val), sizeof(struct value_12));
}
PURE INLINE int struct_equal_value_0 (struct value_0 a, struct value_0 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct value_0));
}
PURE INLINE int struct_equal_value_1 (struct value_1 a, struct value_1 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct value_1));
}
PURE INLINE int struct_equal_value_2 (struct value_2 a, struct value_2 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct value_2));
}
PURE INLINE int struct_equal_value_3 (struct value_3 a, struct value_3 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct value_3));
}
PURE INLINE int struct_equal_value_4 (struct value_4 a, struct value_4 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct value_4));
}
PURE INLINE int struct_equal_value_5 (struct value_5 a, struct value_5 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct value_5));
}
PURE INLINE int struct_equal_value_6 (struct value_6 a, struct value_6 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct value_6));
}
PURE INLINE int struct_equal_value_7 (struct value_7 a, struct value_7 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct value_7));
}
PURE INLINE int struct_equal_value_8 (struct value_8 a, struct value_8 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct value_8));
}
PURE INLINE int struct_equal_value_9 (struct value_9 a, struct value_9 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct value_9));
}
PURE INLINE int struct_equal_value_10 (struct value_10 a, struct value_10 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct value_10));
}
PURE INLINE int struct_equal_value_11 (struct value_11 a, struct value_11 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct value_11));
}
PURE INLINE int struct_equal_value_12 (struct value_12 a, struct value_12 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct value_12));
}
PURE INLINE uint32_t struct_hash_val_plus_friends_0 (struct val_plus_friends_0 val){
    return jenkins_hash((char *)(&val), sizeof(struct val_plus_friends_0));
}
PURE INLINE uint32_t struct_hash_val_plus_friends_1 (struct val_plus_friends_1 val){
    return jenkins_hash((char *)(&val), sizeof(struct val_plus_friends_1));
}
PURE INLINE uint32_t struct_hash_val_plus_friends_2 (struct val_plus_friends_2 val){
    return jenkins_hash((char *)(&val), sizeof(struct val_plus_friends_2));
}
PURE INLINE uint32_t struct_hash_val_plus_friends_3 (struct val_plus_friends_3 val){
    return jenkins_hash((char *)(&val), sizeof(struct val_plus_friends_3));
}
PURE INLINE uint32_t struct_hash_val_plus_friends_4 (struct val_plus_friends_4 val){
    return jenkins_hash((char *)(&val), sizeof(struct val_plus_friends_4));
}
PURE INLINE uint32_t struct_hash_val_plus_friends_5 (struct val_plus_friends_5 val){
    return jenkins_hash((char *)(&val), sizeof(struct val_plus_friends_5));
}
PURE INLINE uint32_t struct_hash_val_plus_friends_6 (struct val_plus_friends_6 val){
    return jenkins_hash((char *)(&val), sizeof(struct val_plus_friends_6));
}
PURE INLINE uint32_t struct_hash_val_plus_friends_7 (struct val_plus_friends_7 val){
    return jenkins_hash((char *)(&val), sizeof(struct val_plus_friends_7));
}
PURE INLINE uint32_t struct_hash_val_plus_friends_8 (struct val_plus_friends_8 val){
    return jenkins_hash((char *)(&val), sizeof(struct val_plus_friends_8));
}
PURE INLINE uint32_t struct_hash_val_plus_friends_9 (struct val_plus_friends_9 val){
    return jenkins_hash((char *)(&val), sizeof(struct val_plus_friends_9));
}
PURE INLINE uint32_t struct_hash_val_plus_friends_10 (struct val_plus_friends_10 val){
    return jenkins_hash((char *)(&val), sizeof(struct val_plus_friends_10));
}
PURE INLINE uint32_t struct_hash_val_plus_friends_11 (struct val_plus_friends_11 val){
    return jenkins_hash((char *)(&val), sizeof(struct val_plus_friends_11));
}
PURE INLINE uint32_t struct_hash_val_plus_friends_12 (struct val_plus_friends_12 val){
    return jenkins_hash((char *)(&val), sizeof(struct val_plus_friends_12));
}
PURE INLINE int struct_equal_val_plus_friends_0 (struct val_plus_friends_0 a, struct val_plus_friends_0 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct val_plus_friends_0));
}
PURE INLINE int struct_equal_val_plus_friends_1 (struct val_plus_friends_1 a, struct val_plus_friends_1 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct val_plus_friends_1));
}
PURE INLINE int struct_equal_val_plus_friends_2 (struct val_plus_friends_2 a, struct val_plus_friends_2 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct val_plus_friends_2));
}
PURE INLINE int struct_equal_val_plus_friends_3 (struct val_plus_friends_3 a, struct val_plus_friends_3 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct val_plus_friends_3));
}
PURE INLINE int struct_equal_val_plus_friends_4 (struct val_plus_friends_4 a, struct val_plus_friends_4 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct val_plus_friends_4));
}
PURE INLINE int struct_equal_val_plus_friends_5 (struct val_plus_friends_5 a, struct val_plus_friends_5 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct val_plus_friends_5));
}
PURE INLINE int struct_equal_val_plus_friends_6 (struct val_plus_friends_6 a, struct val_plus_friends_6 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct val_plus_friends_6));
}
PURE INLINE int struct_equal_val_plus_friends_7 (struct val_plus_friends_7 a, struct val_plus_friends_7 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct val_plus_friends_7));
}
PURE INLINE int struct_equal_val_plus_friends_8 (struct val_plus_friends_8 a, struct val_plus_friends_8 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct val_plus_friends_8));
}
PURE INLINE int struct_equal_val_plus_friends_9 (struct val_plus_friends_9 a, struct val_plus_friends_9 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct val_plus_friends_9));
}
PURE INLINE int struct_equal_val_plus_friends_10 (struct val_plus_friends_10 a, struct val_plus_friends_10 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct val_plus_friends_10));
}
PURE INLINE int struct_equal_val_plus_friends_11 (struct val_plus_friends_11 a, struct val_plus_friends_11 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct val_plus_friends_11));
}
PURE INLINE int struct_equal_val_plus_friends_12 (struct val_plus_friends_12 a, struct val_plus_friends_12 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct val_plus_friends_12));
}
PURE INLINE uint32_t struct_hash_friends_0 (struct friends_0 val){
    return jenkins_hash((char *)(&val), sizeof(struct friends_0));
}
PURE INLINE uint32_t struct_hash_friends_1 (struct friends_1 val){
    return jenkins_hash((char *)(&val), sizeof(struct friends_1));
}
PURE INLINE uint32_t struct_hash_friends_2 (struct friends_2 val){
    return jenkins_hash((char *)(&val), sizeof(struct friends_2));
}
PURE INLINE uint32_t struct_hash_friends_3 (struct friends_3 val){
    return jenkins_hash((char *)(&val), sizeof(struct friends_3));
}
PURE INLINE uint32_t struct_hash_friends_4 (struct friends_4 val){
    return jenkins_hash((char *)(&val), sizeof(struct friends_4));
}
PURE INLINE uint32_t struct_hash_friends_5 (struct friends_5 val){
    return jenkins_hash((char *)(&val), sizeof(struct friends_5));
}
PURE INLINE uint32_t struct_hash_friends_6 (struct friends_6 val){
    return jenkins_hash((char *)(&val), sizeof(struct friends_6));
}
PURE INLINE uint32_t struct_hash_friends_7 (struct friends_7 val){
    return jenkins_hash((char *)(&val), sizeof(struct friends_7));
}
PURE INLINE uint32_t struct_hash_friends_8 (struct friends_8 val){
    return jenkins_hash((char *)(&val), sizeof(struct friends_8));
}
PURE INLINE uint32_t struct_hash_friends_9 (struct friends_9 val){
    return jenkins_hash((char *)(&val), sizeof(struct friends_9));
}
PURE INLINE uint32_t struct_hash_friends_10 (struct friends_10 val){
    return jenkins_hash((char *)(&val), sizeof(struct friends_10));
}
PURE INLINE uint32_t struct_hash_friends_11 (struct friends_11 val){
    return jenkins_hash((char *)(&val), sizeof(struct friends_11));
}
PURE INLINE uint32_t struct_hash_friends_12 (struct friends_12 val){
    return jenkins_hash((char *)(&val), sizeof(struct friends_12));
}
PURE INLINE int struct_equal_friends_0 (struct friends_0 a, struct friends_0 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct friends_0));
}
PURE INLINE int struct_equal_friends_1 (struct friends_1 a, struct friends_1 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct friends_1));
}
PURE INLINE int struct_equal_friends_2 (struct friends_2 a, struct friends_2 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct friends_2));
}
PURE INLINE int struct_equal_friends_3 (struct friends_3 a, struct friends_3 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct friends_3));
}
PURE INLINE int struct_equal_friends_4 (struct friends_4 a, struct friends_4 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct friends_4));
}
PURE INLINE int struct_equal_friends_5 (struct friends_5 a, struct friends_5 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct friends_5));
}
PURE INLINE int struct_equal_friends_6 (struct friends_6 a, struct friends_6 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct friends_6));
}
PURE INLINE int struct_equal_friends_7 (struct friends_7 a, struct friends_7 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct friends_7));
}
PURE INLINE int struct_equal_friends_8 (struct friends_8 a, struct friends_8 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct friends_8));
}
PURE INLINE int struct_equal_friends_9 (struct friends_9 a, struct friends_9 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct friends_9));
}
PURE INLINE int struct_equal_friends_10 (struct friends_10 a, struct friends_10 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct friends_10));
}
PURE INLINE int struct_equal_friends_11 (struct friends_11 a, struct friends_11 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct friends_11));
}
PURE INLINE int struct_equal_friends_12 (struct friends_12 a, struct friends_12 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct friends_12));
}
KHASH_INIT(value_to_friends_0, struct value_0, struct friends_0, 1, struct_hash_value_0, struct_equal_value_0)
KHASH_INIT(value_to_friends_1, struct value_1, struct friends_1, 1, struct_hash_value_1, struct_equal_value_1)
KHASH_INIT(value_to_friends_2, struct value_2, struct friends_2, 1, struct_hash_value_2, struct_equal_value_2)
KHASH_INIT(value_to_friends_3, struct value_3, struct friends_3, 1, struct_hash_value_3, struct_equal_value_3)
KHASH_INIT(value_to_friends_4, struct value_4, struct friends_4, 1, struct_hash_value_4, struct_equal_value_4)
KHASH_INIT(value_to_friends_5, struct value_5, struct friends_5, 1, struct_hash_value_5, struct_equal_value_5)
KHASH_INIT(value_to_friends_6, struct value_6, struct friends_6, 1, struct_hash_value_6, struct_equal_value_6)
KHASH_INIT(value_to_friends_7, struct value_7, struct friends_7, 1, struct_hash_value_7, struct_equal_value_7)
KHASH_INIT(value_to_friends_8, struct value_8, struct friends_8, 1, struct_hash_value_8, struct_equal_value_8)
KHASH_INIT(value_to_friends_9, struct value_9, struct friends_9, 1, struct_hash_value_9, struct_equal_value_9)
KHASH_INIT(value_to_friends_10, struct value_10, struct friends_10, 1, struct_hash_value_10, struct_equal_value_10)
KHASH_INIT(value_to_friends_11, struct value_11, struct friends_11, 1, struct_hash_value_11, struct_equal_value_11)
KHASH_INIT(value_to_friends_12, struct value_12, struct friends_12, 1, struct_hash_value_12, struct_equal_value_12)
KHASH_INIT(val_plus_friends_to_count_0, struct val_plus_friends_0, int, 1, struct_hash_val_plus_friends_0, struct_equal_val_plus_friends_0)
KHASH_INIT(val_plus_friends_to_count_1, struct val_plus_friends_1, int, 1, struct_hash_val_plus_friends_1, struct_equal_val_plus_friends_1)
KHASH_INIT(val_plus_friends_to_count_2, struct val_plus_friends_2, int, 1, struct_hash_val_plus_friends_2, struct_equal_val_plus_friends_2)
KHASH_INIT(val_plus_friends_to_count_3, struct val_plus_friends_3, int, 1, struct_hash_val_plus_friends_3, struct_equal_val_plus_friends_3)
KHASH_INIT(val_plus_friends_to_count_4, struct val_plus_friends_4, int, 1, struct_hash_val_plus_friends_4, struct_equal_val_plus_friends_4)
KHASH_INIT(val_plus_friends_to_count_5, struct val_plus_friends_5, int, 1, struct_hash_val_plus_friends_5, struct_equal_val_plus_friends_5)
KHASH_INIT(val_plus_friends_to_count_6, struct val_plus_friends_6, int, 1, struct_hash_val_plus_friends_6, struct_equal_val_plus_friends_6)
KHASH_INIT(val_plus_friends_to_count_7, struct val_plus_friends_7, int, 1, struct_hash_val_plus_friends_7, struct_equal_val_plus_friends_7)
KHASH_INIT(val_plus_friends_to_count_8, struct val_plus_friends_8, int, 1, struct_hash_val_plus_friends_8, struct_equal_val_plus_friends_8)
KHASH_INIT(val_plus_friends_to_count_9, struct val_plus_friends_9, int, 1, struct_hash_val_plus_friends_9, struct_equal_val_plus_friends_9)
KHASH_INIT(val_plus_friends_to_count_10, struct val_plus_friends_10, int, 1, struct_hash_val_plus_friends_10, struct_equal_val_plus_friends_10)
KHASH_INIT(val_plus_friends_to_count_11, struct val_plus_friends_11, int, 1, struct_hash_val_plus_friends_11, struct_equal_val_plus_friends_11)
KHASH_INIT(val_plus_friends_to_count_12, struct val_plus_friends_12, int, 1, struct_hash_val_plus_friends_12, struct_equal_val_plus_friends_12)
KHASH_INIT(friends_to_count_0, struct friends_0, int, 1, struct_hash_friends_0, struct_equal_friends_0)
KHASH_INIT(friends_to_count_1, struct friends_1, int, 1, struct_hash_friends_1, struct_equal_friends_1)
KHASH_INIT(friends_to_count_2, struct friends_2, int, 1, struct_hash_friends_2, struct_equal_friends_2)
KHASH_INIT(friends_to_count_3, struct friends_3, int, 1, struct_hash_friends_3, struct_equal_friends_3)
KHASH_INIT(friends_to_count_4, struct friends_4, int, 1, struct_hash_friends_4, struct_equal_friends_4)
KHASH_INIT(friends_to_count_5, struct friends_5, int, 1, struct_hash_friends_5, struct_equal_friends_5)
KHASH_INIT(friends_to_count_6, struct friends_6, int, 1, struct_hash_friends_6, struct_equal_friends_6)
KHASH_INIT(friends_to_count_7, struct friends_7, int, 1, struct_hash_friends_7, struct_equal_friends_7)
KHASH_INIT(friends_to_count_8, struct friends_8, int, 1, struct_hash_friends_8, struct_equal_friends_8)
KHASH_INIT(friends_to_count_9, struct friends_9, int, 1, struct_hash_friends_9, struct_equal_friends_9)
KHASH_INIT(friends_to_count_10, struct friends_10, int, 1, struct_hash_friends_10, struct_equal_friends_10)
KHASH_INIT(friends_to_count_11, struct friends_11, int, 1, struct_hash_friends_11, struct_equal_friends_11)
KHASH_INIT(friends_to_count_12, struct friends_12, int, 1, struct_hash_friends_12, struct_equal_friends_12)
#define driving_column_bytes  4
#define MAX_FDS 6
unsigned char fd_to_ibuff[MAX_FDS][64*1024] = {  };
int  fd_to_ibuff_len[MAX_FDS]               = {  };
int  fd_to_ibuff_pos[MAX_FDS]               = {  };
char fd_to_ibuff_bit_pos[MAX_FDS]           = {  };
unsigned char fd_to_ibuff_bit_mask[MAX_FDS];

INLINE int read_some_bytes(int fd){
    //Only call when ibuff is empty
    int amt = read(fd,fd_to_ibuff[fd],64*1024-1);
    if(amt==-1){
        fprintf(stderr, "read error on fd %d, %d\n",fd,errno);
        exit(1);
    }
    fd_to_ibuff_len[fd]=amt;
    fd_to_ibuff_pos[fd]=0;
    fd_to_ibuff_bit_pos[fd]=0;
    fd_to_ibuff_bit_mask[fd]=128;

    return amt;
}


INLINE unsigned char read_bit(int fd){
    if(fd_to_ibuff_bit_pos[fd]==8){
        fd_to_ibuff_bit_pos[fd]=0;
        fd_to_ibuff_bit_mask[fd]=128;
        fd_to_ibuff_pos[fd]++;
    }
    if(fd_to_ibuff_pos[fd] > fd_to_ibuff_len[fd]-1){
        if(read_some_bytes(fd)==0){
            //OUT OF DATA
            die("Prematurely out of data.\n");
        }
    }
    unsigned char bit = (fd_to_ibuff[fd][fd_to_ibuff_pos[fd]] & fd_to_ibuff_bit_mask[fd]) ? 1 : 0;

    fd_to_ibuff_bit_pos[fd]++;
    fd_to_ibuff_bit_mask[fd] >>= 1;
    return bit;

}

INLINE uint32_t read_bits_as_number(int fd, int n_bits){
    uint32_t val = 0;

    for (int i=0;i < n_bits; i++){
        val <<= 1;
        val |= read_bit(fd);
    }
    return val;
}

INLINE int stream_finished(int fd){
    if(fd_to_ibuff_bit_pos[fd]==8){
        fd_to_ibuff_bit_pos[fd]=0;
        fd_to_ibuff_bit_mask[fd]=128;
        fd_to_ibuff_pos[fd]++;
    }
    if(fd_to_ibuff_pos[fd] > fd_to_ibuff_len[fd]-1){
        if(read_some_bytes(fd)==0){
            return 1;
        }else{
            return 0;
        }
    }else{
        return 0;
    }
}

INLINE void seek_till_byte_boundary(int fd){
    if(fd_to_ibuff_bit_pos[fd]>0){
        fd_to_ibuff_bit_pos[fd]=0;
        fd_to_ibuff_bit_mask[fd]=128;
        fd_to_ibuff_pos[fd]++;
    }
}

INLINE uint64_t read_rice(int fd, int k){
    uint64_t m = 1 << k;
    int q = 0;
    uint64_t x;
    int i;

    while (read_bit(fd)) {q++;}
    x = m * q;

    for (i=k-1; i>=0; i--) {x = x | (read_bit(fd) << i);}

    return x;
}

int main(int argc, char ** argv){

    const int BINARY = 4;
    const int BINARY2 = 5;



    const __uint128_t one = 1;
    //__uint128_t test=one<<5;


    int col_to_n_stored_vals[19]={0};


    uint64_t col_to_ref_count[19]={0};
    uint64_t col_to_ref_sum[19]={0};


    int col_to_string_pool_length[19]={0};
    bstring string_pool_0	[648];
    bstring string_pool_1	[297];
    bstring string_pool_2	[3];
    bstring string_pool_3	[35368];
    bstring string_pool_4	[134];
    bstring string_pool_5	[11];
    bstring string_pool_6	[124];
    bstring string_pool_7	[43325];
    bstring string_pool_8	[2];
    bstring string_pool_9	[3];
    bstring string_pool_10	[18];
    bstring string_pool_11	[12];
    bstring string_pool_12	[7];
    bstring string_pool_13	[635];
    bstring string_pool_14	[295];
    bstring string_pool_15	[339];
    bstring string_pool_16	[26];
    bstring string_pool_17	[673];
    bstring string_pool_18	[3];
    bstring * driving_col_string_pool = string_pool_3;
    string_id_0 stored_vals_0	[537];
    string_id_1 stored_vals_1	[246];
    string_id_2 stored_vals_2	[2];
    string_id_3 stored_vals_3	[0];
    string_id_4 stored_vals_4	[94];
    string_id_5 stored_vals_5	[11];
    string_id_6 stored_vals_6	[119];
    string_id_7 stored_vals_7	[83];
    string_id_8 stored_vals_8	[2];
    string_id_9 stored_vals_9	[3];
    string_id_10 stored_vals_10	[17];
    string_id_11 stored_vals_11	[11];
    string_id_12 stored_vals_12	[7];
    string_id_13 stored_vals_13	[411];
    string_id_14 stored_vals_14	[278];
    string_id_15 stored_vals_15	[125];
    string_id_16 stored_vals_16	[17];
    string_id_17 stored_vals_17	[308];
    string_id_18 stored_vals_18	[3];
    printf("%d	%d\n",(int)sizeof(struct friends_0),(int)sizeof(struct value_0));
    printf("%d	%d\n",(int)sizeof(struct friends_1),(int)sizeof(struct value_1));
    printf("%d	%d\n",(int)sizeof(struct friends_2),(int)sizeof(struct value_2));
    printf("%d	%d\n",(int)sizeof(struct friends_3),(int)sizeof(struct value_3));
    printf("%d	%d\n",(int)sizeof(struct friends_4),(int)sizeof(struct value_4));
    printf("%d	%d\n",(int)sizeof(struct friends_5),(int)sizeof(struct value_5));
    printf("%d	%d\n",(int)sizeof(struct friends_6),(int)sizeof(struct value_6));
    printf("%d	%d\n",(int)sizeof(struct friends_7),(int)sizeof(struct value_7));
    printf("%d	%d\n",(int)sizeof(struct friends_8),(int)sizeof(struct value_8));
    printf("%d	%d\n",(int)sizeof(struct friends_9),(int)sizeof(struct value_9));
    printf("%d	%d\n",(int)sizeof(struct friends_10),(int)sizeof(struct value_10));
    printf("%d	%d\n",(int)sizeof(struct friends_11),(int)sizeof(struct value_11));
    printf("%d	%d\n",(int)sizeof(struct friends_12),(int)sizeof(struct value_12));
    khash_t(value_to_friends_0) *value_to_most_popular_friends_0 = kh_init(value_to_friends_0);
    khash_t(value_to_friends_1) *value_to_most_popular_friends_1 = kh_init(value_to_friends_1);
    khash_t(value_to_friends_2) *value_to_most_popular_friends_2 = kh_init(value_to_friends_2);
    khash_t(value_to_friends_3) *value_to_most_popular_friends_3 = kh_init(value_to_friends_3);
    khash_t(value_to_friends_4) *value_to_most_popular_friends_4 = kh_init(value_to_friends_4);
    khash_t(value_to_friends_5) *value_to_most_popular_friends_5 = kh_init(value_to_friends_5);
    khash_t(value_to_friends_6) *value_to_most_popular_friends_6 = kh_init(value_to_friends_6);
    khash_t(value_to_friends_7) *value_to_most_popular_friends_7 = kh_init(value_to_friends_7);
    khash_t(value_to_friends_8) *value_to_most_popular_friends_8 = kh_init(value_to_friends_8);
    khash_t(value_to_friends_9) *value_to_most_popular_friends_9 = kh_init(value_to_friends_9);
    khash_t(value_to_friends_10) *value_to_most_popular_friends_10 = kh_init(value_to_friends_10);
    khash_t(value_to_friends_11) *value_to_most_popular_friends_11 = kh_init(value_to_friends_11);
    khash_t(value_to_friends_12) *value_to_most_popular_friends_12 = kh_init(value_to_friends_12);
    khash_t(val_plus_friends_to_count_0) *val_to_friends_to_count_0 = kh_init(val_plus_friends_to_count_0);
    khash_t(val_plus_friends_to_count_1) *val_to_friends_to_count_1 = kh_init(val_plus_friends_to_count_1);
    khash_t(val_plus_friends_to_count_2) *val_to_friends_to_count_2 = kh_init(val_plus_friends_to_count_2);
    khash_t(val_plus_friends_to_count_3) *val_to_friends_to_count_3 = kh_init(val_plus_friends_to_count_3);
    khash_t(val_plus_friends_to_count_4) *val_to_friends_to_count_4 = kh_init(val_plus_friends_to_count_4);
    khash_t(val_plus_friends_to_count_5) *val_to_friends_to_count_5 = kh_init(val_plus_friends_to_count_5);
    khash_t(val_plus_friends_to_count_6) *val_to_friends_to_count_6 = kh_init(val_plus_friends_to_count_6);
    khash_t(val_plus_friends_to_count_7) *val_to_friends_to_count_7 = kh_init(val_plus_friends_to_count_7);
    khash_t(val_plus_friends_to_count_8) *val_to_friends_to_count_8 = kh_init(val_plus_friends_to_count_8);
    khash_t(val_plus_friends_to_count_9) *val_to_friends_to_count_9 = kh_init(val_plus_friends_to_count_9);
    khash_t(val_plus_friends_to_count_10) *val_to_friends_to_count_10 = kh_init(val_plus_friends_to_count_10);
    khash_t(val_plus_friends_to_count_11) *val_to_friends_to_count_11 = kh_init(val_plus_friends_to_count_11);
    khash_t(val_plus_friends_to_count_12) *val_to_friends_to_count_12 = kh_init(val_plus_friends_to_count_12);
    khash_t(friends_to_count_0) *friends_to_count_0 = kh_init(friends_to_count_0);
    khash_t(friends_to_count_1) *friends_to_count_1 = kh_init(friends_to_count_1);
    khash_t(friends_to_count_2) *friends_to_count_2 = kh_init(friends_to_count_2);
    khash_t(friends_to_count_3) *friends_to_count_3 = kh_init(friends_to_count_3);
    khash_t(friends_to_count_4) *friends_to_count_4 = kh_init(friends_to_count_4);
    khash_t(friends_to_count_5) *friends_to_count_5 = kh_init(friends_to_count_5);
    khash_t(friends_to_count_6) *friends_to_count_6 = kh_init(friends_to_count_6);
    khash_t(friends_to_count_7) *friends_to_count_7 = kh_init(friends_to_count_7);
    khash_t(friends_to_count_8) *friends_to_count_8 = kh_init(friends_to_count_8);
    khash_t(friends_to_count_9) *friends_to_count_9 = kh_init(friends_to_count_9);
    khash_t(friends_to_count_10) *friends_to_count_10 = kh_init(friends_to_count_10);
    khash_t(friends_to_count_11) *friends_to_count_11 = kh_init(friends_to_count_11);
    khash_t(friends_to_count_12) *friends_to_count_12 = kh_init(friends_to_count_12);
    struct friends_0 most_popular_friends_0={0};
    struct friends_1 most_popular_friends_1={0};
    struct friends_2 most_popular_friends_2={0};
    struct friends_3 most_popular_friends_3={0};
    struct friends_4 most_popular_friends_4={0};
    struct friends_5 most_popular_friends_5={0};
    struct friends_6 most_popular_friends_6={0};
    struct friends_7 most_popular_friends_7={0};
    struct friends_8 most_popular_friends_8={0};
    struct friends_9 most_popular_friends_9={0};
    struct friends_10 most_popular_friends_10={0};
    struct friends_11 most_popular_friends_11={0};
    struct friends_12 most_popular_friends_12={0};
    typedef uint32_t driving_col_as_number;    int r=0;

    driving_col_as_number previous_driving_col_number=0;

    while(! stream_finished(BINARY)){

        const int driving_column = 3;
        const int driving_col_rice_bits = 17;
        const int n_predictors = 12+1;
        uint32_t col_was_predicted=0;
        uint16_t predictor_column_used=0;
        for(int i=0;i<n_predictors;i++){
            
            int need_predictor_bit=1;
            
            switch(i){
                case 0: {if(0==((~col_was_predicted) & ((one<<1)|(one<<2)|(one<<3)|(one<<8)|(one<<10)|(one<<11)|(one<<12)|(one<<15)|(one<<16)|(one<<17)|(one<<18)))){need_predictor_bit=0;} break;}
                case 1: {if(0==((~col_was_predicted) & ((one<<10)|(one<<11)|(one<<12)|(one<<15)|(one<<16)|(one<<17)|(one<<18)))){need_predictor_bit=0;} break;}
                case 2: {if(0==((~col_was_predicted) & ((one<<8)|(one<<10)|(one<<11)|(one<<12)))){need_predictor_bit=0;} break;}
                case 3: {if(0==((~col_was_predicted) & ((one<<1)|(one<<2)|(one<<4)|(one<<8)|(one<<10)|(one<<11)|(one<<12)|(one<<13)|(one<<14)|(one<<15)|(one<<16)|(one<<17)|(one<<18)))){need_predictor_bit=0;} break;}
                case 4: {if(0==((~col_was_predicted) & ((one<<4)|(one<<13)|(one<<14)))){need_predictor_bit=0;} break;}
                case 5: {if(0==((~col_was_predicted) & ((one<<4)|(one<<11)))){need_predictor_bit=0;} break;}
                case 6: {if(0==((~col_was_predicted) & ((one<<18)))){need_predictor_bit=0;} break;}
                case 7: {if(0==((~col_was_predicted) & ((one<<16)|(one<<17)))){need_predictor_bit=0;} break;}
                case 8: {if(0==((~col_was_predicted) & ((one<<10)|(one<<11)|(one<<12)))){need_predictor_bit=0;} break;}
                case 9: {if(0==((~col_was_predicted) & ((one<<11)))){need_predictor_bit=0;} break;}
                case 10: {if(0==((~col_was_predicted) & ((one<<4)|(one<<13)))){need_predictor_bit=0;} break;}
                case 11: {if(0==((~col_was_predicted) & ((one<<4)))){need_predictor_bit=0;} break;}
                case 12: {if(0==((~col_was_predicted) & ((one<<0)))){need_predictor_bit=0;} break;}
            }
            if(need_predictor_bit){
                fprintf(stderr,"P%d",i);
                if(read_bit(BINARY)){
                    predictor_column_used|=one<<i;
                    switch(i){
                        case 0: {col_was_predicted|=((one<<1)|(one<<2)|(one<<3)|(one<<8)|(one<<10)|(one<<11)|(one<<12)|(one<<15)|(one<<16)|(one<<17)|(one<<18));break;}
                        case 1: {col_was_predicted|=((one<<10)|(one<<11)|(one<<12)|(one<<15)|(one<<16)|(one<<17)|(one<<18));break;}
                        case 2: {col_was_predicted|=((one<<8)|(one<<10)|(one<<11)|(one<<12));break;}
                        case 3: {col_was_predicted|=((one<<1)|(one<<2)|(one<<4)|(one<<8)|(one<<10)|(one<<11)|(one<<12)|(one<<13)|(one<<14)|(one<<15)|(one<<16)|(one<<17)|(one<<18));break;}
                        case 4: {col_was_predicted|=((one<<4)|(one<<13)|(one<<14));break;}
                        case 5: {col_was_predicted|=((one<<4)|(one<<11));break;}
                        case 6: {col_was_predicted|=((one<<18));break;}
                        case 7: {col_was_predicted|=((one<<16)|(one<<17));break;}
                        case 8: {col_was_predicted|=((one<<10)|(one<<11)|(one<<12));break;}
                        case 9: {col_was_predicted|=((one<<11));break;}
                        case 10: {col_was_predicted|=((one<<4)|(one<<13));break;}
                        case 11: {col_was_predicted|=((one<<4));break;}
                        case 12: {col_was_predicted|=((one<<0));break;}
                    }
                }
            }
            
        }
        string_id vals[19]           ={0};
        string_id previous_row[19]   ={0};
        uint32_t copy_bits=0;
        uint32_t encoding_choice_bits=0;
        uint32_t do_store_bits=0;
        int literal_lengths[19];
        
        
        for (int c=0;c<19;c++){
            if(col_was_predicted & (one<<c)){
                continue;
            }

            unsigned char copy_bit = read_bit(BINARY);
            if(copy_bit){
                copy_bits|=(one<<c);
                warn("COPY  ");
            }

            //$encoding_list .= "COPY  " if $copy_bit;

            if(copy_bit != 1){
                unsigned char encoding_choice_bit = read_bit(BINARY);

                if(encoding_choice_bit){
                    encoding_choice_bits|=(one<<c);
                    if(read_bit(BINARY)){
                        do_store_bits|=(one<<c);
                        warn("LIT-1 ");
                    }else{
                        warn("LIT-0 ");
                    }

                }else{
                    warn("REF   ");
                }

                /*
                if(encoding_choice_bits[c]){
                    $encoding_list .= "LIT-$do_store_bits[$c] ";
                }else{
                    $encoding_list .= "REF   ";
                }
                */
            }
        }

        //warn "ROW $r: $encoding_list\n";

        seek_till_byte_boundary(BINARY);

        for (int c=0;c<19;c++){
            if(col_was_predicted & (one<<c)){
                continue;
            }

            if(encoding_choice_bits & (one<<c)){
                if(c == driving_column && r!=0){
                //only encode the difference
                }else{
                    int max_length=0;
                    switch(c){
                        case 0: max_length = 3;break;
                        case 1: max_length = 3;break;
                        case 2: max_length = 1;break;
                        case 3: max_length = 3;break;
                        case 4: max_length = 2;break;
                        case 5: max_length = 4;break;
                        case 6: max_length = 3;break;
                        case 7: max_length = 4;break;
                        case 8: max_length = 2;break;
                        case 9: max_length = 2;break;
                        case 10: max_length = 5;break;
                        case 11: max_length = 4;break;
                        case 12: max_length = 4;break;
                        case 13: max_length = 3;break;
                        case 14: max_length = 3;break;
                        case 15: max_length = 7;break;
                        case 16: max_length = 4;break;
                        case 17: max_length = 6;break;
                        case 18: max_length = 1;break;
                    }
                    int length_length = max_length;
                    literal_lengths[c] = read_bits_as_number(BINARY,length_length);
                }
            }
        }

        int dupes=1;
        while(read_bit(BINARY)==1){
            dupes++;
        }


        seek_till_byte_boundary(BINARY);

        for (int c=0;c<19;c++){
            if(col_was_predicted & (one<<c)){
                continue;
            }

            string_id val;

            if(copy_bits & (one<<c)){
                val = previous_row[c];
            }else{
                if((encoding_choice_bits & (one<<c))==0){
                    //Ref
                    int rice_bits = ((col_to_ref_count[c]>0) && (col_to_ref_sum[c]>0)) ?
                        log2_int((col_to_ref_sum[c]+col_to_n_stored_vals[c]-1)/(col_to_ref_count[c]+1))-1
                         : log2_int((col_to_n_stored_vals[c])/2)-1;
                    if(rice_bits < 0){
                        rice_bits = 0;
                    }



                    int stored_val_idx = read_rice(BINARY2, rice_bits);
                    switch(c){
                        case 0: val = stored_vals_0[stored_val_idx];break;
                        case 1: val = stored_vals_1[stored_val_idx];break;
                        case 2: val = stored_vals_2[stored_val_idx];break;
                        case 3: val = stored_vals_3[stored_val_idx];break;
                        case 4: val = stored_vals_4[stored_val_idx];break;
                        case 5: val = stored_vals_5[stored_val_idx];break;
                        case 6: val = stored_vals_6[stored_val_idx];break;
                        case 7: val = stored_vals_7[stored_val_idx];break;
                        case 8: val = stored_vals_8[stored_val_idx];break;
                        case 9: val = stored_vals_9[stored_val_idx];break;
                        case 10: val = stored_vals_10[stored_val_idx];break;
                        case 11: val = stored_vals_11[stored_val_idx];break;
                        case 12: val = stored_vals_12[stored_val_idx];break;
                        case 13: val = stored_vals_13[stored_val_idx];break;
                        case 14: val = stored_vals_14[stored_val_idx];break;
                        case 15: val = stored_vals_15[stored_val_idx];break;
                        case 16: val = stored_vals_16[stored_val_idx];break;
                        case 17: val = stored_vals_17[stored_val_idx];break;
                        case 18: val = stored_vals_18[stored_val_idx];break;
                    }
                    int swap_with = (20*stored_val_idx) / 21;

                    if((swap_with >= 0) && (swap_with != stored_val_idx)){
                        switch(c){
                            case 0:{
                                string_id_0 temp = stored_vals_0[stored_val_idx];
                                stored_vals_0[stored_val_idx] = stored_vals_0[swap_with];
                                stored_vals_0[swap_with] = temp;
                                break;
                            }
                            case 1:{
                                string_id_1 temp = stored_vals_1[stored_val_idx];
                                stored_vals_1[stored_val_idx] = stored_vals_1[swap_with];
                                stored_vals_1[swap_with] = temp;
                                break;
                            }
                            case 2:{
                                string_id_2 temp = stored_vals_2[stored_val_idx];
                                stored_vals_2[stored_val_idx] = stored_vals_2[swap_with];
                                stored_vals_2[swap_with] = temp;
                                break;
                            }
                            case 3:{
                                string_id_3 temp = stored_vals_3[stored_val_idx];
                                stored_vals_3[stored_val_idx] = stored_vals_3[swap_with];
                                stored_vals_3[swap_with] = temp;
                                break;
                            }
                            case 4:{
                                string_id_4 temp = stored_vals_4[stored_val_idx];
                                stored_vals_4[stored_val_idx] = stored_vals_4[swap_with];
                                stored_vals_4[swap_with] = temp;
                                break;
                            }
                            case 5:{
                                string_id_5 temp = stored_vals_5[stored_val_idx];
                                stored_vals_5[stored_val_idx] = stored_vals_5[swap_with];
                                stored_vals_5[swap_with] = temp;
                                break;
                            }
                            case 6:{
                                string_id_6 temp = stored_vals_6[stored_val_idx];
                                stored_vals_6[stored_val_idx] = stored_vals_6[swap_with];
                                stored_vals_6[swap_with] = temp;
                                break;
                            }
                            case 7:{
                                string_id_7 temp = stored_vals_7[stored_val_idx];
                                stored_vals_7[stored_val_idx] = stored_vals_7[swap_with];
                                stored_vals_7[swap_with] = temp;
                                break;
                            }
                            case 8:{
                                string_id_8 temp = stored_vals_8[stored_val_idx];
                                stored_vals_8[stored_val_idx] = stored_vals_8[swap_with];
                                stored_vals_8[swap_with] = temp;
                                break;
                            }
                            case 9:{
                                string_id_9 temp = stored_vals_9[stored_val_idx];
                                stored_vals_9[stored_val_idx] = stored_vals_9[swap_with];
                                stored_vals_9[swap_with] = temp;
                                break;
                            }
                            case 10:{
                                string_id_10 temp = stored_vals_10[stored_val_idx];
                                stored_vals_10[stored_val_idx] = stored_vals_10[swap_with];
                                stored_vals_10[swap_with] = temp;
                                break;
                            }
                            case 11:{
                                string_id_11 temp = stored_vals_11[stored_val_idx];
                                stored_vals_11[stored_val_idx] = stored_vals_11[swap_with];
                                stored_vals_11[swap_with] = temp;
                                break;
                            }
                            case 12:{
                                string_id_12 temp = stored_vals_12[stored_val_idx];
                                stored_vals_12[stored_val_idx] = stored_vals_12[swap_with];
                                stored_vals_12[swap_with] = temp;
                                break;
                            }
                            case 13:{
                                string_id_13 temp = stored_vals_13[stored_val_idx];
                                stored_vals_13[stored_val_idx] = stored_vals_13[swap_with];
                                stored_vals_13[swap_with] = temp;
                                break;
                            }
                            case 14:{
                                string_id_14 temp = stored_vals_14[stored_val_idx];
                                stored_vals_14[stored_val_idx] = stored_vals_14[swap_with];
                                stored_vals_14[swap_with] = temp;
                                break;
                            }
                            case 15:{
                                string_id_15 temp = stored_vals_15[stored_val_idx];
                                stored_vals_15[stored_val_idx] = stored_vals_15[swap_with];
                                stored_vals_15[swap_with] = temp;
                                break;
                            }
                            case 16:{
                                string_id_16 temp = stored_vals_16[stored_val_idx];
                                stored_vals_16[stored_val_idx] = stored_vals_16[swap_with];
                                stored_vals_16[swap_with] = temp;
                                break;
                            }
                            case 17:{
                                string_id_17 temp = stored_vals_17[stored_val_idx];
                                stored_vals_17[stored_val_idx] = stored_vals_17[swap_with];
                                stored_vals_17[swap_with] = temp;
                                break;
                            }
                            case 18:{
                                string_id_18 temp = stored_vals_18[stored_val_idx];
                                stored_vals_18[stored_val_idx] = stored_vals_18[swap_with];
                                stored_vals_18[swap_with] = temp;
                                break;
                            }
                        }

                    }


                    col_to_ref_sum[c]+=stored_val_idx;
                    col_to_ref_count[c]++;

                }else{
                    //Lit

                    if((c == driving_column) && (r!=0)){
                        //warn("driving\n");
                        //only encode the difference
                        driving_col_as_number diff = read_rice(BINARY2, driving_col_rice_bits);
                        driving_col_as_number new_val = previous_driving_col_number + diff;

                        previous_driving_col_number = new_val;
                        //Decode the number into a str
                        uint8_t buffer[driving_column_bytes]={0};
                        for(int i=driving_column_bytes-1;i>=0;i--){
                            buffer[i] = new_val & 0xFF;
                            new_val >>= 8;
                        }
                        //Add it to the pool
                        bstring val_str = blk2bstr(buffer,driving_column_bytes);
                        driving_col_string_pool[col_to_string_pool_length[c]] = val_str;
                        val=col_to_string_pool_length[c];
                        col_to_string_pool_length[c]++;
                    }else{
                        //Not delta encoded, just a plain old Lit
                        int length = literal_lengths[c];
                        uint8_t bits_per_char=8;
                        switch(c){
                            case 0: {bits_per_char=4;break;}
                            case 1: {bits_per_char=4;break;}
                            case 2: {bits_per_char=2;break;}
                            case 4: {bits_per_char=4;break;}
                            case 5: {bits_per_char=4;break;}
                            case 6: {bits_per_char=4;break;}
                            case 8: {bits_per_char=3;break;}
                            case 9: {bits_per_char=2;break;}
                            case 10: {bits_per_char=6;break;}
                            case 11: {bits_per_char=6;break;}
                            case 12: {bits_per_char=5;break;}
                            case 13: {bits_per_char=4;break;}
                            case 14: {bits_per_char=4;break;}
                            case 15: {bits_per_char=4;break;}
                            case 16: {bits_per_char=4;break;}
                            case 17: {bits_per_char=4;break;}
                            case 18: {bits_per_char=2;break;}
                        }

                        uint8_t buffer[length];

                        for (int i=0;i<length;i++){
                            uint8_t idx = read_bits_as_number(BINARY2, bits_per_char);
                            uint8_t this_char=0;
                            if(bits_per_char==8){
                                this_char=idx;//Default in case there is no alphabet
                            }else{
                                switch(c){
                                   case 0: {
                                       switch(idx){
                                           case 0: {this_char = 50;break;}
                                           case 1: {this_char = 51;break;}
                                           case 2: {this_char = 48;break;}
                                           case 3: {this_char = 56;break;}
                                           case 4: {this_char = 49;break;}
                                           case 5: {this_char = 57;break;}
                                           case 6: {this_char = 54;break;}
                                           case 7: {this_char = 55;break;}
                                           case 8: {this_char = 52;break;}
                                           case 9: {this_char = 53;break;}
                                       }
                                       break;
                                   }
                                   case 1: {
                                       switch(idx){
                                           case 0: {this_char = 54;break;}
                                           case 1: {this_char = 55;break;}
                                           case 2: {this_char = 53;break;}
                                           case 3: {this_char = 51;break;}
                                           case 4: {this_char = 52;break;}
                                           case 5: {this_char = 50;break;}
                                           case 6: {this_char = 49;break;}
                                           case 7: {this_char = 57;break;}
                                           case 8: {this_char = 48;break;}
                                           case 9: {this_char = 56;break;}
                                       }
                                       break;
                                   }
                                   case 2: {
                                       switch(idx){
                                           case 0: {this_char = 49;break;}
                                           case 1: {this_char = 51;break;}
                                           case 2: {this_char = 50;break;}
                                       }
                                       break;
                                   }
                                   case 4: {
                                       switch(idx){
                                           case 0: {this_char = 52;break;}
                                           case 1: {this_char = 50;break;}
                                           case 2: {this_char = 56;break;}
                                           case 3: {this_char = 54;break;}
                                           case 4: {this_char = 51;break;}
                                           case 5: {this_char = 48;break;}
                                           case 6: {this_char = 49;break;}
                                           case 7: {this_char = 53;break;}
                                           case 8: {this_char = 55;break;}
                                           case 9: {this_char = 57;break;}
                                       }
                                       break;
                                   }
                                   case 5: {
                                       switch(idx){
                                           case 0: {this_char = 52;break;}
                                           case 1: {this_char = 48;break;}
                                           case 2: {this_char = 54;break;}
                                           case 3: {this_char = 53;break;}
                                           case 4: {this_char = 51;break;}
                                           case 5: {this_char = 50;break;}
                                           case 6: {this_char = 56;break;}
                                           case 7: {this_char = 57;break;}
                                           case 8: {this_char = 49;break;}
                                       }
                                       break;
                                   }
                                   case 6: {
                                       switch(idx){
                                           case 0: {this_char = 50;break;}
                                           case 1: {this_char = 51;break;}
                                           case 2: {this_char = 48;break;}
                                           case 3: {this_char = 57;break;}
                                           case 4: {this_char = 54;break;}
                                           case 5: {this_char = 56;break;}
                                           case 6: {this_char = 49;break;}
                                           case 7: {this_char = 55;break;}
                                           case 8: {this_char = 52;break;}
                                           case 9: {this_char = 53;break;}
                                       }
                                       break;
                                   }
                                   case 8: {
                                       switch(idx){
                                           case 0: {this_char = 101;break;}
                                           case 1: {this_char = 78;break;}
                                           case 2: {this_char = 115;break;}
                                           case 3: {this_char = 89;break;}
                                           case 4: {this_char = 111;break;}
                                       }
                                       break;
                                   }
                                   case 9: {
                                       switch(idx){
                                           case 0: {this_char = 49;break;}
                                           case 1: {this_char = 48;break;}
                                           case 2: {this_char = 50;break;}
                                       }
                                       break;
                                   }
                                   case 10: {
                                       switch(idx){
                                           case 0: {this_char = 105;break;}
                                           case 1: {this_char = 110;break;}
                                           case 2: {this_char = 87;break;}
                                           case 3: {this_char = 32;break;}
                                           case 4: {this_char = 97;break;}
                                           case 5: {this_char = 83;break;}
                                           case 6: {this_char = 116;break;}
                                           case 7: {this_char = 79;break;}
                                           case 8: {this_char = 111;break;}
                                           case 9: {this_char = 100;break;}
                                           case 10: {this_char = 101;break;}
                                           case 11: {this_char = 115;break;}
                                           case 12: {this_char = 80;break;}
                                           case 13: {this_char = 56;break;}
                                           case 14: {this_char = 84;break;}
                                           case 15: {this_char = 50;break;}
                                           case 16: {this_char = 107;break;}
                                           case 17: {this_char = 120;break;}
                                           case 18: {this_char = 77;break;}
                                           case 19: {this_char = 88;break;}
                                           case 20: {this_char = 51;break;}
                                           case 21: {this_char = 108;break;}
                                           case 22: {this_char = 78;break;}
                                           case 23: {this_char = 55;break;}
                                           case 24: {this_char = 121;break;}
                                           case 25: {this_char = 117;break;}
                                           case 26: {this_char = 49;break;}
                                           case 27: {this_char = 99;break;}
                                           case 28: {this_char = 98;break;}
                                           case 29: {this_char = 73;break;}
                                           case 30: {this_char = 71;break;}
                                           case 31: {this_char = 85;break;}
                                           case 32: {this_char = 119;break;}
                                           case 33: {this_char = 114;break;}
                                           case 34: {this_char = 86;break;}
                                           case 35: {this_char = 104;break;}
                                           case 36: {this_char = 48;break;}
                                           case 37: {this_char = 46;break;}
                                           case 38: {this_char = 76;break;}
                                           case 39: {this_char = 65;break;}
                                           case 40: {this_char = 109;break;}
                                           case 41: {this_char = 57;break;}
                                           case 42: {this_char = 82;break;}
                                       }
                                       break;
                                   }
                                   case 11: {
                                       switch(idx){
                                           case 0: {this_char = 101;break;}
                                           case 1: {this_char = 114;break;}
                                           case 2: {this_char = 97;break;}
                                           case 3: {this_char = 111;break;}
                                           case 4: {this_char = 105;break;}
                                           case 5: {this_char = 83;break;}
                                           case 6: {this_char = 102;break;}
                                           case 7: {this_char = 116;break;}
                                           case 8: {this_char = 115;break;}
                                           case 9: {this_char = 66;break;}
                                           case 10: {this_char = 108;break;}
                                           case 11: {this_char = 99;break;}
                                           case 12: {this_char = 70;break;}
                                           case 13: {this_char = 78;break;}
                                           case 14: {this_char = 77;break;}
                                           case 15: {this_char = 79;break;}
                                           case 16: {this_char = 32;break;}
                                           case 17: {this_char = 112;break;}
                                           case 18: {this_char = 73;break;}
                                           case 19: {this_char = 119;break;}
                                           case 20: {this_char = 120;break;}
                                           case 21: {this_char = 69;break;}
                                           case 22: {this_char = 121;break;}
                                           case 23: {this_char = 104;break;}
                                           case 24: {this_char = 107;break;}
                                           case 25: {this_char = 67;break;}
                                           case 26: {this_char = 48;break;}
                                           case 27: {this_char = 76;break;}
                                           case 28: {this_char = 65;break;}
                                           case 29: {this_char = 110;break;}
                                           case 30: {this_char = 87;break;}
                                           case 31: {this_char = 109;break;}
                                           case 32: {this_char = 98;break;}
                                       }
                                       break;
                                   }
                                   case 12: {
                                       switch(idx){
                                           case 0: {this_char = 97;break;}
                                           case 1: {this_char = 112;break;}
                                           case 2: {this_char = 114;break;}
                                           case 3: {this_char = 100;break;}
                                           case 4: {this_char = 105;break;}
                                           case 5: {this_char = 101;break;}
                                           case 6: {this_char = 110;break;}
                                           case 7: {this_char = 98;break;}
                                           case 8: {this_char = 111;break;}
                                           case 9: {this_char = 119;break;}
                                           case 10: {this_char = 121;break;}
                                           case 11: {this_char = 107;break;}
                                           case 12: {this_char = 104;break;}
                                           case 13: {this_char = 48;break;}
                                           case 14: {this_char = 51;break;}
                                           case 15: {this_char = 115;break;}
                                           case 16: {this_char = 108;break;}
                                           case 17: {this_char = 99;break;}
                                       }
                                       break;
                                   }
                                   case 13: {
                                       switch(idx){
                                           case 0: {this_char = 83;break;}
                                           case 1: {this_char = 50;break;}
                                           case 2: {this_char = 53;break;}
                                           case 3: {this_char = 49;break;}
                                           case 4: {this_char = 48;break;}
                                           case 5: {this_char = 52;break;}
                                           case 6: {this_char = 51;break;}
                                           case 7: {this_char = 56;break;}
                                           case 8: {this_char = 57;break;}
                                           case 9: {this_char = 55;break;}
                                           case 10: {this_char = 54;break;}
                                       }
                                       break;
                                   }
                                   case 14: {
                                       switch(idx){
                                           case 0: {this_char = 68;break;}
                                           case 1: {this_char = 48;break;}
                                           case 2: {this_char = 53;break;}
                                           case 3: {this_char = 54;break;}
                                           case 4: {this_char = 50;break;}
                                           case 5: {this_char = 55;break;}
                                           case 6: {this_char = 56;break;}
                                           case 7: {this_char = 52;break;}
                                           case 8: {this_char = 49;break;}
                                           case 9: {this_char = 51;break;}
                                           case 10: {this_char = 57;break;}
                                           case 11: {this_char = 45;break;}
                                       }
                                       break;
                                   }
                                   case 15: {
                                       switch(idx){
                                           case 0: {this_char = 48;break;}
                                           case 1: {this_char = 49;break;}
                                           case 2: {this_char = 124;break;}
                                           case 3: {this_char = 58;break;}
                                           case 4: {this_char = 67;break;}
                                           case 5: {this_char = 51;break;}
                                           case 6: {this_char = 54;break;}
                                           case 7: {this_char = 57;break;}
                                           case 8: {this_char = 55;break;}
                                           case 9: {this_char = 50;break;}
                                           case 10: {this_char = 56;break;}
                                           case 11: {this_char = 53;break;}
                                           case 12: {this_char = 52;break;}
                                       }
                                       break;
                                   }
                                   case 16: {
                                       switch(idx){
                                           case 0: {this_char = 48;break;}
                                           case 1: {this_char = 124;break;}
                                           case 2: {this_char = 58;break;}
                                           case 3: {this_char = 65;break;}
                                           case 4: {this_char = 49;break;}
                                           case 5: {this_char = 54;break;}
                                           case 6: {this_char = 55;break;}
                                           case 7: {this_char = 51;break;}
                                           case 8: {this_char = 57;break;}
                                           case 9: {this_char = 50;break;}
                                       }
                                       break;
                                   }
                                   case 17: {
                                       switch(idx){
                                           case 0: {this_char = 48;break;}
                                           case 1: {this_char = 124;break;}
                                           case 2: {this_char = 58;break;}
                                           case 3: {this_char = 49;break;}
                                           case 4: {this_char = 51;break;}
                                           case 5: {this_char = 82;break;}
                                           case 6: {this_char = 54;break;}
                                           case 7: {this_char = 57;break;}
                                           case 8: {this_char = 55;break;}
                                           case 9: {this_char = 53;break;}
                                           case 10: {this_char = 50;break;}
                                           case 11: {this_char = 52;break;}
                                           case 12: {this_char = 56;break;}
                                       }
                                       break;
                                   }
                                   case 18: {
                                       switch(idx){
                                           case 0: {this_char = 70;break;}
                                           case 1: {this_char = 77;break;}
                                           case 2: {this_char = 88;break;}
                                       }
                                       break;
                                   }
                                }
                            }
                            buffer[i]=this_char;
                        }

                        //Add it to the pool
                        bstring val_str = blk2bstr(buffer,length);
                        int new_last_idx = col_to_string_pool_length[c];
                        switch(c){
                            case 0: {string_pool_0[new_last_idx] = val_str;break;}
                            case 1: {string_pool_1[new_last_idx] = val_str;break;}
                            case 2: {string_pool_2[new_last_idx] = val_str;break;}
                            case 3: {string_pool_3[new_last_idx] = val_str;break;}
                            case 4: {string_pool_4[new_last_idx] = val_str;break;}
                            case 5: {string_pool_5[new_last_idx] = val_str;break;}
                            case 6: {string_pool_6[new_last_idx] = val_str;break;}
                            case 7: {string_pool_7[new_last_idx] = val_str;break;}
                            case 8: {string_pool_8[new_last_idx] = val_str;break;}
                            case 9: {string_pool_9[new_last_idx] = val_str;break;}
                            case 10: {string_pool_10[new_last_idx] = val_str;break;}
                            case 11: {string_pool_11[new_last_idx] = val_str;break;}
                            case 12: {string_pool_12[new_last_idx] = val_str;break;}
                            case 13: {string_pool_13[new_last_idx] = val_str;break;}
                            case 14: {string_pool_14[new_last_idx] = val_str;break;}
                            case 15: {string_pool_15[new_last_idx] = val_str;break;}
                            case 16: {string_pool_16[new_last_idx] = val_str;break;}
                            case 17: {string_pool_17[new_last_idx] = val_str;break;}
                            case 18: {string_pool_18[new_last_idx] = val_str;break;}
                        }
                        col_to_string_pool_length[c]++;
                        val=new_last_idx;

                        if((c == driving_column) && (r==0)){
                            //only on the first row will this happen
                            driving_col_as_number num=0;
                            for(int i=0;i<driving_column_bytes;i++){
                                num<<=8;
                                num+=buffer[i];
                            }
                            previous_driving_col_number = num;
                        }
                    }

                    if(do_store_bits & (one<<c)){
                        int last_inserted_idx=col_to_string_pool_length[c]-1;
                        int new_stored_idx = col_to_n_stored_vals[c];
                        switch(c){
                            case 0: {stored_vals_0[new_stored_idx]=last_inserted_idx;break;}
                            case 1: {stored_vals_1[new_stored_idx]=last_inserted_idx;break;}
                            case 2: {stored_vals_2[new_stored_idx]=last_inserted_idx;break;}
                            case 3: {stored_vals_3[new_stored_idx]=last_inserted_idx;break;}
                            case 4: {stored_vals_4[new_stored_idx]=last_inserted_idx;break;}
                            case 5: {stored_vals_5[new_stored_idx]=last_inserted_idx;break;}
                            case 6: {stored_vals_6[new_stored_idx]=last_inserted_idx;break;}
                            case 7: {stored_vals_7[new_stored_idx]=last_inserted_idx;break;}
                            case 8: {stored_vals_8[new_stored_idx]=last_inserted_idx;break;}
                            case 9: {stored_vals_9[new_stored_idx]=last_inserted_idx;break;}
                            case 10: {stored_vals_10[new_stored_idx]=last_inserted_idx;break;}
                            case 11: {stored_vals_11[new_stored_idx]=last_inserted_idx;break;}
                            case 12: {stored_vals_12[new_stored_idx]=last_inserted_idx;break;}
                            case 13: {stored_vals_13[new_stored_idx]=last_inserted_idx;break;}
                            case 14: {stored_vals_14[new_stored_idx]=last_inserted_idx;break;}
                            case 15: {stored_vals_15[new_stored_idx]=last_inserted_idx;break;}
                            case 16: {stored_vals_16[new_stored_idx]=last_inserted_idx;break;}
                            case 17: {stored_vals_17[new_stored_idx]=last_inserted_idx;break;}
                            case 18: {stored_vals_18[new_stored_idx]=last_inserted_idx;break;}
                        }
                        col_to_n_stored_vals[c]++;
                    }

                }
            }
            vals[c]=val;
        }
        seek_till_byte_boundary(BINARY2);
        seek_till_byte_boundary(BINARY);


        if(predictor_column_used & (one<<0)){
            struct value_0 value={vals[7]};
            struct friends_0 friends;
            khiter_t k = kh_get(value_to_friends_0, value_to_most_popular_friends_0, value);
            int is_missing = (k == kh_end(value_to_most_popular_friends_0));
            if(!is_missing){
                friends = kh_val(value_to_most_popular_friends_0, k);
            }else if(r !=0){
                friends = most_popular_friends_0;
            }else{die("You're just unpredictable.\n");}
            vals[1] = friends.col_1;
            vals[2] = friends.col_2;
            vals[3] = friends.col_3;
            vals[8] = friends.col_8;
            vals[10] = friends.col_10;
            vals[11] = friends.col_11;
            vals[12] = friends.col_12;
            vals[15] = friends.col_15;
            vals[16] = friends.col_16;
            vals[17] = friends.col_17;
            vals[18] = friends.col_18;
        }
            
        if(predictor_column_used & (one<<1)){
            struct value_1 value={vals[7]};
            struct friends_1 friends;
            khiter_t k = kh_get(value_to_friends_1, value_to_most_popular_friends_1, value);
            int is_missing = (k == kh_end(value_to_most_popular_friends_1));
            if(!is_missing){
                friends = kh_val(value_to_most_popular_friends_1, k);
            }else if(r !=0){
                friends = most_popular_friends_1;
            }else{die("You're just unpredictable.\n");}
            vals[10] = friends.col_10;
            vals[11] = friends.col_11;
            vals[12] = friends.col_12;
            vals[15] = friends.col_15;
            vals[16] = friends.col_16;
            vals[17] = friends.col_17;
            vals[18] = friends.col_18;
        }
            
        if(predictor_column_used & (one<<2)){
            struct value_2 value={vals[7]};
            struct friends_2 friends;
            khiter_t k = kh_get(value_to_friends_2, value_to_most_popular_friends_2, value);
            int is_missing = (k == kh_end(value_to_most_popular_friends_2));
            if(!is_missing){
                friends = kh_val(value_to_most_popular_friends_2, k);
            }else if(r !=0){
                friends = most_popular_friends_2;
            }else{die("You're just unpredictable.\n");}
            vals[8] = friends.col_8;
            vals[10] = friends.col_10;
            vals[11] = friends.col_11;
            vals[12] = friends.col_12;
        }
            
        if(predictor_column_used & (one<<3)){
            struct value_3 value={vals[3]};
            struct friends_3 friends;
            khiter_t k = kh_get(value_to_friends_3, value_to_most_popular_friends_3, value);
            int is_missing = (k == kh_end(value_to_most_popular_friends_3));
            if(!is_missing){
                friends = kh_val(value_to_most_popular_friends_3, k);
            }else if(r !=0){
                friends = most_popular_friends_3;
            }else{die("You're just unpredictable.\n");}
            vals[1] = friends.col_1;
            vals[2] = friends.col_2;
            vals[4] = friends.col_4;
            vals[8] = friends.col_8;
            vals[10] = friends.col_10;
            vals[11] = friends.col_11;
            vals[12] = friends.col_12;
            vals[13] = friends.col_13;
            vals[14] = friends.col_14;
            vals[15] = friends.col_15;
            vals[16] = friends.col_16;
            vals[17] = friends.col_17;
            vals[18] = friends.col_18;
        }
            
        if(predictor_column_used & (one<<4)){
            struct value_4 value={vals[3]};
            struct friends_4 friends;
            khiter_t k = kh_get(value_to_friends_4, value_to_most_popular_friends_4, value);
            int is_missing = (k == kh_end(value_to_most_popular_friends_4));
            if(!is_missing){
                friends = kh_val(value_to_most_popular_friends_4, k);
            }else if(r !=0){
                friends = most_popular_friends_4;
            }else{die("You're just unpredictable.\n");}
            vals[4] = friends.col_4;
            vals[13] = friends.col_13;
            vals[14] = friends.col_14;
        }
            
        if(predictor_column_used & (one<<5)){
            struct value_5 value={vals[1]};
            struct friends_5 friends;
            khiter_t k = kh_get(value_to_friends_5, value_to_most_popular_friends_5, value);
            int is_missing = (k == kh_end(value_to_most_popular_friends_5));
            if(!is_missing){
                friends = kh_val(value_to_most_popular_friends_5, k);
            }else if(r !=0){
                friends = most_popular_friends_5;
            }else{die("You're just unpredictable.\n");}
            vals[4] = friends.col_4;
            vals[11] = friends.col_11;
        }
            
        if(predictor_column_used & (one<<6)){
            struct value_6 value={vals[1]};
            struct friends_6 friends;
            khiter_t k = kh_get(value_to_friends_6, value_to_most_popular_friends_6, value);
            int is_missing = (k == kh_end(value_to_most_popular_friends_6));
            if(!is_missing){
                friends = kh_val(value_to_most_popular_friends_6, k);
            }else if(r !=0){
                friends = most_popular_friends_6;
            }else{die("You're just unpredictable.\n");}
            vals[18] = friends.col_18;
        }
            
        if(predictor_column_used & (one<<7)){
            struct value_7 value={vals[15]};
            struct friends_7 friends;
            khiter_t k = kh_get(value_to_friends_7, value_to_most_popular_friends_7, value);
            int is_missing = (k == kh_end(value_to_most_popular_friends_7));
            if(!is_missing){
                friends = kh_val(value_to_most_popular_friends_7, k);
            }else if(r !=0){
                friends = most_popular_friends_7;
            }else{die("You're just unpredictable.\n");}
            vals[16] = friends.col_16;
            vals[17] = friends.col_17;
        }
            
        if(predictor_column_used & (one<<8)){
            struct value_8 value={vals[8]};
            struct friends_8 friends;
            khiter_t k = kh_get(value_to_friends_8, value_to_most_popular_friends_8, value);
            int is_missing = (k == kh_end(value_to_most_popular_friends_8));
            if(!is_missing){
                friends = kh_val(value_to_most_popular_friends_8, k);
            }else if(r !=0){
                friends = most_popular_friends_8;
            }else{die("You're just unpredictable.\n");}
            vals[10] = friends.col_10;
            vals[11] = friends.col_11;
            vals[12] = friends.col_12;
        }
            
        if(predictor_column_used & (one<<9)){
            struct value_9 value={vals[10]};
            struct friends_9 friends;
            khiter_t k = kh_get(value_to_friends_9, value_to_most_popular_friends_9, value);
            int is_missing = (k == kh_end(value_to_most_popular_friends_9));
            if(!is_missing){
                friends = kh_val(value_to_most_popular_friends_9, k);
            }else if(r !=0){
                friends = most_popular_friends_9;
            }else{die("You're just unpredictable.\n");}
            vals[11] = friends.col_11;
        }
            
        if(predictor_column_used & (one<<10)){
            struct value_10 value={vals[14]};
            struct friends_10 friends;
            khiter_t k = kh_get(value_to_friends_10, value_to_most_popular_friends_10, value);
            int is_missing = (k == kh_end(value_to_most_popular_friends_10));
            if(!is_missing){
                friends = kh_val(value_to_most_popular_friends_10, k);
            }else if(r !=0){
                friends = most_popular_friends_10;
            }else{die("You're just unpredictable.\n");}
            vals[4] = friends.col_4;
            vals[13] = friends.col_13;
        }
            
        if(predictor_column_used & (one<<11)){
            struct value_11 value={vals[13]};
            struct friends_11 friends;
            khiter_t k = kh_get(value_to_friends_11, value_to_most_popular_friends_11, value);
            int is_missing = (k == kh_end(value_to_most_popular_friends_11));
            if(!is_missing){
                friends = kh_val(value_to_most_popular_friends_11, k);
            }else if(r !=0){
                friends = most_popular_friends_11;
            }else{die("You're just unpredictable.\n");}
            vals[4] = friends.col_4;
        }
            
        if(predictor_column_used & (one<<12)){
            struct value_12 value={vals[1],vals[6],vals[4]};
            struct friends_12 friends;
            khiter_t k = kh_get(value_to_friends_12, value_to_most_popular_friends_12, value);
            int is_missing = (k == kh_end(value_to_most_popular_friends_12));
            if(!is_missing){
                friends = kh_val(value_to_most_popular_friends_12, k);
            }else if(r !=0){
                friends = most_popular_friends_12;
            }else{die("You're just unpredictable.\n");}
            vals[0] = friends.col_0;
        }
            
        //store previous row vals
        for (int c=0;c<19;c++){
            previous_row[c]=vals[c];
        }

        //check for undef vals


        //store new predictor vals-done


        {
            struct friends_0 friends={vals[1],vals[2],vals[3],vals[8],vals[10],vals[11],vals[12],vals[15],vals[16],vals[17],vals[18]};
            struct value_0 value={vals[7]};
            struct val_plus_friends_0 val_plus_friends = {value,friends};
            int new_count = kh_increment(val_plus_friends_to_count_0, val_to_friends_to_count_0, val_plus_friends);
            struct friends_0 *most_popular_friends = kh_get_val_ptr(value_to_friends_0, value_to_most_popular_friends_0, value);
            if(most_popular_friends==NULL){
                int ret;
                khiter_t k=kh_put(value_to_friends_0, value_to_most_popular_friends_0, value,&ret);
                kh_val(value_to_most_popular_friends_0,k)=friends;
            }
            else if(new_count >= kh_val(val_to_friends_to_count_0,kh_get(val_plus_friends_to_count_0, val_to_friends_to_count_0, ((struct val_plus_friends_0){value, *most_popular_friends})))){
                khiter_t k=kh_get(value_to_friends_0, value_to_most_popular_friends_0, value);
                kh_val(value_to_most_popular_friends_0,k)=friends;
            }
            new_count = kh_increment(friends_to_count_0, friends_to_count_0, friends);
            if((r == 0) || (new_count >= kh_val(friends_to_count_0,kh_get(friends_to_count_0, friends_to_count_0, most_popular_friends_0)))){
                most_popular_friends_0 = friends;
            }
            
        }
        {
            struct friends_1 friends={vals[10],vals[11],vals[12],vals[15],vals[16],vals[17],vals[18]};
            struct value_1 value={vals[7]};
            struct val_plus_friends_1 val_plus_friends = {value,friends};
            int new_count = kh_increment(val_plus_friends_to_count_1, val_to_friends_to_count_1, val_plus_friends);
            struct friends_1 *most_popular_friends = kh_get_val_ptr(value_to_friends_1, value_to_most_popular_friends_1, value);
            if(most_popular_friends==NULL){
                int ret;
                khiter_t k=kh_put(value_to_friends_1, value_to_most_popular_friends_1, value,&ret);
                kh_val(value_to_most_popular_friends_1,k)=friends;
            }
            else if(new_count >= kh_val(val_to_friends_to_count_1,kh_get(val_plus_friends_to_count_1, val_to_friends_to_count_1, ((struct val_plus_friends_1){value, *most_popular_friends})))){
                khiter_t k=kh_get(value_to_friends_1, value_to_most_popular_friends_1, value);
                kh_val(value_to_most_popular_friends_1,k)=friends;
            }
            new_count = kh_increment(friends_to_count_1, friends_to_count_1, friends);
            if((r == 0) || (new_count >= kh_val(friends_to_count_1,kh_get(friends_to_count_1, friends_to_count_1, most_popular_friends_1)))){
                most_popular_friends_1 = friends;
            }
            
        }
        {
            struct friends_2 friends={vals[8],vals[10],vals[11],vals[12]};
            struct value_2 value={vals[7]};
            struct val_plus_friends_2 val_plus_friends = {value,friends};
            int new_count = kh_increment(val_plus_friends_to_count_2, val_to_friends_to_count_2, val_plus_friends);
            struct friends_2 *most_popular_friends = kh_get_val_ptr(value_to_friends_2, value_to_most_popular_friends_2, value);
            if(most_popular_friends==NULL){
                int ret;
                khiter_t k=kh_put(value_to_friends_2, value_to_most_popular_friends_2, value,&ret);
                kh_val(value_to_most_popular_friends_2,k)=friends;
            }
            else if(new_count >= kh_val(val_to_friends_to_count_2,kh_get(val_plus_friends_to_count_2, val_to_friends_to_count_2, ((struct val_plus_friends_2){value, *most_popular_friends})))){
                khiter_t k=kh_get(value_to_friends_2, value_to_most_popular_friends_2, value);
                kh_val(value_to_most_popular_friends_2,k)=friends;
            }
            new_count = kh_increment(friends_to_count_2, friends_to_count_2, friends);
            if((r == 0) || (new_count >= kh_val(friends_to_count_2,kh_get(friends_to_count_2, friends_to_count_2, most_popular_friends_2)))){
                most_popular_friends_2 = friends;
            }
            
        }
        {
            struct friends_3 friends={vals[1],vals[2],vals[4],vals[8],vals[10],vals[11],vals[12],vals[13],vals[14],vals[15],vals[16],vals[17],vals[18]};
            struct value_3 value={vals[3]};
            struct val_plus_friends_3 val_plus_friends = {value,friends};
            int new_count = kh_increment(val_plus_friends_to_count_3, val_to_friends_to_count_3, val_plus_friends);
            struct friends_3 *most_popular_friends = kh_get_val_ptr(value_to_friends_3, value_to_most_popular_friends_3, value);
            if(most_popular_friends==NULL){
                int ret;
                khiter_t k=kh_put(value_to_friends_3, value_to_most_popular_friends_3, value,&ret);
                kh_val(value_to_most_popular_friends_3,k)=friends;
            }
            else if(new_count >= kh_val(val_to_friends_to_count_3,kh_get(val_plus_friends_to_count_3, val_to_friends_to_count_3, ((struct val_plus_friends_3){value, *most_popular_friends})))){
                khiter_t k=kh_get(value_to_friends_3, value_to_most_popular_friends_3, value);
                kh_val(value_to_most_popular_friends_3,k)=friends;
            }
            new_count = kh_increment(friends_to_count_3, friends_to_count_3, friends);
            if((r == 0) || (new_count >= kh_val(friends_to_count_3,kh_get(friends_to_count_3, friends_to_count_3, most_popular_friends_3)))){
                most_popular_friends_3 = friends;
            }
            
        }
        {
            struct friends_4 friends={vals[4],vals[13],vals[14]};
            struct value_4 value={vals[3]};
            struct val_plus_friends_4 val_plus_friends = {value,friends};
            int new_count = kh_increment(val_plus_friends_to_count_4, val_to_friends_to_count_4, val_plus_friends);
            struct friends_4 *most_popular_friends = kh_get_val_ptr(value_to_friends_4, value_to_most_popular_friends_4, value);
            if(most_popular_friends==NULL){
                int ret;
                khiter_t k=kh_put(value_to_friends_4, value_to_most_popular_friends_4, value,&ret);
                kh_val(value_to_most_popular_friends_4,k)=friends;
            }
            else if(new_count >= kh_val(val_to_friends_to_count_4,kh_get(val_plus_friends_to_count_4, val_to_friends_to_count_4, ((struct val_plus_friends_4){value, *most_popular_friends})))){
                khiter_t k=kh_get(value_to_friends_4, value_to_most_popular_friends_4, value);
                kh_val(value_to_most_popular_friends_4,k)=friends;
            }
            new_count = kh_increment(friends_to_count_4, friends_to_count_4, friends);
            if((r == 0) || (new_count >= kh_val(friends_to_count_4,kh_get(friends_to_count_4, friends_to_count_4, most_popular_friends_4)))){
                most_popular_friends_4 = friends;
            }
            
        }
        {
            struct friends_5 friends={vals[4],vals[11]};
            struct value_5 value={vals[1]};
            struct val_plus_friends_5 val_plus_friends = {value,friends};
            int new_count = kh_increment(val_plus_friends_to_count_5, val_to_friends_to_count_5, val_plus_friends);
            struct friends_5 *most_popular_friends = kh_get_val_ptr(value_to_friends_5, value_to_most_popular_friends_5, value);
            if(most_popular_friends==NULL){
                int ret;
                khiter_t k=kh_put(value_to_friends_5, value_to_most_popular_friends_5, value,&ret);
                kh_val(value_to_most_popular_friends_5,k)=friends;
            }
            else if(new_count >= kh_val(val_to_friends_to_count_5,kh_get(val_plus_friends_to_count_5, val_to_friends_to_count_5, ((struct val_plus_friends_5){value, *most_popular_friends})))){
                khiter_t k=kh_get(value_to_friends_5, value_to_most_popular_friends_5, value);
                kh_val(value_to_most_popular_friends_5,k)=friends;
            }
            new_count = kh_increment(friends_to_count_5, friends_to_count_5, friends);
            if((r == 0) || (new_count >= kh_val(friends_to_count_5,kh_get(friends_to_count_5, friends_to_count_5, most_popular_friends_5)))){
                most_popular_friends_5 = friends;
            }
            
        }
        {
            struct friends_6 friends={vals[18]};
            struct value_6 value={vals[1]};
            struct val_plus_friends_6 val_plus_friends = {value,friends};
            int new_count = kh_increment(val_plus_friends_to_count_6, val_to_friends_to_count_6, val_plus_friends);
            struct friends_6 *most_popular_friends = kh_get_val_ptr(value_to_friends_6, value_to_most_popular_friends_6, value);
            if(most_popular_friends==NULL){
                int ret;
                khiter_t k=kh_put(value_to_friends_6, value_to_most_popular_friends_6, value,&ret);
                kh_val(value_to_most_popular_friends_6,k)=friends;
            }
            else if(new_count >= kh_val(val_to_friends_to_count_6,kh_get(val_plus_friends_to_count_6, val_to_friends_to_count_6, ((struct val_plus_friends_6){value, *most_popular_friends})))){
                khiter_t k=kh_get(value_to_friends_6, value_to_most_popular_friends_6, value);
                kh_val(value_to_most_popular_friends_6,k)=friends;
            }
            new_count = kh_increment(friends_to_count_6, friends_to_count_6, friends);
            if((r == 0) || (new_count >= kh_val(friends_to_count_6,kh_get(friends_to_count_6, friends_to_count_6, most_popular_friends_6)))){
                most_popular_friends_6 = friends;
            }
            
        }
        {
            struct friends_7 friends={vals[16],vals[17]};
            struct value_7 value={vals[15]};
            struct val_plus_friends_7 val_plus_friends = {value,friends};
            int new_count = kh_increment(val_plus_friends_to_count_7, val_to_friends_to_count_7, val_plus_friends);
            struct friends_7 *most_popular_friends = kh_get_val_ptr(value_to_friends_7, value_to_most_popular_friends_7, value);
            if(most_popular_friends==NULL){
                int ret;
                khiter_t k=kh_put(value_to_friends_7, value_to_most_popular_friends_7, value,&ret);
                kh_val(value_to_most_popular_friends_7,k)=friends;
            }
            else if(new_count >= kh_val(val_to_friends_to_count_7,kh_get(val_plus_friends_to_count_7, val_to_friends_to_count_7, ((struct val_plus_friends_7){value, *most_popular_friends})))){
                khiter_t k=kh_get(value_to_friends_7, value_to_most_popular_friends_7, value);
                kh_val(value_to_most_popular_friends_7,k)=friends;
            }
            new_count = kh_increment(friends_to_count_7, friends_to_count_7, friends);
            if((r == 0) || (new_count >= kh_val(friends_to_count_7,kh_get(friends_to_count_7, friends_to_count_7, most_popular_friends_7)))){
                most_popular_friends_7 = friends;
            }
            
        }
        {
            struct friends_8 friends={vals[10],vals[11],vals[12]};
            struct value_8 value={vals[8]};
            struct val_plus_friends_8 val_plus_friends = {value,friends};
            int new_count = kh_increment(val_plus_friends_to_count_8, val_to_friends_to_count_8, val_plus_friends);
            struct friends_8 *most_popular_friends = kh_get_val_ptr(value_to_friends_8, value_to_most_popular_friends_8, value);
            if(most_popular_friends==NULL){
                int ret;
                khiter_t k=kh_put(value_to_friends_8, value_to_most_popular_friends_8, value,&ret);
                kh_val(value_to_most_popular_friends_8,k)=friends;
            }
            else if(new_count >= kh_val(val_to_friends_to_count_8,kh_get(val_plus_friends_to_count_8, val_to_friends_to_count_8, ((struct val_plus_friends_8){value, *most_popular_friends})))){
                khiter_t k=kh_get(value_to_friends_8, value_to_most_popular_friends_8, value);
                kh_val(value_to_most_popular_friends_8,k)=friends;
            }
            new_count = kh_increment(friends_to_count_8, friends_to_count_8, friends);
            if((r == 0) || (new_count >= kh_val(friends_to_count_8,kh_get(friends_to_count_8, friends_to_count_8, most_popular_friends_8)))){
                most_popular_friends_8 = friends;
            }
            
        }
        {
            struct friends_9 friends={vals[11]};
            struct value_9 value={vals[10]};
            struct val_plus_friends_9 val_plus_friends = {value,friends};
            int new_count = kh_increment(val_plus_friends_to_count_9, val_to_friends_to_count_9, val_plus_friends);
            struct friends_9 *most_popular_friends = kh_get_val_ptr(value_to_friends_9, value_to_most_popular_friends_9, value);
            if(most_popular_friends==NULL){
                int ret;
                khiter_t k=kh_put(value_to_friends_9, value_to_most_popular_friends_9, value,&ret);
                kh_val(value_to_most_popular_friends_9,k)=friends;
            }
            else if(new_count >= kh_val(val_to_friends_to_count_9,kh_get(val_plus_friends_to_count_9, val_to_friends_to_count_9, ((struct val_plus_friends_9){value, *most_popular_friends})))){
                khiter_t k=kh_get(value_to_friends_9, value_to_most_popular_friends_9, value);
                kh_val(value_to_most_popular_friends_9,k)=friends;
            }
            new_count = kh_increment(friends_to_count_9, friends_to_count_9, friends);
            if((r == 0) || (new_count >= kh_val(friends_to_count_9,kh_get(friends_to_count_9, friends_to_count_9, most_popular_friends_9)))){
                most_popular_friends_9 = friends;
            }
            
        }
        {
            struct friends_10 friends={vals[4],vals[13]};
            struct value_10 value={vals[14]};
            struct val_plus_friends_10 val_plus_friends = {value,friends};
            int new_count = kh_increment(val_plus_friends_to_count_10, val_to_friends_to_count_10, val_plus_friends);
            struct friends_10 *most_popular_friends = kh_get_val_ptr(value_to_friends_10, value_to_most_popular_friends_10, value);
            if(most_popular_friends==NULL){
                int ret;
                khiter_t k=kh_put(value_to_friends_10, value_to_most_popular_friends_10, value,&ret);
                kh_val(value_to_most_popular_friends_10,k)=friends;
            }
            else if(new_count >= kh_val(val_to_friends_to_count_10,kh_get(val_plus_friends_to_count_10, val_to_friends_to_count_10, ((struct val_plus_friends_10){value, *most_popular_friends})))){
                khiter_t k=kh_get(value_to_friends_10, value_to_most_popular_friends_10, value);
                kh_val(value_to_most_popular_friends_10,k)=friends;
            }
            new_count = kh_increment(friends_to_count_10, friends_to_count_10, friends);
            if((r == 0) || (new_count >= kh_val(friends_to_count_10,kh_get(friends_to_count_10, friends_to_count_10, most_popular_friends_10)))){
                most_popular_friends_10 = friends;
            }
            
        }
        {
            struct friends_11 friends={vals[4]};
            struct value_11 value={vals[13]};
            struct val_plus_friends_11 val_plus_friends = {value,friends};
            int new_count = kh_increment(val_plus_friends_to_count_11, val_to_friends_to_count_11, val_plus_friends);
            struct friends_11 *most_popular_friends = kh_get_val_ptr(value_to_friends_11, value_to_most_popular_friends_11, value);
            if(most_popular_friends==NULL){
                int ret;
                khiter_t k=kh_put(value_to_friends_11, value_to_most_popular_friends_11, value,&ret);
                kh_val(value_to_most_popular_friends_11,k)=friends;
            }
            else if(new_count >= kh_val(val_to_friends_to_count_11,kh_get(val_plus_friends_to_count_11, val_to_friends_to_count_11, ((struct val_plus_friends_11){value, *most_popular_friends})))){
                khiter_t k=kh_get(value_to_friends_11, value_to_most_popular_friends_11, value);
                kh_val(value_to_most_popular_friends_11,k)=friends;
            }
            new_count = kh_increment(friends_to_count_11, friends_to_count_11, friends);
            if((r == 0) || (new_count >= kh_val(friends_to_count_11,kh_get(friends_to_count_11, friends_to_count_11, most_popular_friends_11)))){
                most_popular_friends_11 = friends;
            }
            
        }
        {
            struct friends_12 friends={vals[0]};
            struct value_12 value={vals[1],vals[6],vals[4]};
            struct val_plus_friends_12 val_plus_friends = {value,friends};
            int new_count = kh_increment(val_plus_friends_to_count_12, val_to_friends_to_count_12, val_plus_friends);
            struct friends_12 *most_popular_friends = kh_get_val_ptr(value_to_friends_12, value_to_most_popular_friends_12, value);
            if(most_popular_friends==NULL){
                int ret;
                khiter_t k=kh_put(value_to_friends_12, value_to_most_popular_friends_12, value,&ret);
                kh_val(value_to_most_popular_friends_12,k)=friends;
            }
            else if(new_count >= kh_val(val_to_friends_to_count_12,kh_get(val_plus_friends_to_count_12, val_to_friends_to_count_12, ((struct val_plus_friends_12){value, *most_popular_friends})))){
                khiter_t k=kh_get(value_to_friends_12, value_to_most_popular_friends_12, value);
                kh_val(value_to_most_popular_friends_12,k)=friends;
            }
            new_count = kh_increment(friends_to_count_12, friends_to_count_12, friends);
            if((r == 0) || (new_count >= kh_val(friends_to_count_12,kh_get(friends_to_count_12, friends_to_count_12, most_popular_friends_12)))){
                most_popular_friends_12 = friends;
            }
            
        }

        puts("decoded row\n");
        //decode columns
        //print output
        //add row checksum
        //- end row loop
        //check final row count
        //check row checksum
        printf("%d dupes\n",dupes);
        while(dupes>0){
            r++;
            dupes--;
            printf("%d\n",r);
                bstring val_0 = string_pool_0[vals[0]];
                printf("%s\t",val_0->data);
                bstring val_1 = string_pool_1[vals[1]];
                printf("%s\t",val_1->data);
                bstring val_2 = string_pool_2[vals[2]];
                printf("%s\t",val_2->data);
                bstring val_3 = string_pool_3[vals[3]];
                char decoded_buf_3[ip_get_unbinarized_bufsize()];
                struct tagbstring tb_decoded_3={ip_get_unbinarized_bufsize(),0,decoded_buf_3};
                bstring decoded_val_3 = &tb_decoded_3;
                ip_unbinarize(val_3, decoded_val_3);
                val_3 = decoded_val_3;
                printf("%s\t",val_3->data);
                bstring val_4 = string_pool_4[vals[4]];
                printf("%s\t",val_4->data);
                bstring val_5 = string_pool_5[vals[5]];
                char decoded_buf_5[datetime_get_bufsize()];
                struct tagbstring tb_decoded_5={datetime_get_bufsize(),0,decoded_buf_5};
                bstring decoded_val_5 = &tb_decoded_5;
                datetime_from_integer(val_5, decoded_val_5);
                val_5 = decoded_val_5;
                printf("%s\t",val_5->data);
                bstring val_6 = string_pool_6[vals[6]];
                printf("%s\t",val_6->data);
                bstring val_7 = string_pool_7[vals[7]];
                char decoded_buf_7[short_uuid_get_bufsize()];
                struct tagbstring tb_decoded_7={short_uuid_get_bufsize(),0,decoded_buf_7};
                bstring decoded_val_7 = &tb_decoded_7;
                short_uuid_unbinarize(val_7, decoded_val_7);
                val_7 = decoded_val_7;
                printf("%s\t",val_7->data);
                bstring val_8 = string_pool_8[vals[8]];
                printf("%s\t",val_8->data);
                bstring val_9 = string_pool_9[vals[9]];
                printf("%s\t",val_9->data);
                bstring val_10 = string_pool_10[vals[10]];
                printf("%s\t",val_10->data);
                bstring val_11 = string_pool_11[vals[11]];
                printf("%s\t",val_11->data);
                bstring val_12 = string_pool_12[vals[12]];
                printf("%s\t",val_12->data);
                bstring val_13 = string_pool_13[vals[13]];
                printf("%s\t",val_13->data);
                bstring val_14 = string_pool_14[vals[14]];
                printf("%s\t",val_14->data);
                bstring val_15 = string_pool_15[vals[15]];
                printf("%s\t",val_15->data);
                bstring val_16 = string_pool_16[vals[16]];
                printf("%s\t",val_16->data);
                bstring val_17 = string_pool_17[vals[17]];
                printf("%s\t",val_17->data);
                bstring val_18 = string_pool_18[vals[18]];
                printf("%s\t",val_18->data);
        }
    }
    warn("done decoding\n");
    return 0;
}

