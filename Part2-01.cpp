#include <iostream>
using namespace std;

int main () {
    int T, A, B, K, counter;
    
    do {
        cin >> T;
    } while (T < 1 || T > 100);
    
    for (int i=0; i < T; i++)
    {
        counter = 0;
        
        do {
            cin >> A;
        } while (A < 1 || A > 10000);
        do {
            cin >> B;
        } while (B < A || B > 10000);
        do {
            cin >> K;
        } while (K < 1 || K >= 10000);
        
        for (int j=A; j<=B; j++)
            if (j  % K == 0)
                counter++;
                
        cout << "Case " << (i+1) << ": " << counter << endl;
    }
}