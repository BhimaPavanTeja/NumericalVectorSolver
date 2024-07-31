#include <stdio.h>
#include <math.h>

float equation(float x) {
    float result;
    result = pow(x,3) - x - 1; // give the equation here
    return result;
}

int main() {
    float a = 0, b = 1, c, fa, fb, fc;
    int i = 1; 

    do { 
        fa = equation(a);
        fb = equation(b);
        if (fa * fb < 0) { // check if the root is between a and b
            printf("<-------------------------------------------------------->\n");
            printf("\t\tf(a) = %0.4f is negative\n", fa);
            printf("\t\tf(b) = %0.4f is positive\n", fb);
            printf("<-------------------------------------------------------->\n");
            break;
        }
        a++, b++;
        i++;
    }while(i<100);

    printf("\t\t\ta value is %d\n",(int)a);
    printf("\t\t\tb value is %d\n",(int)b);
    printf("_________________________________________________________");
    printf("\n i\t  a\t  f(a)\t  b\t  f(b)\t  c\t  f(c)\t \n");

    do {
        c = (a * fb - b * fa) / (fb - fa); 

        fc = equation(c);

        printf("%2d\t %0.4f\t %0.4f %0.4f\t %0.4f\t %0.4f\t %0.4f\t \n",i ,a ,fa ,b ,fb , c, fc);

        if (fabs(fc) <= 0.0001) { // check if the root is found
            printf("________________________________________________________\n");
            printf("\t\tApproximate root = %0.4f\n", c);
            printf("<-------------------------------------------------------->\n");
            break;
        }
        else if (fc < 0) { // check if the root is between a and c
            a = c;
            fa = fc;
        }
        else { // check if the root is between b and c
            b = c;
            fb = fc;
        }
        i++;
    } while (1);

    return 0;
}