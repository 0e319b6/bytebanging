#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  float f; /* note frequency */
  char c; /* "cdefgab" for notes or "pr" for pause */
  int d, o; /* d = duration, o = octave */
  while (scanf("%d%c%d ", &d, &c, &o) > 0) {
    /* convert note to lowercase */
    c &= 31;
    /* c>>4 is 0 for CDEFGAB and 1 for "PR" */
    /* so, for pauses f would be zero, for notes - 55 */
    f = !(c >> 4) * 55;
    /* a trick we used in Nokia Composer post to conver note letter to note index */
    c = (c * 8 / 5 + 8) % 12 + o * 12 - 22;
    /* Note `x` frequency is 2^(x/12), or (2^(1/12))^x */
    while (c--) {
      f *= 1.0595; /* 1.0595 is 2^(1/12) */
    }
    /* Play sawtooth wave for the given duration with given pitch */
    //for (d = 16e3 / d; d--; putchar(d * f * .032));

    	//sine wave
	double osc = 0;
	double inc = 256.0 * f / 8000.0;
//	for (d = 16e3 / d; d--; osc = osc + inc) {
//	  putchar(127 * sin(osc/255.0*2*3.14) + 128);
//	}

	unsigned char a[(int)round(inc)];
	for (int i = 0; i < sizeof(a); i++) a[i] = rand();

	int t = 0;
	for (d = 16e3 / d, t=0; d--; t++) {
	  int i = t % sizeof(a);
	  int j = (t+1) % sizeof(a);
	  putchar(a[i] = (a[i] + a[j])/2);
	}
  }
}
