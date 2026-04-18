#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void show_status(int m, int al, int cl, int li, int src);
float get_random_temp();
char get_random_motion();

int main() {
    int mode, hour, source = 1, air, security, alarm;
    int lights = 0; 
    float temp = 0;
    char motion = 'N', update_choice;
    int wrong_count = 0;
    int is_first_run = 1;
    int running = 1;

    srand(time(NULL)); 

    while (running) {
        printf("\n=== OMNI-GUARD COMMAND CENTER ===\n");
        if (wrong_count > 0) printf("[!] Wrong entry count: %d/5\n", wrong_count);
        printf("0: Exit | 1: Disabled | 2: Home | 3: Away | 4: Panic\n");
        printf("Selection: ");
        
        if (scanf("%d", &mode) != 1) {
            printf("Enter a number kanka!\n");
            while(getchar() != '\n');
            wrong_count++;
            if (wrong_count >= 5) mode = 4; else continue;
        }

        if (mode == 0) break;

        if (mode < 0 || mode > 4) {
            wrong_count++;
            if (wrong_count >= 5) {
                printf("\n!!! SECURITY BREACH: PANIC MODE ACTIVE !!!\n");
                mode = 4;
            } else {
                printf("Invalid mode! Try again.\n");
                continue;
            }
        } else {
            wrong_count = 0; 
        }

        if (mode != 4) {
            printf("Select Energy Source (1: Grid, 2: Battery, 3: Solar): ");
            if (scanf("%d", &source) != 1 || source < 1 || source > 3) {
                printf("[!] Invalid source! Defaulting to Grid (1).\n");
                while(getchar() != '\n');
                source = 1;
            }
        }

        if (is_first_run) {
            temp = get_random_temp();
            motion = get_random_motion();
            is_first_run = 0;
            printf("\n[*] Initial sensors synced: %.1fC, Motion: %c\n", temp, motion);
        } else {
            printf("Update sensors? (G: Update / S: Skip): ");
            scanf(" %c", &update_choice);
            if (update_choice == 'G' || update_choice == 'g') {
                temp = get_random_temp();
                motion = get_random_motion();
                printf("[*] Sensors updated: %.1fC, Motion: %c\n", temp, motion);
            }
        }

        security = 1; air = 0; alarm = 0;
        
        if (mode == 4) {
            alarm = 2; lights = 2; air = 0;
        } else {
            if (lights == 0) { 
                if (mode == 2 && (motion == 'Y' || motion == 'y')) lights = 1;
            }

            if (mode == 1) { air = 2; security = 0; }
            else if (mode == 3) {
                if (motion == 'Y' || motion == 'y') alarm = 1;
                air = 1;
            }

            if ((source == 1 || source == 3) && (temp < 20 || temp > 25)) air = 2;
            else if (source == 2 && (temp < 15 || temp > 30)) air = 2;
        }

        show_status(mode, alarm, air, lights, source);
    }

    return 0;
}

void show_status(int m, int al, int cl, int li, int src) {
    char *src_name;
    switch(src) {
        case 1: src_name = "Grid"; break;
        case 2: src_name = "Battery"; break;
        case 3: src_name = "Solar"; break;
        default: src_name = "Unknown";
    }

    printf("\n--- SYSTEM REPORT ---\n");
    printf("Mode: %d | Source: %s | Alarm: %d | AC: %d\n", m, src_name, al, cl);
    printf("Lights: %s\n", (li == 0 ? "MANUAL" : (li == 1 ? "AUTO-ON" : "EMERGENCY-ON")));
    printf("---------------------\n");
}

float get_random_temp() {
    return (float)(rand() % 23 + 13);
}

char get_random_motion() {
    return (rand() % 2 == 0) ? 'Y' : 'N';
}
