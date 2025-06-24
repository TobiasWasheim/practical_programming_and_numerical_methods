Self-evaluation: 
    10 points for completing, testing and applying (to schrodingers equation) the algorithm
    and comparing the results to the EVD routine from the homeworks


Short description:
    This exam project is about implementing the inverse iteration algorithm which
    returns an eigenvalue that is closest to the shit-value s and the corresponding
    eigenvector. 

    I have implemented that algorithm which can found at'src/InverseIteration.cpp/'.

    The second (and important step) is to test the algorithm. I have tested the algorithm
    and compared the results to the EVD routine from the homeworks. The test case I have
    used is generating a random 5x5 real symmetric matrix. From that I found that I get
    the same eigenvalues and eigenvectors (however not normalized!) as the ones from the
    EVD routine. 

    Additionally, I also applied the inverse iteration algorithm to find the ground state energy
    of the (s-wave) schrodinger equation on grid where the Hamiltonian was built like in the 
    EVD homework part B. This was not something that was required for the exam problem. 
    
    I found that E = -0.49... which was expected (the analytical value is -0.5). 

