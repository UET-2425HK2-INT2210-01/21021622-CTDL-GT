//pseudo-codes
function solve(n)
    if n = 0 then
        return 1
    end if

    half ← solve(n / 2)  

    if n % 2 = 0 then
        return half × half
    else if n < 0 then
        return half × half / 2
    else
        return half × half × 2
    end if
end function

begin
    input n
    output solve(n)
end

//C++ codes
#include <iostream>
using namespace std;

long long solve(int n) {
    if (n == 0) return 1;

    long long half = solve(n / 2);  

    if (n % 2 == 0) return half * half;
    if (n < 0) return half * half / 2;
    return half * half * 2;
}

int main() {
    int n;
    cin >> n;  
    cout << solve(n) << endl;
}
