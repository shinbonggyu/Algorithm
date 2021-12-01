#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{

    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int numberA, numberM;
    cin >> numberA;
    vector<int> vocaA;


    for (int i = 0; i < numberA; i++)
    {
        int A;
        cin >> A;
        vocaA.push_back(A);
    }
    sort(vocaA.begin(), vocaA.end());

    cin >> numberM;
    for (int i = 0; i < numberM; i++)
    {
        int M;
        cin >> M;
        if (binary_search(vocaA.begin(), vocaA.end(), M))
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }
    return 0;

}
