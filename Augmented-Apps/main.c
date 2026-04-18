#include "omni_types.h"

void process_logic(HomeState *c, int is_time_passing);
void show_smart_dashboard(HomeState *c);
void show_full_day_report(HomeState *s);
void change_pin_ui(Config *cfg);
void clean_input();

int main() {
    Config cfg = {CORRECT_PIN};
    HomeState h = {DISABLED, GRID, OFF, OFF, 0, 100.0, 22.0, 12, 0, 0, 0, {0}, 0, 'N'};
    int input, loop = 0;
    srand(time(NULL));

    while (1) {
        if (loop % 5 == 0) {
            CLEAR_SCREEN;
            int user_pin;
            printf("\n[SECURITY] PIN REQUIRED: "); fflush(stdout);
            if (scanf("%d", &user_pin) != 1 || user_pin != cfg.pin) {
                printf("Access Denied!\n"); clean_input(); continue;
            }
            clean_input();
        }

        CLEAR_SCREEN;
        printf("=== OMNI-GUARD v4.9 (Live Simulation) ===\n");
        printf("------------------------------------------------------------\n");
        printf(" 1: DISABLED | 2: HOME | 3: AWAY  | 4: PANIC\n");
        printf(" 5: REFRESH  | 0: LOGS | 9: PIN   | -1: EXIT\n");
        printf("------------------------------------------------------------\n");
        printf("Current Time: %02d:00 | Selection: ", h.hour); // Log sayısı buradan kaldırıldı!
        fflush(stdout);
        
        if (scanf("%d", &input) != 1) { clean_input(); continue; }
        
        if (input == -1) break;
        if (input == 0) { show_full_day_report(&h); continue; }
        if (input == 9) { change_pin_ui(&cfg); continue; }

        if (input == 5) {
            process_logic(&h, 0); 
            show_smart_dashboard(&h);
            printf("\n>> [REFRESHED] Still at %02d:00. Press ENTER...", h.hour);
            fflush(stdout); clean_input(); getchar();
            continue; 
        }

        if (input >= 1 && input <= 4) {
            h.mode = (Mode)(input - 1);
            process_logic(&h, 1); 
            show_smart_dashboard(&h);
            printf("\n>> Mode Set. Press ENTER to advance to %02d:00...", (h.hour == 23) ? 0 : h.hour + 1);
            fflush(stdout); clean_input(); getchar();

            if (h.hour == 23) {
                h.hour = 0;
                h.reports_saved = 0; 
            } else {
                h.hour++;
            }
            loop++;
        } else {
            printf("Invalid selection!\n"); clean_input(); getchar();
        }
    }
    return 0;
}