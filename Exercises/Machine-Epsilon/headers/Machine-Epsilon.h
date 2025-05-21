#ifndef HAVE_MACHINE_EPSILON_H
#define HAVE_MACHINE_EPSILON_H
double machineEpsilonDouble();
float machineEpsilonFloat();
bool approx(double a, double b, double acc=1E-9, double eps=1E-9);

#endif