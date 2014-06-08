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

PURE INLINE uint32_t jenkins_hash(const char *key, size_t len){
    uint32_t hash, i;

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

    int amt = snprintf((char *)dest->data,20, "%04d-%02d-%02d %02d:%02d:%02d", (int)y, (int)mo, (int)d, (int)h, (int)mi, (int)s);
    dest->data[amt]=0;
    dest->slen=amt;
}



