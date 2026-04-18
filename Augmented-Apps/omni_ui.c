#include "omni_types.h"

void clean_input() {
    int c; while ((c = getchar()) != '\n' && c != EOF);
}

void show_full_day_report(HomeState *s) {
    const char* s_n[] = {"GRID", "BATT", "SOLR"};
    const char* st_n[] = {"OFF", "SAVE", "ACTV", "MAX"};
    CLEAR_SCREEN;
    printf("\n=== CHRONOLOGICAL SYSTEM LOGS ===\n");
    printf(">> TOTAL LOG ENTRIES RECORDED: %d <<\n", s->reports_saved); // Log sayısı burada!
    printf("Line | Hour  | Temp  | Batt  | Power | AC Status | Alarm\n");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < s->reports_saved; i++) {
        HourlyReport r = s->daily_history[i];
        printf("#%03d | %02d:00 | %4.1fC | %4.1f%% | %-5s | %-9s | %s\n", 
               i+1, r.hour, r.temp, r.battery, s_n[r.src], st_n[r.air], st_n[r.alarm]);
    }
    printf("\nPress ENTER to return to Dashboard...");
    fflush(stdout); clean_input(); getchar();
}

void change_pin_ui(Config *cfg) {
    int old_pin, new_pin;
    printf("\n[SECURITY] Enter OLD PIN: "); fflush(stdout);
    if(scanf("%d", &old_pin) != 1) { clean_input(); return; }
    if (old_pin == cfg->pin) {
        printf("Enter NEW PIN: "); fflush(stdout);
        scanf("%d", &new_pin); cfg->pin = new_pin;
        printf("PIN updated successfully!\n");
    } else printf("Wrong PIN! Access denied.\n");
    clean_input(); getchar();
}

void show_smart_dashboard(HomeState *c) {
    const char* m_n[] = {"DISABLED", "HOME", "AWAY", "PANIC"};
    const char* s_n[] = {"GRID", "BATTERY", "SOLAR"};
    const char* st_n[] = {"OFF", "SAVING", "ACTIVE", "MAX_ALERT"};
    printf("\n>>> CURRENT SYSTEM STATUS <<<\n");
    printf("Time: %02d:00 | Battery: %.1f%% | Temp: %.1fC\n", c->hour, c->battery, c->temp);
    printf("------------------------------------\n");
    printf("[MODE]   : %s\n", m_n[c->mode]);
    printf("[POWER]  : %s\n", s_n[c->source]);
    printf("[CLIMATE]: %s (AC)\n", st_n[c->air]);
    printf("[LIGHTS] : %s\n", (c->lights == 0 ? "OFF" : (c->lights == 1 ? "HALLWAY" : "ALL OPEN")));
    printf("------------------------------------\n");
    fflush(stdout); 
}