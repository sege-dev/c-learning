#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

void show_status(int m, int al, int cl, int li, int src, float bat);
float get_random_temp();
char get_random_motion();

int main() {
    int mode, hour = 12, source = 1, air, security, alarm;
    int lights = 0; 
    float temp = 0, battery = 100.0;
    char motion = 'N';
    int wrong_count = 0, is_first_run = 1, running = 1;

    srand(time(NULL)); 

    while (running) {
        if (is_first_run) {
            temp = get_random_temp();
            motion = get_random_motion();
            is_first_run = 0;
        }

        system(CLEAR);

        printf("\n=== OMNI-GUARD COMMAND CENTER ===\n");
        printf("0: Exit | 1: Disabled | 2: Home | 3: Away | 4: Panic | 5: UPDATE SENSORS\n");
        printf("Current Hour: %02d:00 | Selection: ", hour);
        
        if (scanf("%d", &mode) != 1) {
            printf("\nEnter a number!");
            while(getchar() != '\n');
            wrong_count++;
            if (wrong_count >= 5) mode = 4; else {
                printf("\nPress Enter to try again...");
                getchar(); getchar();
                continue;
            }
        }

        if (mode == 0) break;
        
        if (mode == 5) {
            temp = get_random_temp();
            motion = get_random_motion();
            hour = (hour + 1) % 24;
            continue; 
        }

        if (mode < 0 || mode > 4) {
            wrong_count++;
            if (wrong_count >= 5) mode = 4; else {
                printf("\nInvalid mode! Press Enter to try again...");
                getchar(); getchar();
                continue;
            }
        } else {
            wrong_count = 0; 
        }

        if (battery <= 0) {
            source = 1;
            battery = 0;
        } else if (hour >= 10 && hour <= 16) {
            source = 3;
        } else if (battery < 20) {
            source = 1;
        } else {
            source = 2;
        }

        security = 1; air = 0; alarm = 0;
        
        if (mode == 4) {
            alarm = 2; lights = 2; air = 0;
        } else {
            if (lights == 0 && mode == 2 && (motion == 'Y' || motion == 'y')) lights = 1;
            if (mode == 1) { air = 2; security = 0; }
            else if (mode == 3) {
                if (motion == 'Y' || motion == 'y') alarm = 1;
                air = 1;
            }
            if ((source == 1 || source == 3) && (temp < 20 || temp > 25)) air = 2;
            else if (source == 2 && (temp < 15 || temp > 30)) air = 2;
        }

        if (source == 2) {
            if (air == 2) battery -= 5.0;
            if (security == 1) battery -= 1.0;
            if (lights >= 1) battery -= 0.5;
        } else if (source == 3) {
            battery += 2.0;
            if (battery > 100) battery = 100;
        }

        show_status(mode, alarm, air, lights, source, battery);
        
        if (battery <= 0) printf("[!] WARNING: Battery exhausted! Switched to GRID.\n");

        printf("\n>> Devam etmek icin ENTER'a bas...");
        while(getchar() != '\n'); 
        getchar(); 

        hour = (hour + 1) % 24; 
    }

    return 0;
}

void show_status(int m, int al, int cl, int li, int src, float bat) {
    char *src_name;
    switch(src) {
        case 1: src_name = "GRID"; break;
        case 2: src_name = "BATTERY"; break;
        case 3: src_name = "SOLAR"; break;
        default: src_name = "Unknown";
    }

    printf("\n>>> STATUS DASHBOARD <<<\n");
    printf("Mode: %d | Source: %s | Battery: [%.1f%%]\n", m, src_name, bat);
    printf("Climate: %d | Alarm: %d | Lights: %s\n", cl, al, (li == 0 ? "MANUAL" : (li == 1 ? "AUTO" : "MAX")));
    printf("------------------------\n");
}

float get_random_temp() { return (float)(rand() % 23 + 13); }
char get_random_motion() { return (rand() % 2 == 0) ? 'Y' : 'N'; }
