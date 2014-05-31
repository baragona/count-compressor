#line 457

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>

#include <unordered_map>

#define INLINE __attribute__((always_inline)) static
#define PURE __attribute__((pure))
#define MAYBE __attribute__((unused))
#include "count.h"




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

int main(int argc, char ** argv){

    const int BINARY = 4;
    const int BINARY2 = 5;
    const __uint128_t one = 1;
    //__uint128_t test=one<<5;
    string_id col_to_stored_vals[2274]; //FLAT ARRAY for all cols
    int col_to_n_stored_vals[19]={0};

    //my %col_to_value_to_friends_str_to_count;
    //my %col_to_value_to_most_popular_friends;
    //my %col_to_friends_str_to_count;
    //my %col_to_most_popular_friends;
    uint64_t col_to_ref_count[19];
    uint64_t col_to_ref_sum[19];
    int r=0;

    while(! stream_finished(BINARY)){

        const int driving_column = 3;
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

                }else{

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

