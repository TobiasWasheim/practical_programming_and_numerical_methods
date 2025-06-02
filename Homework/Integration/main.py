import scipy.integrate as sc
import numpy as np
def f(x):
    return 1/np.sqrt(x)

def g(x):
    return np.log(x)/np.sqrt(x)


result,error,info = sc.quad(f,0,1, full_output=1)
solveg = sc.quad(f,0,1, full_output=1)


print(info["neval"])