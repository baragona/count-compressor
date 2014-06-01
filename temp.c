#line 461

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>

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

INLINE uint32_t struct_hash_value_0 (struct value_0 val){
    return jenkins_hash((char *)(&val), sizeof(struct value_0));
}
INLINE uint32_t struct_hash_value_1 (struct value_1 val){
    return jenkins_hash((char *)(&val), sizeof(struct value_1));
}
INLINE uint32_t struct_hash_value_2 (struct value_2 val){
    return jenkins_hash((char *)(&val), sizeof(struct value_2));
}
INLINE uint32_t struct_hash_value_3 (struct value_3 val){
    return jenkins_hash((char *)(&val), sizeof(struct value_3));
}
INLINE uint32_t struct_hash_value_4 (struct value_4 val){
    return jenkins_hash((char *)(&val), sizeof(struct value_4));
}
INLINE uint32_t struct_hash_value_5 (struct value_5 val){
    return jenkins_hash((char *)(&val), sizeof(struct value_5));
}
INLINE uint32_t struct_hash_value_6 (struct value_6 val){
    return jenkins_hash((char *)(&val), sizeof(struct value_6));
}
INLINE uint32_t struct_hash_value_7 (struct value_7 val){
    return jenkins_hash((char *)(&val), sizeof(struct value_7));
}
INLINE uint32_t struct_hash_value_8 (struct value_8 val){
    return jenkins_hash((char *)(&val), sizeof(struct value_8));
}
INLINE uint32_t struct_hash_value_9 (struct value_9 val){
    return jenkins_hash((char *)(&val), sizeof(struct value_9));
}
INLINE uint32_t struct_hash_value_10 (struct value_10 val){
    return jenkins_hash((char *)(&val), sizeof(struct value_10));
}
INLINE uint32_t struct_hash_value_11 (struct value_11 val){
    return jenkins_hash((char *)(&val), sizeof(struct value_11));
}
INLINE uint32_t struct_hash_value_12 (struct value_12 val){
    return jenkins_hash((char *)(&val), sizeof(struct value_12));
}
INLINE int struct_equal_value_0 (struct value_0 a, struct value_0 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct value_0));
}
INLINE int struct_equal_value_1 (struct value_1 a, struct value_1 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct value_1));
}
INLINE int struct_equal_value_2 (struct value_2 a, struct value_2 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct value_2));
}
INLINE int struct_equal_value_3 (struct value_3 a, struct value_3 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct value_3));
}
INLINE int struct_equal_value_4 (struct value_4 a, struct value_4 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct value_4));
}
INLINE int struct_equal_value_5 (struct value_5 a, struct value_5 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct value_5));
}
INLINE int struct_equal_value_6 (struct value_6 a, struct value_6 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct value_6));
}
INLINE int struct_equal_value_7 (struct value_7 a, struct value_7 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct value_7));
}
INLINE int struct_equal_value_8 (struct value_8 a, struct value_8 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct value_8));
}
INLINE int struct_equal_value_9 (struct value_9 a, struct value_9 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct value_9));
}
INLINE int struct_equal_value_10 (struct value_10 a, struct value_10 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct value_10));
}
INLINE int struct_equal_value_11 (struct value_11 a, struct value_11 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct value_11));
}
INLINE int struct_equal_value_12 (struct value_12 a, struct value_12 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct value_12));
}
INLINE uint32_t struct_hash_val_plus_friends_0 (struct val_plus_friends_0 val){
    return jenkins_hash((char *)(&val), sizeof(struct val_plus_friends_0));
}
INLINE uint32_t struct_hash_val_plus_friends_1 (struct val_plus_friends_1 val){
    return jenkins_hash((char *)(&val), sizeof(struct val_plus_friends_1));
}
INLINE uint32_t struct_hash_val_plus_friends_2 (struct val_plus_friends_2 val){
    return jenkins_hash((char *)(&val), sizeof(struct val_plus_friends_2));
}
INLINE uint32_t struct_hash_val_plus_friends_3 (struct val_plus_friends_3 val){
    return jenkins_hash((char *)(&val), sizeof(struct val_plus_friends_3));
}
INLINE uint32_t struct_hash_val_plus_friends_4 (struct val_plus_friends_4 val){
    return jenkins_hash((char *)(&val), sizeof(struct val_plus_friends_4));
}
INLINE uint32_t struct_hash_val_plus_friends_5 (struct val_plus_friends_5 val){
    return jenkins_hash((char *)(&val), sizeof(struct val_plus_friends_5));
}
INLINE uint32_t struct_hash_val_plus_friends_6 (struct val_plus_friends_6 val){
    return jenkins_hash((char *)(&val), sizeof(struct val_plus_friends_6));
}
INLINE uint32_t struct_hash_val_plus_friends_7 (struct val_plus_friends_7 val){
    return jenkins_hash((char *)(&val), sizeof(struct val_plus_friends_7));
}
INLINE uint32_t struct_hash_val_plus_friends_8 (struct val_plus_friends_8 val){
    return jenkins_hash((char *)(&val), sizeof(struct val_plus_friends_8));
}
INLINE uint32_t struct_hash_val_plus_friends_9 (struct val_plus_friends_9 val){
    return jenkins_hash((char *)(&val), sizeof(struct val_plus_friends_9));
}
INLINE uint32_t struct_hash_val_plus_friends_10 (struct val_plus_friends_10 val){
    return jenkins_hash((char *)(&val), sizeof(struct val_plus_friends_10));
}
INLINE uint32_t struct_hash_val_plus_friends_11 (struct val_plus_friends_11 val){
    return jenkins_hash((char *)(&val), sizeof(struct val_plus_friends_11));
}
INLINE uint32_t struct_hash_val_plus_friends_12 (struct val_plus_friends_12 val){
    return jenkins_hash((char *)(&val), sizeof(struct val_plus_friends_12));
}
INLINE int struct_equal_val_plus_friends_0 (struct val_plus_friends_0 a, struct val_plus_friends_0 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct val_plus_friends_0));
}
INLINE int struct_equal_val_plus_friends_1 (struct val_plus_friends_1 a, struct val_plus_friends_1 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct val_plus_friends_1));
}
INLINE int struct_equal_val_plus_friends_2 (struct val_plus_friends_2 a, struct val_plus_friends_2 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct val_plus_friends_2));
}
INLINE int struct_equal_val_plus_friends_3 (struct val_plus_friends_3 a, struct val_plus_friends_3 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct val_plus_friends_3));
}
INLINE int struct_equal_val_plus_friends_4 (struct val_plus_friends_4 a, struct val_plus_friends_4 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct val_plus_friends_4));
}
INLINE int struct_equal_val_plus_friends_5 (struct val_plus_friends_5 a, struct val_plus_friends_5 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct val_plus_friends_5));
}
INLINE int struct_equal_val_plus_friends_6 (struct val_plus_friends_6 a, struct val_plus_friends_6 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct val_plus_friends_6));
}
INLINE int struct_equal_val_plus_friends_7 (struct val_plus_friends_7 a, struct val_plus_friends_7 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct val_plus_friends_7));
}
INLINE int struct_equal_val_plus_friends_8 (struct val_plus_friends_8 a, struct val_plus_friends_8 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct val_plus_friends_8));
}
INLINE int struct_equal_val_plus_friends_9 (struct val_plus_friends_9 a, struct val_plus_friends_9 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct val_plus_friends_9));
}
INLINE int struct_equal_val_plus_friends_10 (struct val_plus_friends_10 a, struct val_plus_friends_10 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct val_plus_friends_10));
}
INLINE int struct_equal_val_plus_friends_11 (struct val_plus_friends_11 a, struct val_plus_friends_11 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct val_plus_friends_11));
}
INLINE int struct_equal_val_plus_friends_12 (struct val_plus_friends_12 a, struct val_plus_friends_12 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct val_plus_friends_12));
}
INLINE uint32_t struct_hash_friends_0 (struct friends_0 val){
    return jenkins_hash((char *)(&val), sizeof(struct friends_0));
}
INLINE uint32_t struct_hash_friends_1 (struct friends_1 val){
    return jenkins_hash((char *)(&val), sizeof(struct friends_1));
}
INLINE uint32_t struct_hash_friends_2 (struct friends_2 val){
    return jenkins_hash((char *)(&val), sizeof(struct friends_2));
}
INLINE uint32_t struct_hash_friends_3 (struct friends_3 val){
    return jenkins_hash((char *)(&val), sizeof(struct friends_3));
}
INLINE uint32_t struct_hash_friends_4 (struct friends_4 val){
    return jenkins_hash((char *)(&val), sizeof(struct friends_4));
}
INLINE uint32_t struct_hash_friends_5 (struct friends_5 val){
    return jenkins_hash((char *)(&val), sizeof(struct friends_5));
}
INLINE uint32_t struct_hash_friends_6 (struct friends_6 val){
    return jenkins_hash((char *)(&val), sizeof(struct friends_6));
}
INLINE uint32_t struct_hash_friends_7 (struct friends_7 val){
    return jenkins_hash((char *)(&val), sizeof(struct friends_7));
}
INLINE uint32_t struct_hash_friends_8 (struct friends_8 val){
    return jenkins_hash((char *)(&val), sizeof(struct friends_8));
}
INLINE uint32_t struct_hash_friends_9 (struct friends_9 val){
    return jenkins_hash((char *)(&val), sizeof(struct friends_9));
}
INLINE uint32_t struct_hash_friends_10 (struct friends_10 val){
    return jenkins_hash((char *)(&val), sizeof(struct friends_10));
}
INLINE uint32_t struct_hash_friends_11 (struct friends_11 val){
    return jenkins_hash((char *)(&val), sizeof(struct friends_11));
}
INLINE uint32_t struct_hash_friends_12 (struct friends_12 val){
    return jenkins_hash((char *)(&val), sizeof(struct friends_12));
}
INLINE int struct_equal_friends_0 (struct friends_0 a, struct friends_0 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct friends_0));
}
INLINE int struct_equal_friends_1 (struct friends_1 a, struct friends_1 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct friends_1));
}
INLINE int struct_equal_friends_2 (struct friends_2 a, struct friends_2 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct friends_2));
}
INLINE int struct_equal_friends_3 (struct friends_3 a, struct friends_3 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct friends_3));
}
INLINE int struct_equal_friends_4 (struct friends_4 a, struct friends_4 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct friends_4));
}
INLINE int struct_equal_friends_5 (struct friends_5 a, struct friends_5 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct friends_5));
}
INLINE int struct_equal_friends_6 (struct friends_6 a, struct friends_6 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct friends_6));
}
INLINE int struct_equal_friends_7 (struct friends_7 a, struct friends_7 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct friends_7));
}
INLINE int struct_equal_friends_8 (struct friends_8 a, struct friends_8 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct friends_8));
}
INLINE int struct_equal_friends_9 (struct friends_9 a, struct friends_9 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct friends_9));
}
INLINE int struct_equal_friends_10 (struct friends_10 a, struct friends_10 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct friends_10));
}
INLINE int struct_equal_friends_11 (struct friends_11 a, struct friends_11 b){
    return 0==memcmp((void *) (&a),(void *) (&b),sizeof(struct friends_11));
}
INLINE int struct_equal_friends_12 (struct friends_12 a, struct friends_12 b){
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
                case 0: {if(0!=((~col_was_predicted) & ((one<<1)|(one<<2)|(one<<3)|(one<<8)|(one<<10)|(one<<11)|(one<<12)|(one<<15)|(one<<16)|(one<<17)|(one<<18)))){need_predictor_bit=0;} break;}
                case 1: {if(0!=((~col_was_predicted) & ((one<<10)|(one<<11)|(one<<12)|(one<<15)|(one<<16)|(one<<17)|(one<<18)))){need_predictor_bit=0;} break;}
                case 2: {if(0!=((~col_was_predicted) & ((one<<8)|(one<<10)|(one<<11)|(one<<12)))){need_predictor_bit=0;} break;}
                case 3: {if(0!=((~col_was_predicted) & ((one<<1)|(one<<2)|(one<<4)|(one<<8)|(one<<10)|(one<<11)|(one<<12)|(one<<13)|(one<<14)|(one<<15)|(one<<16)|(one<<17)|(one<<18)))){need_predictor_bit=0;} break;}
                case 4: {if(0!=((~col_was_predicted) & ((one<<4)|(one<<13)|(one<<14)))){need_predictor_bit=0;} break;}
                case 5: {if(0!=((~col_was_predicted) & ((one<<4)|(one<<11)))){need_predictor_bit=0;} break;}
                case 6: {if(0!=((~col_was_predicted) & ((one<<18)))){need_predictor_bit=0;} break;}
                case 7: {if(0!=((~col_was_predicted) & ((one<<16)|(one<<17)))){need_predictor_bit=0;} break;}
                case 8: {if(0!=((~col_was_predicted) & ((one<<10)|(one<<11)|(one<<12)))){need_predictor_bit=0;} break;}
                case 9: {if(0!=((~col_was_predicted) & ((one<<11)))){need_predictor_bit=0;} break;}
                case 10: {if(0!=((~col_was_predicted) & ((one<<4)|(one<<13)))){need_predictor_bit=0;} break;}
                case 11: {if(0!=((~col_was_predicted) & ((one<<4)))){need_predictor_bit=0;} break;}
                case 12: {if(0!=((~col_was_predicted) & ((one<<0)))){need_predictor_bit=0;} break;}
            }
            if(need_predictor_bit){
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
            }

            //$encoding_list .= "COPY  " if $copy_bit;

            if(copy_bit != 1){
                unsigned char encoding_choice_bit = read_bit(BINARY);

                if(encoding_choice_bit){
                    encoding_choice_bits|=(one<<c);
                    if(read_bit(BINARY)){
                        do_store_bits|=(one<<c);
                    }

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
                        //only encode the difference
                        driving_col_as_number diff = read_rice(BINARY2, driving_col_rice_bits);
                        driving_col_as_number new_val = previous_driving_col_number + diff;

                        previous_driving_col_number = new_val;

                        uint8_t buffer[driving_column_bytes]={0};
                        for(int i=driving_column_bytes-1;i>=0;i--){
                            buffer[i] = new_val & 0xFF;
                            new_val >>= 8;
                        }

                        bstring val_str = blk2bstr(buffer,driving_column_bytes);
                        driving_col_string_pool[col_to_string_pool_length[c]] = val_str;
                        col_to_string_pool_length[c]++;
                    }else{
                        //Not delta encoded, just a plain old Lit

                        //MORE HERE

                        if((c == driving_column) && (r==0)){
                            //only on the first row will this happen
                            driving_col_as_number num=0;
                            bstring val_str = driving_col_string_pool[val];
                            for(int i=0;i<driving_column_bytes;i++){
                                num<<=8;
                                num+=((uint8_t *)(val_str->data))[i];
                            }
                            previous_driving_col_number = num;
                        }
                    }
                    /*
                    if($c == $driving_column and $r!=0){
                        #only encode the difference
                        my $diff = count::from_rice(sub {read_bits($BINARY2,1)}, $driving_col_rice_bits);
                        $val = count::num2str(count::str2num($previous_row[$c])+$diff,$col_to_max_length[$driving_column]);
                    }else{
                        my $length = $literal_lengths[$c];
                        $length = oct("0b$length");


                        if(defined $col_to_literal_bits[$c]){
                            my $bits_per_char=$col_to_literal_bits[$c];
                            $val='';
                            for (my $i=0;$i<$length;$i++){
                                my $bits = read_bits($BINARY2,$bits_per_char);
                                $val .= $col_to_alpha_idx_to_char[$c]->[oct("0b$bits")];
                            }
                        }else{
                            $val = read_bits($BINARY2,$length*8);
                            $val = count::bitstring_to_bytes($val);
                        }
                    }

                    push @{$col_to_stored_vals[$c]}, $val;

                    if($do_store_bits[$c]==0){
                        #warn "DELETING\n";
                        my $delete_idx = $#{$col_to_stored_vals[$c]};
                        splice(@{$col_to_stored_vals[$c]}, $delete_idx, 1);
                    }
                    */
                }
            }

        }
        while(dupes>0){
            r++;
            dupes--;
        }
    }

    return 0;
}

