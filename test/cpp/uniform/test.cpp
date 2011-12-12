#include <FImage.h>
#include <sys/time.h>

using namespace FImage;

int main(int argc, char **argv) {

    Var x("x");
    Func f("f");

    Uniform<float> u;

    f(x) = u;

    u = 17.0f;
    Image<float> out_17 = f.realize(1024);

    u = 123.0f;
    Image<float> out_123 = f.realize(1024);

    for (int i = 0; i < 1024; i++) {
        if (out_17(i) != 17.0f || out_123(i) != 123.0f) {
            printf("Failed!\n");
            for (int i = 0; i < 1024; i++) {
                printf("%f %f\n", out_17(i), out_123(i));
            }
            return -1;
        }
    }

    printf("Success!\n");
    return 0;
}