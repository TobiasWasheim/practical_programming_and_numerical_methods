import math

def adapt(f, a, b, acc=0.01, eps=0.01, f2=math.nan, f3=math.nan):
    f1 = f(a+(b-a)/6)
    f4 = f(a+(b-a)*5/6)

    if math.isnan(f2):
        f2 = f(a+(b-a)*2/6)
        f3 = f(a+(b-a)*4/6)
    Q = (2 * f1 + f2 + f3 + 2 * f4)/6 * (b-a)
    q = ( f1+f4+f2+f3 )/4*(b-a) 
    tolerance = acc + eps * abs(Q)
    error = abs(Q-q)

    if (error < tolerance):
        return Q
    else:
        Q1 = adapt(f,a,(a+b)/2,acc/math.sqrt(2),eps,f1,f2)
        Q2 = adapt(f,(a+b)/2,b,acc/math.sqrt(2),eps,f3,f4)
        return Q1+Q2
