// Implement int sqrt(int x).
// Compute and return the square root of x, where x is guaranteed to be a non-negative integer.
// Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

class Solution {
public:
    // based on newton's method
    int mySqrt(int x) {
        if (x < 2) return x; // zero and one cases
        return sqrIter(x/2,x);
    }
    
    // guess is long to support MAX_INT as X
    int sqrIter(unsigned long long guess, int x) {
        if (isGoodEnough(guess, x)) return guess;
        return sqrIter(improve(guess, x), x);
    }
    
    bool isGoodEnough(unsigned long long guess, int x) {
        return (((guess*guess) <= x) && ((guess+1)*(guess+1) > x));
    }
    
    int improve(unsigned long long guess, int x) {
        return (guess + (x/guess))/2;
    }
};
