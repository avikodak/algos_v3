/****************************************************************************************************************************************************
 *  File Name                   : atoi.h
 *  File Location               : /algos_v3/src/main/avikodak/sites/leetcode/easy/atoi.h
 *  Created on                  : Jul 19, 2017 :: 9:29:39 AM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : https://leetcode.com/problems/string-to-integer-atoi/#/description
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

#ifndef MAIN_AVIKODAK_SITES_LEETCODE_EASY_ATOI_H_
#define MAIN_AVIKODAK_SITES_LEETCODE_EASY_ATOI_H_

/****************************************************************************************************************************************************/
/*                                                           O(LOGN) Algorithm                                                                      */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                            O(N) Algorithm                                                                        */
/****************************************************************************************************************************************************/
int atoi(string userInput) {
    int result = 0;
    bool isInputNegative = false;
    if (userInput.size() == 0) {
        return result;
    }
    int crawler = 0;
    while (userInput[crawler] == ' ') {
        crawler++;
    }
    if (userInput[crawler] == '-' || userInput[crawler] == '+') {
        crawler++;
        isInputNegative = (userInput[crawler] == '-');
    }
    for (; crawler < userInput.size(); crawler++) {
        if (userInput[crawler] >= '0' && userInput[crawler] <= '9') {
            int digit = userInput[crawler] - '0';
            if (result > (INT_MAX / 10) || result * 10 + digit < result * 10) {
                return INT_MAX;
            }
            result = (result << 3) + (result << 1) + (digit);
        } else {
            break;
        }
    }
    return isInputNegative ? -1 * result : result;
}

/****************************************************************************************************************************************************/
/*                                                          O(N*LOGN) Algorithm                                                                     */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                           O(N^2) Algorithm                                                                       */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                           O(C^N) Algorithm                                                                       */
/****************************************************************************************************************************************************/

#endif /* MAIN_AVIKODAK_SITES_LEETCODE_EASY_ATOI_H_ */
