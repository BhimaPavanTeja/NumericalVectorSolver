#include <stdio.h>
#include <math.h>

float equation(float x) {
    float result;
    result = 3*x - exp(x); // give the equation here
    return result;
}

int main() {
    float a=0, b=1, c, fa, fb, fc;
    int i=1;

     do {
        fa = equation(a);
        fb = equation(b);
        if (fa * fb < 0) { // check the sign of the function
            printf("<---------------------------------------->\n");
            printf("\tf(a) = %0.4f is negative\n", fa);
            printf("\tf(b) = %0.4f is positive\n", fb); 
            printf("<---------------------------------------->\n");
            break;
        }
        a++, b++;
        i++;
    }while(i<100);

    printf("\t\ta value is %d\n",(int)a);
    printf("\t\tb value is %d\n",(int)b);
    printf("__________________________________________");
    printf("\n i\t  a\t  b\t  c\t  f(c)\t \n");

    do {
        c = (a + b) / 2.0; // calculate the midpoint
        fc = equation(c); 
        printf("%2d\t %0.4f\t %0.4f\t %0.4f\t %0.4f\t \n", i, a, b, c, fc); 
        
        if (fabs(fc) <= 0.0001) { // check the root
            printf("__________________________________________");
            printf("\n\tApproximate root = %0.4f\n", c); 
            printf("<---------------------------------------->\n");
            break;
        }
        else if (fc < 0) {
            a = c;
        } 
        else {
            b = c;
        }
        i++;
    }while(1);
    
    return 0;
}
