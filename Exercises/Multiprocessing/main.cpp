#include<thread>
#include<functional>
#include<string>
#include<iostream>

struct data 
{ 
    int start;
    int end; 
    double sum; 
};

void harm(data& p)
{
	p.sum = 0;
	std::cout<<"harm: start:  summing from "<<p.start<<" to "<<p.end<<std::endl;;
	for (int i=p.start; i<p.end; i++) 
    {
        p.sum += 1.0/i;
    }
	std::cout<<"harm: finish:  sum from "<<p.start<<" to "<<p.end<<"="<<p.sum<<std::endl;;
}

int main(int argc, char** argv)
{
    
	int N=(int)1e8;
    int n = 1;
	for(int i=0;i<argc;i++)
    {
		std::string arg=argv[i];
		if(arg=="-N" && i+1<argc) N=std::stoi(argv[i+1]);
		if(arg=="-n" && i+1<argc) n=std::stoi(argv[i+1]);
	}

	std::vector<std::thread> threads(n);
	std::vector<data> parameters(n);
	for(int i=0; i<n; i++)
    {
		parameters[i].start=1+(N/n)*i;
		parameters[i].end  =1+(N/n)*(i+1);
		threads[i] = std::thread(harm,std::ref(parameters[i]));
	}

	for(std::thread& thread : threads)
    {
        thread.join();
    }
	double sum = 0;

	for(auto p : parameters)
    {
        sum+=p.sum;
    }
	std::cout <<"main: harmonic sum from "<<1<<" to " << N << "=" << sum << std::endl;

return 0;
}
