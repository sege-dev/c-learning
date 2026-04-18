#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define CLEAR_SCREEN printf("\033[H\033[J")

#define MAX_LOGS 10
#define CORRECT_PIN 1907

typedef enum { DISABLED, HOME, AWAY, PANIC } Mode;
typedef enum { GRID, BATTERY, SOLAR } Source;
typedef enum { OFF, SAVING, ACTIVE, MAX } Status;

typedef struct { int hour; char msg[100]; } LogEntry;

typedef struct {
    Mode mode; Source source; Status air; Status alarm;
    int lights; float battery; float temp; int hour;
    int grid_h, bat_h, solar_h;
    LogEntry history[MAX_LOGS]; int log_count;
    char motion;
} HomeState;

void show_smart_dashboard(HomeState *c, HomeState *p);
void add_log(HomeState *s, const char *text);
void clean_input();

int main() {
    HomeState h = {DISABLED, GRID, OFF, OFF, 0, 100.0, 22.0, 12, 0, 0, 0, {}, 0, 'N'};
    HomeState p;
    int input, user_pin, loop = 0;
    srand(time(NULL));

    while (1) {
        if (loop % 5 == 0) {
            CLEAR_SCREEN;
            printf("\n[SECURITY] PIN REQUIRED: "); fflush(stdout);
            if (scanf("%d", &user_pin) != 1 || user_pin != CORRECT_PIN) {
                printf("\nAccess Denied!\n"); clean_input(); continue;
            }
            clean_input();
        }

        CLEAR_SCREEN;
        printf("\n\n=== OMNI-GUARD COMMAND CENTER v3.6 ===\n");
        printf("-1: Exit | 0: Logs | 1: Disabled | 2: Home | 3: Away | 4: Panic | 5: Update\n");
        printf("Current Hour: %02d:00 | Selection: ", h.hour);
        fflush(stdout);
        
        if (scanf("%d", &input) != 1) { clean_input(); continue; }
        if (input == -1) break;

        p = h; 

        if (input == 5) {
            h.temp = (float)(rand() % 23 + 13);
            h.motion = (rand() % 2 == 0) ? 'Y' : 'N';
            add_log(&h, "Sensors updated");
        } else if (input >= 1 && input <= 4) {
            h.mode = (Mode)(input - 1);
        }

        if (h.mode == PANIC) { h.source = GRID; h.alarm = MAX; h.lights = 2; }
        else {
            if (h.hour >= 10 && h.hour <= 16) h.source = SOLAR;
            else if (h.battery < 20) h.source = GRID;
            else h.source = BATTERY;

            if (h.mode == AWAY) {
                h.lights = 0; h.air = SAVING;
                if (h.motion == 'Y') { h.alarm = ACTIVE; add_log(&h, "Intruder Alert!"); }
                else h.alarm = OFF;
            } else if (h.mode == HOME) {
                h.alarm = OFF;
                h.lights = (h.motion == 'Y') ? 1 : 0;
                h.air = (h.temp < 20 || h.temp > 25) ? ACTIVE : OFF;
            }
        }

        if (h.source == GRID) h.grid_h++;
        else if (h.source == BATTERY) { h.bat_h++; h.battery -= 2.0; }
        else if (h.source == SOLAR) { h.solar_h++; h.battery += 1.5; if (h.battery > 100) h.battery = 100; }
        if (h.battery < 0) h.battery = 0;

        show_smart_dashboard(&h, &p);
        
        printf("\n>> [DONE] Press ENTER to go to %02d:00...", (h.hour + 1) % 24);
        fflush(stdout);
        clean_input();
        getchar();

        h.hour = (h.hour + 1) % 24;
        loop++;
    }
    return 0;
}

void clean_input() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void add_log(HomeState *s, const char *text) {
    if (s->log_count < MAX_LOGS) {
        s->history[s->log_count].hour = s->hour;
        strncpy(s->history[s->log_count].msg, text, 99);
        s->log_count++;
    }
}

void show_smart_dashboard(HomeState *c, HomeState *p) {
    const char* m_n[] = {"DISABLED", "HOME", "AWAY", "PANIC"};
    const char* s_n[] = {"GRID", "BATTERY", "SOLAR"};
    const char* st_n[] = {"OFF", "SAVING", "ACTIVE", "MAX_ALERT"};

    printf("\n\n>>> SYSTEM REPORT <<<\n");
    printf("Time: %02d:00 | Battery: %.1f%% | Temp: %.1fC\n", c->hour, c->battery, c->temp);
    printf("------------------------------------\n");

    if (c->mode != p->mode) printf("[MODE]   : %s -> %s\n", m_n[p->mode], m_n[c->mode]);
    else printf("[MODE]   : %s\n", m_n[c->mode]);

    if (c->source != p->source) printf("[POWER]  : %s -> %s\n", s_n[p->source], s_n[c->source]);
    else printf("[POWER]  : %s\n", s_n[c->source]);

    if (c->air != p->air) printf("[CLIMATE]: %s -> %s\n", st_n[p->air], st_n[c->air]);
    else printf("[CLIMATE]: %s\n", st_n[c->air]);

    if (c->alarm != p->alarm) printf("[ALARM]  : %s -> %s\n", st_n[p->alarm], st_n[c->alarm]);
    else printf("[ALARM]  : %s\n", st_n[c->alarm]);

    printf("[LIGHTS] : %s\n", (c->lights == 0 ? "OFF" : (c->lights == 1 ? "HALLWAY" : "ALL OPEN")));
    printf("------------------------------------\n");
    
    if (c->mode == AWAY && c->motion == 'Y') printf("!!! WARNING: MOTION DETECTED !!!\n");

    fflush(stdout); 
}
