#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    double numbers[5];
    double minNum, maxNum;
    
    cin >> numbers[0];
    minNum = maxNum = numbers[0];
    
    for (int i = 1; i < 5; i++) {
        cin >> numbers[i];
        if (numbers[i] < minNum) minNum = numbers[i];
        if (numbers[i] > maxNum) maxNum = numbers[i];
    }
    
    cout << minNum + maxNum << endl;
    
    return 0;
}
