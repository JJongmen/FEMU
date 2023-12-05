#include "../nvme.h"
#include "./stats.h"

statistics stats = {{0}, 64, 0, false, 100, 0, 64};

void increase_lines_erase_counts_and_print_stats(int line_id) {
    if (!stats.reached) {
        if (++stats.lines_erase_counts[line_id] == 64) {
            stats.reached = true;
            print_stats();
        }
    }
}

// 통계 데이터를 출력하는 함수
void print_stats(void) {
    printf("Host Write IO Count : %d\r\n", stats.host_write_io_count);
    for (int i = 0; i < stats.tt_lines - 1; i++) {
        printf("%d,", stats.lines_erase_counts[i]);
    }
    printf("%d\r\n", stats.lines_erase_counts[stats.tt_lines - 1]);
}

void increase_host_write_io_count(void) {
    stats.host_write_io_count++;
}
