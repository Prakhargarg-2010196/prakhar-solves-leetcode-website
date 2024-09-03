#include <bits/stdc++.h>
using namespace std;
// This question will help you think recursively
// As the grammar is being generated recursively here from the previous row values the recursion is obvious
// here (this is not an optimised approach but a different approach then previous one)
int kthGrammar(int n, int k)
{
    /*
    One observation also can be that if we know the parent value and the k value is even or odd then we can 
    determine the grammar at k 
    */
    // Base Condition
    if (n == 1 && k == 1)
    {
        return 0;
    }
    // Hypothesis and Induction
    if (k%2==0)
    {   // if we can relate to brute force in a way we are finding the parent position by finding the mid of 
        // the child key by dividing by 2 when it is even and dividing the key +1  by 2  when it is odd(as odd
        // in itself is not completely divisible)
        // if k is even and the parent of the node is 0 then the value is reversed else it remains the same
        if( kthGrammar(n - 1, k/2)==0)
            return 1;
        else
            return 0;
    }
    else
    {// if k is odd and the parent of the node is 0 then the value is same else it gets reversed
        if(kthGrammar(n - 1, (k+1)/2)==0) // negate the ouput if the k > mid
        return 0;
        else return 1;
    }   
}
int main()
{
    int n, k;
    cin >> n >> k;
    cout << kthGrammar(n, k);
    return 0;
}