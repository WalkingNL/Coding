#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {

    vector<int> vec = {9,2,10,100,96,97,3,11,4,76};


    int max_first = vec[0];
    int max_second = vec[0];
    
    for (int i=0; i<vec.size(); i++) {
        if (vec[i] > max_first) {
            max_second = max_first;
            max_first = vec[i];
        } else if (vec[i] > max_second) {
            max_second = vec[i];
        }
    }

    cout << "max_first: " << max_first << endl;
    cout << "max_second: " << max_second << endl;

    sort(vec.begin(), vec.end(), greater<int>());
    cout << "max_first: " << vec[0] << endl;
    cout << "max_second: " << vec[1] << endl;

    return 0;
}