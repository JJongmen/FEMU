#include "../nvme.h"

// 통계 데이터를 위한 구조체
typedef struct statistics {
    int selected_counts[64];  // line별 victim line으로 선택된 횟수
    int tt_lines;
} statistics;

// 통계 데이터를 위한 전역 변수
extern statistics stats;

// 통계 데이터를 업데이트하는 함수
void increase_victim_line_count_and_print_stats(int);   // 입력된 line의 id의 victim line 선정 횟수를 늘린다

void print_stats(void);
