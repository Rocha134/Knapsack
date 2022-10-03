//Francisco Rocha
//Iker Guerrero
//Juan Carlos Llanos

/*Complexity Analysis:
Time Complexity: O(2n).
As there are redundant subproblems.
Auxiliary Space :O(1) + O(N).
As no extra data structure has been
 used for storing values but O(N)
 auxiliary stack space(ASS) has been
 used for recursion stack.*/

#include <iostream>
using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }


int backpackOptimization(int W, int weightsArray[], int valuesArray[], int elementsPossible)
{
    if (elementsPossible == 0 || W == 0)
        return 0;
    if (weightsArray[elementsPossible - 1] > W)
        return backpackOptimization(W, weightsArray, valuesArray, elementsPossible - 1);
    else
        return max(
                valuesArray[elementsPossible - 1]
                + backpackOptimization(W - weightsArray[elementsPossible - 1],
                                       weightsArray, valuesArray, elementsPossible - 1),
                backpackOptimization(W, weightsArray, valuesArray, elementsPossible - 1));
}

int main()
{
    int elementsPossible;
    cin>>elementsPossible;

    int valuesArray[elementsPossible];
    int weightsArray[elementsPossible];
    int aux;

    //Create array of values
    for (int i = 0; i < elementsPossible; ++i) {
        cin>>aux;
        valuesArray[i] = aux;
    }

    //Create array of weights
    for (int i = 0; i < elementsPossible; ++i) {
        cin>>aux;
        weightsArray[i] = aux;
    }

    int W;
    cin>>W;

    cout << backpackOptimization(W, weightsArray, valuesArray, elementsPossible);
    return 0;
}