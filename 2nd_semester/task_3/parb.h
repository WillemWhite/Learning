#ifndef PARB_H
#define PARB_H

struct Parabola
{
    double a;
    double b;
    double c;
};

struct ArrParabolas
{
    Parabola arrParabolas[100];
};

struct MinAndParabola
{
    int countMin = 0;

    Parabola parabolaMax;
};

int compValueOfParabolaInMin(Parabola);

ArrParabolas inputParabolas(int);

MinAndParabola computMinimum(Parabola array[100], int);

void testComputMinimum();

#endif //PARB_H
