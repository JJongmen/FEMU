#include "../nvme.h"
#include "./stats.h"

statistics stats = {{0}, 64};

void increase_victim_line_count_and_print_stats(int line_id) {
    stats.selected_counts[line_id]++;
    print_stats();
}

// 통계 데이터를 출력하는 함수
void print_stats(void) {
    for (int i = 0; i < stats.tt_lines - 1; i++) {
        printf("%d,", stats.selected_counts[i]);
    }
    printf("%d\r\n", stats.selected_counts[stats.tt_lines - 1]);
}
