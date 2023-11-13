#include "../nvme.h"
#include "./stats.h"

statistics stats = {0};

// 통계 데이터를 출력하고 리셋하는 함수
void print_and_reset_stats(unsigned long seconds) {
    // 통계 데이터 출력
    printf("[%lu sec], Host_Read_Count: %lu, Host_Write_Count: %lu, GC_Write_Count: %lu, Victim_Line_Count: %lu\r\n", 
           seconds, stats.host_read_count, stats.host_write_count, stats.gc_write_count, stats.victim_line_count);
    // 통계 데이터 리셋
    memset(&stats, 0, sizeof(stats));
}

// 1초마다 통계를 출력하고 초기화하는 스레드 함수
void *stats_thread_func(void *arg) {
    unsigned long elapsed_seconds = 0;  // 경과 시간
    while (1) {
        sleep(1); // 1초 대기
        print_and_reset_stats(++elapsed_seconds); // 통계 출력 및 초기화
    }
    return NULL;
}

void increase_host_read_count(void) {
    stats.host_read_count++;
}

void increase_host_write_count(void) {
    stats.host_write_count++;
}

void increase_gc_write_count(int vpc) {
    stats.gc_write_count += vpc;
}

void increase_victim_line_count(void) {
    stats.victim_line_count++;    
}
