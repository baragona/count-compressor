#include <stdio.h>
#include "khash.h"


//KHASH_MAP_INIT_INT(the_hash, char)
KHASH_INIT(the_hash, uint32_t, uint64_t, 1, kh_int_hash_func, kh_int_hash_equal)
int main() {
	int ret, is_missing;
	khiter_t k;

	khash_t(the_hash) *h = kh_init(the_hash);
	puts("ding\n");
	kh_resize(the_hash, h, 200000);
	puts("dong\n");
	//sleep(1000);
	k = kh_put(the_hash, h, 5, &ret);
	puts("dong\n");
	if (!ret) {kh_del(the_hash, h, k);puts("dong\n");}
	kh_value(h, k) = 10;
	puts("dong\n");
	k = kh_get(the_hash, h, 10);
	puts("dong\n");
	is_missing = (k == kh_end(h));
	puts("dong\n");
	k = kh_get(the_hash, h, 5);
	puts("dong\n");
	kh_del(the_hash, h, k);
	puts("dong\n");
	/*
	for (k = kh_begin(h); k != kh_end(h); ++k){
		if (kh_exist(h, k)) {kh_value(h, k) = 1;}
		puts("dong\n");
	}
	*/
	kh_destroy(the_hash, h);
    puts("dong\n");

	return 0;
}

