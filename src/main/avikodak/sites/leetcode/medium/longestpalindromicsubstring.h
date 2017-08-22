/****************************************************************************************************************************************************
 *  File Name                   : longestpalindromicsubstring.h
 *  File Location               : /algos_v3/src/main/avikodak/sites/leetcode/medium/longestpalindromicsubstring.h
 *  Created on                  : Aug 1, 2017 :: 10:22:20 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://leetcode.com/problems/longest-palindromic-substring/description/
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

#ifndef MAIN_AVIKODAK_SITES_LEETCODE_MEDIUM_LONGESTPALINDROMICSUBSTRING_H_
#define MAIN_AVIKODAK_SITES_LEETCODE_MEDIUM_LONGESTPALINDROMICSUBSTRING_H_

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
string longestPalindrome(string userInput) {
    if (userInput.size() < 2) {
        return userInput;
    }
    int auxSpace[userInput.size()][userInput.size()];
    int maxLength = 1, maxStartIndex = 0, maxEndIndex = 0;
    for (unsigned int length = 1; length <= userInput.size(); length++) {
        for (unsigned int startIndex = 0; startIndex < userInput.size() - length + 1; startIndex++) {
            unsigned int endIndex = startIndex + length - 1;
            bool isPalindrome = false;
            if (length == 1) {
                auxSpace[startIndex][endIndex] = true;
                isPalindrome = true;
            } else if (length == 2) {
                if (userInput[startIndex] == userInput[endIndex]) {
                    auxSpace[startIndex][endIndex] = true;
                    isPalindrome = true;
                } else {
                    auxSpace[startIndex][endIndex] = false;
                }
            } else if (userInput[startIndex] == userInput[endIndex] && auxSpace[startIndex + 1][endIndex - 1]) {
                auxSpace[startIndex][endIndex] = true;
                isPalindrome = true;
            } else {
                auxSpace[startIndex][endIndex] = false;
            }
            if (isPalindrome && maxLength < length) {
                maxLength = length;
                maxStartIndex = startIndex;
                maxEndIndex = endIndex;
            }
        }
    }
    return userInput.substr(maxStartIndex, maxLength);
}

/****************************************************************************************************************************************************/
/*                                                           O(C^N) Algorithm                                                                       */
/****************************************************************************************************************************************************/

#endif /* MAIN_AVIKODAK_SITES_LEETCODE_MEDIUM_LONGESTPALINDROMICSUBSTRING_H_ */
