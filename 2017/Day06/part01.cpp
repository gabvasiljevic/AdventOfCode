#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

int main(){

    vector<int> input;
    int x;

    while(cin >> x){
        input.push_back(x);
    }

    bool repeated = false;
    map<vector<int>, int> configs;

    configs[input] = 1;

    int n = input.size();
    int cycles = 0;

    while(!repeated){
        vector<int>::iterator it;
        it = max_element(input.begin(), input.end());

        int index = std::distance(input.begin(), it);

        int blocks = input[index];
        input[index] = 0;

        while(blocks--){
            input[(++index)%n]++;
        }

        if(configs[input]){
            repeated = true;
        }
        else{
            configs[input] = 1;
        }

        cycles++;
    }

    debug(cycles);

    return 0;
}
