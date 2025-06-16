import scipy.integrate as sc
import numpy as np
def f(x):
    return np.exp(-x*x)

def g(x):
    return np.log(x)/np.sqrt(x)


result,error,info = sc.quad(g,0,1, full_output=1, epsabs = 0.001, epsrel = 0.1)
gResult, gError, gInfo = sc.quad(f,-np.inf,np.inf, full_output=1, epsabs = 0.001, epsrel = 0.1)


print("Number of iterations using SciPy's integrate for non-infinte limits:",info["neval"])
print("Number of iterations using SciPy's integrate for gaussian function :",gInfo["neval"])