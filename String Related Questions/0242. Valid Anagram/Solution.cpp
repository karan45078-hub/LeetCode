#include <iostream>
#include <string>
using namespace std;

bool isAnagram(string s, string t) {
        if (s.length()!=t.length()){
            return false;
        }
        int freq[26] = {0};
        for (int i=0; i<s.length(); i++){
            freq[s[i] - 'a']++;
        }
        for (int j=0; j<t.length(); j++){
            if (freq[t[j]-'a']==0){
                return false;
            }
            freq[t[j] - 'a']--;
        }
        return true;
    }

int main(){
    //Example
    string s1 = "anagram", t1 = "nagaram";
    string s2 = "rat", t2 = "car";

    cout << isAnagram(s1,t1) << endl; //1 (true)
    cout << isAnagram(s2,t2) << endl; //0 (false)
    return 0;
}