#include <stdio.h>

#define GRAMS_IN_ONE_OUNCE  28.3495231
#define OUNCES_IN_ONE_POUND 16

float ounces, grams, pounds;
float ouncesToGrams(float ounces);
float gramsToOunces(float grams);
float poundsToGrams(float pounds);

// 1 ounce = 28.3495231 grams

float ounces = 2;
float pounds = .3;

int main(void) {
    printf("%.2f ounces is %f grams\n", ounces, ouncesToGrams(ounces));
    printf("%.2f pounds is %f grams\n", pounds, poundsToGrams(pounds));
}

float ouncesToGrams(float o) {
    return o * GRAMS_IN_ONE_OUNCE;
}

float gramsToOunces(float g) {
    return g / GRAMS_IN_ONE_OUNCE;
}

float poundsToGrams(float p) {
    return p * OUNCES_IN_ONE_POUND * GRAMS_IN_ONE_OUNCE;
}
