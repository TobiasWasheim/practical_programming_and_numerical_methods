Self-evaluation: 
    10/10 points for completing, testing and applying (to schrodingers equation) the algorithm
    and comparing the results to the EVD routine from the homeworks

Note:
    - You can find the results in the file out.txt and plots in the folder 'plots'.
    - If you run "make clean" and then "make" it might take a minute or two to run
      the code as it takes some time to do part C. 

Short description:
    This exam project is about implementing the inverse iteration algorithm which
    returns an eigenvalue that is closest to the shit-value s and the corresponding
    eigenvector. 


    I have divided the exam exercise in three parts (A, B, C). Part A is implementing the
    algorithm and testing it and comparing to the EVD routine. Part B is applying the 
    algorithm to find energy eigenvalue for the schrodinger equation s-wave (ground state, excited states). 
    Part C is about timing the algorithm and the EVD routine. The plot from part C can be 
    found at 'plots/timing.svg/'.

    Part A:

    I have implemented that algorithm which can found at'src/InverseIteration.cpp/'.

    The second (and important step) is to test the algorithm. I have tested the algorithm
    and compared the results to the EVD routine from the homeworks. The test case I have
    used is generating a random 5x5 real symmetric matrix. From that I found that I get
    the same eigenvalues and eigenvectors (however not normalized!) as the ones from the
    EVD routine.


    Part B:

    Additionally, I also applied the inverse iteration algorithm to find the ground state energy
    of the (s-wave) schrodinger equation on grid where the Hamiltonian was built like in the 
    EVD homework part B. This was not something that was required for the exam problem. 
    
    I found that E = -0.49... which was expected (the analytical value is -0.5). 


    Part C:
    
    I timed the inverse iteration algorithm and the EVD routine. Both methods scale as O(N^3) and
    it can be seen plotted at plots/timing.svg/. 