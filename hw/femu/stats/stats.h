#include "../nvme.h"
#include <pthread.h>

// 통계 데이터를 위한 구조체
typedef struct statistics {
    uint64_t host_read_count;   // host가 요청한 읽기 횟수
    uint64_t host_write_count;  // host가 요청한 쓰기 횟수
    uint64_t gc_write_count;    // gc가 요청한 쓰기 횟수
    uint64_t victim_line_count; // gc가 victim line을 선정한 횟수
} statistics;

// 통계 데이터를 위한 전역 변수
extern statistics stats;

// 통계 데이터를 업데이트하는 함수들
void increase_host_read_count(void);

void increase_host_write_count(void);

void increase_gc_write_count(int);

void increase_victim_line_count(void);

void print_and_reset_stats(unsigned long);

void *stats_thread_func(void*);