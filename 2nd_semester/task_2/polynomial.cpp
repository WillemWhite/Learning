#include <iostream>
#include <cassert>

float polComputation(int, float);

void inpConditions(int deg, float arg)
{
    assert(arg > 0 && "Wrong input: out of range argument... (argument > 0)");
    assert(deg >= 0 && "Wrong input: degree must be >= 0");
}
void testPolComputation()
{
    char mes[16] = "Wrong tests...";

    assert(polComputation(2, 1) == 0 && mes);
    assert(polComputation(3, 5) == static_cast<float>(8.0 / 3.0) && mes);
    assert(polComputation(3, 2) == static_cast<float>(-0.5 + (2.0 / 3.0)) && mes);
}

float polComputation(int deg, float arg)
{
    switch (deg)
    {
    case 0:
        return 0;
        break;

    case 1:
        return (-arg + 1);
        break;

    default:
        return (((1.0 / deg) * ((2 * deg - 1 - arg) * polComputation(deg - 1, arg) -
                                (deg - 1) * polComputation(deg - 2, arg))));
    }
}
