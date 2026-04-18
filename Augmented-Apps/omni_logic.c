#include "omni_types.h"

void save_report(HomeState *s) {
    if (s->reports_saved < MAX_REPORT_ENTRIES) {
        int idx = s->reports_saved;
        s->daily_history[idx].hour = s->hour;
        s->daily_history[idx].temp = s->temp;
        s->daily_history[idx].battery = s->battery;
        s->daily_history[idx].src = s->source;
        s->daily_history[idx].air = s->air;
        s->daily_history[idx].lights = s->lights;
        s->daily_history[idx].alarm = s->alarm;
        s->daily_history[idx].motion = s->motion;
        s->reports_saved++;
    }
}

void process_logic(HomeState *c, int is_time_passing) {
    // --- Agresif Sıcaklık Değişimi ---
    // Değişimi +/- 3.5 dereceye çıkardık ki klima tetiklensin
    float variation = ((float)(rand() % 71) - 35.0) / 10.0; 
    c->temp += variation;

    // Sınırları biraz genişlettik (10C - 40C)
    if (c->temp < 10) c->temp = 10;
    if (c->temp > 40) c->temp = 40;
    
    c->motion = (rand() % 2 == 0) ? 'Y' : 'N';

    if (c->mode == PANIC) c->source = GRID;
    else if (c->hour >= 10 && c->hour <= 16) c->source = SOLAR;
    else if (c->battery < 20) c->source = GRID;
    else c->source = BATTERY;

    // KLİMA MANTIĞI: 20'den düşük veya 25'ten yüksekse AC AÇILIR
    if (c->mode == PANIC) { c->alarm = MAX_STATUS; c->lights = 2; c->air = ACTIVE; }
    else if (c->mode == AWAY) {
        c->lights = 0; c->air = SAVING;
        c->alarm = (c->motion == 'Y') ? ACTIVE : OFF;
    } else {
        c->alarm = OFF;
        c->lights = (c->motion == 'Y') ? 1 : 0;
        // Kritik eşikler: 20C ve 25C
        c->air = (c->temp < 20.0 || c->temp > 25.0) ? ACTIVE : OFF;
    }

    if (is_time_passing) {
        if (c->source == GRID) c->grid_h++;
        else if (c->source == BATTERY) { c->bat_h++; c->battery -= 2.0; }
        else if (c->source == SOLAR) { 
            c->solar_h++; c->battery += 1.5; 
            if (c->battery > 100) c->battery = 100; 
        }
        if (c->battery < 0) c->battery = 0;
    }
    save_report(c);
}