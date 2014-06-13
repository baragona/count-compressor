//count.h



MAYBE void warn(const char * s){
    fputs(s,stderr);
}
MAYBE __attribute__((noreturn)) void die(const char * s){
    warn(s);
    exit(1);
}
//
// MAYBE PURE INLINE int log2_int(uint64_t x){
//     if (x < 1) {
//         return 0 ;
//     }
//     uint64_t mask = ((uint64_t)1) << 32;
//     for (int i=32;i>=0;i--){
//         if (x & mask) {
//             return i+1;
//         }
//
//         mask >>=1;
//     }
//     return 0;
//     //die("Something too big passed to log2_int?\n");
// }

MAYBE PURE INLINE int log2_int(uint64_t x){
    if (x == 0) {
        return 0 ;
    }
    return 64-__builtin_clzl(x);
}


typedef uint64_t string_id ;


//https://code.google.com/p/my-itoa/
MAYBE INLINE int my_itoa(int val, char* buf)
{
    const unsigned int radix = 10;

    char* p;
    unsigned int a;        //every digit
    int len;
    char* b;            //start of the digit char
    char temp;
    unsigned int u;

    p = buf;

    if (val < 0)
    {
        *p++ = '-';
        val = 0 - val;
    }
    u = (unsigned int)val;

    b = p;

    do
    {
        a = u % radix;
        u /= radix;

        *p++ = a + '0';

    } while (u > 0);

    len = (int)(p - buf);

    *p-- = 0;

    //swap
    do
    {
        temp = *p;
        *p = *b;
        *b = temp;
        --p;
        ++b;

    } while (b < p);

    return len;
}

/*base64 stuff*/
//from here, http://stackoverflow.com/questions/342409/how-do-i-base64-encode-decode-in-c
//modified to to not allocate anything and used passed destination pointer

const static char encoding_table[] =   {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                                        'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
                                        'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
                                        'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
                                        'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
                                        'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                                        'w', 'x', 'y', 'z', '0', '1', '2', '3',
                                        '4', '5', '6', '7', '8', '9', '+', '/'};
static char *decoding_table = NULL;
const static int mod_table[] = {0, 2, 1};


MAYBE INLINE void base64_encode(const unsigned char *data,
                    unsigned char *encoded_data,
                    size_t input_length,
                    size_t *output_length) {

    *output_length = ((input_length - 1) / 3) * 4 + 4;

    //char *encoded_data = malloc(*output_length);
    //if (encoded_data == NULL) return NULL;

    for (int i = 0, j = 0; i < input_length;) {

        uint32_t octet_a = i < input_length ? (unsigned char)data[i++] : 0;
        uint32_t octet_b = i < input_length ? (unsigned char)data[i++] : 0;
        uint32_t octet_c = i < input_length ? (unsigned char)data[i++] : 0;

        uint32_t triple = (octet_a << 0x10) + (octet_b << 0x08) + octet_c;

        encoded_data[j++] = encoding_table[(triple >> 3 * 6) & 0x3F];
        encoded_data[j++] = encoding_table[(triple >> 2 * 6) & 0x3F];
        encoded_data[j++] = encoding_table[(triple >> 1 * 6) & 0x3F];
        encoded_data[j++] = encoding_table[(triple >> 0 * 6) & 0x3F];
    }

    for (int i = 0; i < mod_table[input_length % 3]; i++)
        encoded_data[*output_length - 1 - i] = '=';

    //return encoded_data;
}

MAYBE INLINE void build_decoding_table() {

    decoding_table = malloc(256);

    for (int i = 0; i < 64; i++)
        decoding_table[(unsigned char) encoding_table[i]] = i;
}

MAYBE INLINE unsigned char *base64_decode(const char *data,
                             size_t input_length,
                             size_t *output_length) {

    if (decoding_table == NULL) build_decoding_table();

    if (input_length % 4 != 0) return NULL;

    *output_length = input_length / 4 * 3;
    if (data[input_length - 1] == '=') (*output_length)--;
    if (data[input_length - 2] == '=') (*output_length)--;

    unsigned char *decoded_data = malloc(*output_length);
    if (decoded_data == NULL) return NULL;

    for (int i = 0, j = 0; i < input_length;) {

        uint32_t sextet_a = data[i] == '=' ? 0 & i++ : decoding_table[(int)data[i++]];
        uint32_t sextet_b = data[i] == '=' ? 0 & i++ : decoding_table[(int)data[i++]];
        uint32_t sextet_c = data[i] == '=' ? 0 & i++ : decoding_table[(int)data[i++]];
        uint32_t sextet_d = data[i] == '=' ? 0 & i++ : decoding_table[(int)data[i++]];

        uint32_t triple = (sextet_a << 3 * 6)
        + (sextet_b << 2 * 6)
        + (sextet_c << 1 * 6)
        + (sextet_d << 0 * 6);

        if (j < *output_length) decoded_data[j++] = (triple >> 2 * 8) & 0xFF;
        if (j < *output_length) decoded_data[j++] = (triple >> 1 * 8) & 0xFF;
        if (j < *output_length) decoded_data[j++] = (triple >> 0 * 8) & 0xFF;
    }

    return decoded_data;
}




/* end base64 */

/* begin murmurhash3 */

inline uint32_t rotl32 ( uint32_t x, int8_t r )
{
  return (x << r) | (x >> (32 - r));
}

inline uint64_t rotl64 ( uint64_t x, int8_t r )
{
  return (x << r) | (x >> (64 - r));
}

#define ROTL32(x,y)     rotl32(x,y)
#define ROTL64(x,y)     rotl64(x,y)

#define BIG_CONSTANT(x) (x##LLU)


//-----------------------------------------------------------------------------
// Block read - if your platform needs to do endian-swapping or can only
// handle aligned reads, do the conversion here

INLINE uint32_t getblock32 ( const uint32_t * p, int i )
{
  return p[i];
}

INLINE uint64_t getblock64 ( const uint64_t * p, int i )
{
  return p[i];
}

//-----------------------------------------------------------------------------
// Finalization mix - force all bits of a hash block to avalanche

INLINE uint32_t fmix32 ( uint32_t h )
{
  h ^= h >> 16;
  h *= 0x85ebca6b;
  h ^= h >> 13;
  h *= 0xc2b2ae35;
  h ^= h >> 16;

  return h;
}

//----------

INLINE uint64_t fmix64 ( uint64_t k )
{
  k ^= k >> 33;
  k *= BIG_CONSTANT(0xff51afd7ed558ccd);
  k ^= k >> 33;
  k *= BIG_CONSTANT(0xc4ceb9fe1a85ec53);
  k ^= k >> 33;

  return k;
}

//-----------------------------------------------------------------------------

void MurmurHash3_x86_32 ( const void * key, int len,
                          uint32_t seed, void * out )
{
  const uint8_t * data = (const uint8_t*)key;
  const int nblocks = len / 4;

  uint32_t h1 = seed;

  const uint32_t c1 = 0xcc9e2d51;
  const uint32_t c2 = 0x1b873593;

  //----------
  // body

  const uint32_t * blocks = (const uint32_t *)(data + nblocks*4);

  for(int i = -nblocks; i; i++)
  {
    uint32_t k1 = getblock32(blocks,i);

    k1 *= c1;
    k1 = ROTL32(k1,15);
    k1 *= c2;

    h1 ^= k1;
    h1 = ROTL32(h1,13);
    h1 = h1*5+0xe6546b64;
  }

  //----------
  // tail

  const uint8_t * tail = (const uint8_t*)(data + nblocks*4);

  uint32_t k1 = 0;

  switch(len & 3)
  {
  case 3: k1 ^= tail[2] << 16;
  case 2: k1 ^= tail[1] << 8;
  case 1: k1 ^= tail[0];
          k1 *= c1; k1 = ROTL32(k1,15); k1 *= c2; h1 ^= k1;
  };

  //----------
  // finalization

  h1 ^= len;

  h1 = fmix32(h1);

  *(uint32_t*)out = h1;
}

//-----------------------------------------------------------------------------

void MurmurHash3_x86_128 ( const void * key, const int len,
                           uint32_t seed, void * out )
{
  const uint8_t * data = (const uint8_t*)key;
  const int nblocks = len / 16;

  uint32_t h1 = seed;
  uint32_t h2 = seed;
  uint32_t h3 = seed;
  uint32_t h4 = seed;

  const uint32_t c1 = 0x239b961b;
  const uint32_t c2 = 0xab0e9789;
  const uint32_t c3 = 0x38b34ae5;
  const uint32_t c4 = 0xa1e38b93;

  //----------
  // body

  const uint32_t * blocks = (const uint32_t *)(data + nblocks*16);

  for(int i = -nblocks; i; i++)
  {
    uint32_t k1 = getblock32(blocks,i*4+0);
    uint32_t k2 = getblock32(blocks,i*4+1);
    uint32_t k3 = getblock32(blocks,i*4+2);
    uint32_t k4 = getblock32(blocks,i*4+3);

    k1 *= c1; k1  = ROTL32(k1,15); k1 *= c2; h1 ^= k1;

    h1 = ROTL32(h1,19); h1 += h2; h1 = h1*5+0x561ccd1b;

    k2 *= c2; k2  = ROTL32(k2,16); k2 *= c3; h2 ^= k2;

    h2 = ROTL32(h2,17); h2 += h3; h2 = h2*5+0x0bcaa747;

    k3 *= c3; k3  = ROTL32(k3,17); k3 *= c4; h3 ^= k3;

    h3 = ROTL32(h3,15); h3 += h4; h3 = h3*5+0x96cd1c35;

    k4 *= c4; k4  = ROTL32(k4,18); k4 *= c1; h4 ^= k4;

    h4 = ROTL32(h4,13); h4 += h1; h4 = h4*5+0x32ac3b17;
  }

  //----------
  // tail

  const uint8_t * tail = (const uint8_t*)(data + nblocks*16);

  uint32_t k1 = 0;
  uint32_t k2 = 0;
  uint32_t k3 = 0;
  uint32_t k4 = 0;

  switch(len & 15)
  {
  case 15: k4 ^= tail[14] << 16;
  case 14: k4 ^= tail[13] << 8;
  case 13: k4 ^= tail[12] << 0;
           k4 *= c4; k4  = ROTL32(k4,18); k4 *= c1; h4 ^= k4;

  case 12: k3 ^= tail[11] << 24;
  case 11: k3 ^= tail[10] << 16;
  case 10: k3 ^= tail[ 9] << 8;
  case  9: k3 ^= tail[ 8] << 0;
           k3 *= c3; k3  = ROTL32(k3,17); k3 *= c4; h3 ^= k3;

  case  8: k2 ^= tail[ 7] << 24;
  case  7: k2 ^= tail[ 6] << 16;
  case  6: k2 ^= tail[ 5] << 8;
  case  5: k2 ^= tail[ 4] << 0;
           k2 *= c2; k2  = ROTL32(k2,16); k2 *= c3; h2 ^= k2;

  case  4: k1 ^= tail[ 3] << 24;
  case  3: k1 ^= tail[ 2] << 16;
  case  2: k1 ^= tail[ 1] << 8;
  case  1: k1 ^= tail[ 0] << 0;
           k1 *= c1; k1  = ROTL32(k1,15); k1 *= c2; h1 ^= k1;
  };

  //----------
  // finalization

  h1 ^= len; h2 ^= len; h3 ^= len; h4 ^= len;

  h1 += h2; h1 += h3; h1 += h4;
  h2 += h1; h3 += h1; h4 += h1;

  h1 = fmix32(h1);
  h2 = fmix32(h2);
  h3 = fmix32(h3);
  h4 = fmix32(h4);

  h1 += h2; h1 += h3; h1 += h4;
  h2 += h1; h3 += h1; h4 += h1;

  ((uint32_t*)out)[0] = h1;
  ((uint32_t*)out)[1] = h2;
  ((uint32_t*)out)[2] = h3;
  ((uint32_t*)out)[3] = h4;
}

//-----------------------------------------------------------------------------

void MurmurHash3_x64_128 ( const void * key, const int len,
                           const uint32_t seed, void * out )
{
  const uint8_t * data = (const uint8_t*)key;
  const int nblocks = len / 16;

  uint64_t h1 = seed;
  uint64_t h2 = seed;

  const uint64_t c1 = BIG_CONSTANT(0x87c37b91114253d5);
  const uint64_t c2 = BIG_CONSTANT(0x4cf5ad432745937f);

  //----------
  // body

  const uint64_t * blocks = (const uint64_t *)(data);

  for(int i = 0; i < nblocks; i++)
  {
    uint64_t k1 = getblock64(blocks,i*2+0);
    uint64_t k2 = getblock64(blocks,i*2+1);

    k1 *= c1; k1  = ROTL64(k1,31); k1 *= c2; h1 ^= k1;

    h1 = ROTL64(h1,27); h1 += h2; h1 = h1*5+0x52dce729;

    k2 *= c2; k2  = ROTL64(k2,33); k2 *= c1; h2 ^= k2;

    h2 = ROTL64(h2,31); h2 += h1; h2 = h2*5+0x38495ab5;
  }

  //----------
  // tail

  const uint8_t * tail = (const uint8_t*)(data + nblocks*16);

  uint64_t k1 = 0;
  uint64_t k2 = 0;

  switch(len & 15)
  {
  case 15: k2 ^= ((uint64_t)tail[14]) << 48;
  case 14: k2 ^= ((uint64_t)tail[13]) << 40;
  case 13: k2 ^= ((uint64_t)tail[12]) << 32;
  case 12: k2 ^= ((uint64_t)tail[11]) << 24;
  case 11: k2 ^= ((uint64_t)tail[10]) << 16;
  case 10: k2 ^= ((uint64_t)tail[ 9]) << 8;
  case  9: k2 ^= ((uint64_t)tail[ 8]) << 0;
           k2 *= c2; k2  = ROTL64(k2,33); k2 *= c1; h2 ^= k2;

  case  8: k1 ^= ((uint64_t)tail[ 7]) << 56;
  case  7: k1 ^= ((uint64_t)tail[ 6]) << 48;
  case  6: k1 ^= ((uint64_t)tail[ 5]) << 40;
  case  5: k1 ^= ((uint64_t)tail[ 4]) << 32;
  case  4: k1 ^= ((uint64_t)tail[ 3]) << 24;
  case  3: k1 ^= ((uint64_t)tail[ 2]) << 16;
  case  2: k1 ^= ((uint64_t)tail[ 1]) << 8;
  case  1: k1 ^= ((uint64_t)tail[ 0]) << 0;
           k1 *= c1; k1  = ROTL64(k1,31); k1 *= c2; h1 ^= k1;
  };

  //----------
  // finalization

  h1 ^= len; h2 ^= len;

  h1 += h2;
  h2 += h1;

  h1 = fmix64(h1);
  h2 = fmix64(h2);

  h1 += h2;
  h2 += h1;

  ((uint64_t*)out)[0] = h1;
  ((uint64_t*)out)[1] = h2;
}


MAYBE PURE INLINE uint32_t murmur_hash_wrapper(const char *key, const size_t len){
    uint32_t out;
    MurmurHash3_x86_32(key, len, 123456789,&out);
    return out;
}

/* end murmurhash3 */


PURE INLINE uint32_t jenkins_hash(const char *key, const size_t len){
    uint32_t hash, i;

    if(len<=4){
        //Custom modification: do no mixing for ultra short keys
        hash=0;
        for(i = 0; i < len; ++i){
            hash <<=8;
            hash|=((unsigned char *)key)[i];
        }
        return hash;
    }else
//     if(len==1){
//         return ((unsigned char *) key)[0];
//     }else if(len==2){
//         return ((uint16_t *) key)[0];
//     }else if(len==3){
//         return (((uint32_t *) key)[0]) & 0xFFFFFF00;
//     }else if(len==4){
//         return ((uint32_t *) key)[0];
//     }else
    {

        hash = len;//CUSTOM MODIFICATION: initialize hash to length

        for(i = 0; i < len; ++i)
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
}

MAYBE PURE INLINE char my_memcmp(const void *a, const void *b, const size_t len){//only compare for equality


    if(len<=8){
        uint64_t val_a=0;
        uint64_t val_b=0;
        for(int i = 0; i < len; i++){
            val_a <<=8;
            val_a |=((unsigned char *)a)[i];
            val_b <<=8;
            val_b |=((unsigned char *)b)[i];
        }
        if(val_a == val_b){
            return 0;
        }else{
            return 1;
        }
    }else{
        return memcmp(a,b,len);
//         for(int i = 0; i < len; i++){
//             if((((unsigned char *)a)[i]) != (((unsigned char *)b)[i])){
//                 return 1;
//             }
//         }
//         return 0;
    }

}

MAYBE PURE INLINE uint32_t calc_bstring_hash(const_bstring b){
    return jenkins_hash((char *)(b->data), b->slen);
}

MAYBE PURE INLINE int ip_get_unbinarized_bufsize(){
    return 16;
}

MAYBE PURE INLINE int datetime_get_bufsize(){
    return 20;
}

MAYBE PURE INLINE int short_uuid_get_bufsize(){
    return 14;
}

MAYBE INLINE void ip_unbinarize(bstring src, bstring dest){
    int idx=0;
    for(int i=0;i<4;i++){
        idx+=my_itoa(src->data[i], (char *)(dest->data+idx));
        dest->data[idx]='.';idx++;
    }
    dest->data[idx-1]=0;//overwrite last dot with null
    dest->slen=idx-1;
}

MAYBE INLINE void short_uuid_unbinarize(bstring src, bstring dest){
    size_t out_length;
    base64_encode(src->data, dest->data, src->slen, &out_length);
    dest->data[out_length]=0;
    dest->slen=out_length;
}

MAYBE INLINE void datetime_from_integer(bstring src, bstring dest){
    long long diff = atoll((char *)src->data);

    uint64_t s = diff % 60;
    diff -= s;
    diff /= 60;
    uint64_t mi = diff % 60;
    diff -= mi;
    diff /= 60;
    uint64_t h  = diff % 24;
    diff -= h;
    diff /= 24;
    uint64_t d  = diff % 31;
    diff -= d;
    diff /= 31;
    uint64_t mo = diff % 12;
    diff -= mo;
    diff /= 12;
    uint64_t y  = diff + 2000;
    int amt=20;


    for(int i=0;i<20;i++){
        dest->data[i]=0;
    }

    int pos=0;
    my_itoa(y,(char *)dest->data+pos);//assume 4 digit year!
    pos=5;
    if(mo<10){pos++;}
    my_itoa(mo,(char *)dest->data+pos);
    pos=8;
    if(d<10){pos++;}
    my_itoa(d,(char *)dest->data+pos);
    pos=11;

    if(h<10){pos++;}
    my_itoa(h,(char *)dest->data+pos);
    pos=14;

    if(mi<10){pos++;}
    my_itoa(mi,(char *)dest->data+pos);
    pos=17;

    if(s<10){pos++;}
    my_itoa(s,(char *)dest->data+pos);

    static const char * template = "0000-00-00 00:00:00";

    for(int i=0;i<20;i++){
        if(dest->data[i] == 0 ){
            dest->data[i]=template[i];
        }
    }

    //int amt = snprintf((char *)dest->data,20, "%04d-%02d-%02d %02d:%02d:%02d", (int)y, (int)mo, (int)d, (int)h, (int)mi, (int)s);
    dest->data[amt]=0;
    dest->slen=amt;
}



