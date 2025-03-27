import scipy.integrate
import numpy as np
import matplotlib.pyplot as plt

def HarmonicOscillator(t, y):
    dydt = []
    dydt.append(y[1])
    dydt.append(-y[0])
    return dydt


y0 = [1.0, 0.0]
t = np.linspace(0, 10, 100)

solution = scipy.integrate.solve_ivp(HarmonicOscillator, (0, 10), y0, t_eval=t)

# Plotting the solution
plt.plot(solution.t, solution.y[0], label='Displacement')
plt.plot(solution.t, solution.y[1], label='Velocity')
plt.xlabel('Time [arb. units]')
plt.ylabel('y [arb. units]')
plt.title('Harmonic Oscillator')
plt.legend()
plt.grid(True)
plt.savefig('harmonic_oscillator_plot_python.svg') 

