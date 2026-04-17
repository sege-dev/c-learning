#include <stdio.h>
int main()
{
    int mode, hour, source, air, security, lights, alarm;
    security = 1;
    air = 0;
    alarm = 0;
    lights = 0;
    char motion;
    float temp;
    printf("--- Omni-Guard System Interface---\n");
    printf("1: Disabled\n2: Home\n3: Away\n4: Panic\n");
    scanf("%d", &mode);
    switch (mode)
    {
    }
    switch (mode)
    {
    case 4:
        alarm = 2;
        air = 0;
        lights = 2;
        printf("All lights are opened and alarm level is raised to the highest level.");
        break;
    case 1:
    case 2:
    case 3:
        break;
    default:
        printf("Error!!! Please enter a valid mode.\n");
        return 1;
    }
    printf("Enter Indoor temperature: ");
    scanf("%f", &temp);
    if (temp < -10)
    {
        printf("Error!!!\n");
        return 1;
    }
    printf("Motion Detected?(Y/N)");
    scanf(" %c", &motion);
    printf("Enter Current Hour(0-23): ");
    scanf("%d", &hour);
    if (hour >= 24 || hour < 0)
    {
        printf("Error!!! Please enter valid hour.\n");
        return 1;
    }
    printf("Energy Source\n1: Grid\n2: Battery\n3: Solar\n");
    scanf("%d", &source);
    switch (mode)
    {
    case 1:
        air = 2;
        security = 0;
        printf("The system is free. Only the air conditioning is working.");
        break;
    case 2:
        if ((hour <= 6 || hour >= 22) || (motion == 'Y' || motion == 'y'))
        {
            lights = 1;
            printf("Light up the hallway");
        }
        else
        {
        }
        break;
    case 3:
        if (motion == 'Y' || motion == 'y')
        {
            alarm = 1;
            printf("trigger alarm");
        }
        else
        {
        }
        air = 1;
        break;
    }
    switch (source)
    {
    case 1:
    case 3:
        if (temp < 20 || temp > 25)
        {
            air = 2;
        }
        else
        {
        }
        printf("Source: direct connect\n");
        break;
    case 2:
        if (temp < 15 || temp > 30)
        {
            air = 2;
        }
        printf("Source: Battery.\n");
        break;
    }
    switch (alarm)
    {
    case 1:
        printf("Alarm Triggered\n");
        break;
    case 2:
        printf("Alarm level is raised to the highest level.\n");
        break;
    default:
        printf("Alarm: Deactive \n");
    }
    switch (security)
    {
    case 1:
        printf("Security: Active\n");
        break;
    case 0:
        printf("Security: Deactive\n");
        break;
    default:
        printf("Error!!!");
        return 1;
    }
    switch (air)
    {
    case 1:
        printf("Air Conditioning: Saving mode\n");
        break;
    case 2:
        printf("Air Conditioning: Active\n");
        break;
    default:
        printf("Air Conditioning: Deactive\n");
        break;
    }
    switch (lights)
    {
    case 1:
        printf("Hall Lights are open.\n");
        break;
    case 2:
        printf("All light are open.\n");
        break;
    default:
        printf("Lights in manual mode");
    }
    return 0;
}