#include <stdio.h>
#include <string>
using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int freq1[26] = {0};
        int freq2[26] = {0};
        int len1 = word1.length();
        int len2 = word2.length();

        if (len1==len2){
            //Count frequency of every character
            for (int i=0; i<len1; i++){
                freq1[word1[i] - 'a'] = freq1[word1[i] - 'a'] + 1;
                freq2[word2[i] - 'a'] = freq2[word2[i] - 'a'] + 1;
            }

            //Checking every unique character of word1 are present in word2
            for (int k=0; k<26; k++){
                if (freq1[k]==0 && freq2[k]!=0){
                    return false;
                }
                if (freq2[k]==0 && freq1[k]!=0){
                    return false;
                }
            }

            sort(freq1,freq1+26);
            sort(freq2,freq2+26);
            //Check that if transformation of character possible for getting the answer using "LeetCode -> Operation:2"
            for (int j=0; j<26; j++){
                if (freq1[j]!=freq2[j]){
                    return false;
                }
            }
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){
    return 0;
}