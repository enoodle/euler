#include "../gcd.h"
#include "../math_objects.h"
#include <iostream>
using namespace std;

int main(){
    egcd_res<int> res = egcd(10,5);
    cout << res.r.x  << endl;
    cout << egcd(46,240).r.x  << endl;

    cout << Fraction<int>(240, 46) << endl;

    cout << (-10) % 3 << endl;

    cout << egcd(3,20).s.x  << endl;
    cout << egcd(3,20).t.x  << endl;
    cout << chinese_reminder({2,3,1}, {3,4,5}) << endl;

    return 0;
}
