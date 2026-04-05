#include <iostream>
#include <string>
using namespace std;


int mirrorFrequency(string s) {
    int freqc[26] = {0};
    int freqd[10] = {0};
    int ans = 0;

    //Frequency count
    for (int i=0; i<s.length(); i++){
        //Alphabet frequency
        if (isalpha(s[i])){
            freqc[s[i] - 'a']++;
            freqc['z' - s[i]]--;
        }
        //Digit frequency
        if(isdigit(s[i])){
            freqd[s[i]-'0']++;
            freqd['9'-s[i]]--;
        }
    }

    //Count distinct mirror pairs of alphabet
    for (int val:freqc){
        if (val>0){
            ans += val;
        }
    }
    //Count distinct mirror pairs digit
    for (int val:freqd){
        if (val>0){
            ans += val;
        }
    }
    return ans;
}

int main(){
    //example
    string s = "ab1z9";
    cout << mirrorFrequency(s) << endl; //Output: 3
    return 0;
}