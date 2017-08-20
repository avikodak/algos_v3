/****************************************************************************************************************************************************
 *  File Name                   : anagrampalindrome.h
 *  File Location               : /algos_v3/src/main/avikodak/sites/geeksforgeeks/practice/basic/anagrampalindrome.h
 *  Created on                  : Aug 20, 2017 :: 11:07:25 AM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : http://practice.geeksforgeeks.org/problems/anagram-palindrome/0
 ****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                         NAMESPACE DECLARATION AND IMPORTS                                                        */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/*                                                                 INCLUDES                                                                         */
/****************************************************************************************************************************************************/

#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <hash_map>
#include <stack>
#include <queue>
#include <limits.h>
#include <libv3/constants/constants.h>
#include <libv3/ds/dscommons.h>
#include <libv3/ds/graphds.h>
#include <libv3/ds/linkedlistsds.h>
#include <libv3/ds/treeds.h>
#include <libv3/utils/abtreeutils.h>
#include <libv3/utils/arrayutils.h>
#include <libv3/utils/avltreeutils.h>
#include <libv3/utils/binarytreeutils.h>
#include <libv3/utils/bplustreeutils.h>
#include <libv3/utils/bstutils.h>
#include <libv3/utils/btreeutils.h>
#include <libv3/utils/commonutil.h>
#include <libv3/utils/dllutils.h>
#include <libv3/utils/graphutils.h>
#include <libv3/utils/ioutils.h>
#include <libv3/utils/mathutils.h>
#include <libv3/utils/redblacktreeutils.h>
#include <libv3/utils/treeutils.h>
#include <libv3/utils/trieutils.h>
#include <libv3/utils/twofourtreeutils.h>
#include <libv3/utils/sillutils.h>

/****************************************************************************************************************************************************/
/*                                                            USER DEFINED CONSTANTS                                                                */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_BASIC_ANAGRAMPALINDROME_H_
#define MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_BASIC_ANAGRAMPALINDROME_H_

bool isAnagramPalindrome(string userInput) {
    if (userInput.size() < 2) {
        return true;
    }
    unsigned int frequency[26] = { 0 };
    for (unsigned int counter = 0; counter < userInput.size(); counter++) {
        frequency[userInput[counter] - 'a']++;
    }
    bool oddFrequencyFound = false;
    for (unsigned int counter = 0; counter < 26; counter++) {
        if (frequency[counter] & 1) {
            if (oddFrequencyFound) {
                return false;
            }
            oddFrequencyFound = true;
        }
    }
    return true;
}

void solveProblem() {
    unsigned int testCases;
    string userInput;
    scanf("%u", &testCases);
    while (testCases--) {
        cin >> userInput;
        printf("%s\n", isAnagramPalindrome(userInput) ? "Yes" : "No");
    }
}

#endif /* MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_BASIC_ANAGRAMPALINDROME_H_ */
