/****************************************************************************************************************************************************
 *  File Name                   : palindromicsubstrings.h
 *  File Location               : /algos_v3/src/main/avikodak/sites/leetcode/medium/palindromicsubstrings.h
 *  Created on                  : Jul 29, 2017 :: 11:49:40 AM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : https://leetcode.com/problems/palindromic-substrings/description/
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
#include <stdexcept>
#include <limits.h>
#include <stdint.h>
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

#ifndef MAIN_AVIKODAK_SITES_LEETCODE_MEDIUM_PALINDROMICSUBSTRINGS_H_
#define MAIN_AVIKODAK_SITES_LEETCODE_MEDIUM_PALINDROMICSUBSTRINGS_H_

/****************************************************************************************************************************************************/
/*                                                           O(LOGN) Algorithm                                                                      */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                            O(N) Algorithm                                                                        */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                          O(N*LOGN) Algorithm                                                                     */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                           O(N^2) Algorithm                                                                       */
/****************************************************************************************************************************************************/
int countSubstrings(string userInput) {
    if (userInput.size() < 2) {
        return userInput.size();
    }
    bool auxSpace[userInput.size()][userInput.size()];
    memset(auxSpace, false, sizeof(int) * userInput.size() * userInput.size());
    int palindromeCount = 0;
    for (int length = 1; length < userInput.size() + 1; length++) {
        for (int startIndex = 0; startIndex < userInput.size() - length; startIndex++) {
            int endIndex = startIndex + length - 1;
            if (length == 1) {
                auxSpace[startIndex][endIndex] = true;
                palindromeCount++;
            } else if (length == 2) {
                if (userInput[startIndex] == userInput[endIndex]) {
                    auxSpace[startIndex][endIndex] = true;
                    palindromeCount++;
                }
            } else {
                if (userInput[startIndex] == userInput[endIndex] && auxSpace[startIndex + 1][endIndex - 1]) {
                    auxSpace[startIndex][endIndex] = true;
                    palindromeCount++;
                }
            }
        }
    }
    return palindromeCount;
}

/****************************************************************************************************************************************************/
/*                                                           O(C^N) Algorithm                                                                       */
/****************************************************************************************************************************************************/

#endif /* MAIN_AVIKODAK_SITES_LEETCODE_MEDIUM_PALINDROMICSUBSTRINGS_H_ */
