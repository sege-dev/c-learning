#ifndef OMNI_TYPES_H
#define OMNI_TYPES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define CORRECT_PIN 1907
#define CLEAR_SCREEN printf("\033[H\033[J")
#define MAX_REPORT_ENTRIES 500 

typedef enum { DISABLED, HOME, AWAY, PANIC } Mode;
typedef enum { GRID, BATTERY, SOLAR } Source;
typedef enum { OFF, SAVING, ACTIVE, MAX_STATUS } Status;

typedef struct {
    int hour; float temp; float battery; Source src;
    Status air; int lights; Status alarm; char motion;
} HourlyReport;

typedef struct { int pin; } Config;

typedef struct {
    Mode mode; Source source; Status air; Status alarm;
    int lights; float battery; float temp; int hour;
    int grid_h; int bat_h; int solar_h;
    HourlyReport daily_history[MAX_REPORT_ENTRIES]; 
    int reports_saved;
    char motion;
} HomeState;

#endif