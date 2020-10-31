#include <cstdio>
#include <cstdlib>
#include <vector>

int main(int argc, char *argv[]) {
	std::vector<unsigned char> samples;
	unsigned int i = 0;
	
	unsigned int N = argc == 2? atoi(argv[1]) : 5;
	samples.reserve(N);
	for (unsigned int j = 0; j < N; ++j) samples.push_back(0);

	while(1) {
		unsigned char cur_sample;
		if(!fread(&cur_sample, 1, 1, stdin))
			exit(0);

		unsigned int fir_sum = 0;
		for(unsigned int j = 0; j < N; ++j) fir_sum += samples[j];

		samples[i] = cur_sample;
		i = (i + 1) % N;

		putchar((unsigned char)((cur_sample + fir_sum)/(N + 1)));
	}
}
