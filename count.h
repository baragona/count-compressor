//count.h



MAYBE void warn(const char * s){
    fputs(s,stderr);
}
MAYBE __attribute__((noreturn)) void die(const char * s){
    warn(s);
    exit(1);
}

MAYBE PURE INLINE int log2_int(uint64_t x){
    if (x < 1) {
        return 0 ;
    }
    uint64_t mask = ((uint64_t)1) << 32;
    for (int i=32;i>=0;i--){
        if (x & mask) {
            return i+1;
        }

        mask >>=1;
    }
    return 0;
    //die("Something too big passed to log2_int?\n");
}

typedef uint64_t string_id ;


//Jenkins hash
INLINE uint32_t calc_hash(const char *key, size_t len){
    uint32_t hash, i;
    for(hash = i = 0; i < len; ++i)
    {
        hash += key[i];
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);
    return hash;
}

