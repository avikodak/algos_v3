/****************************************************************************************************************************************************
 *  File Name                   : kadanealgo.h
 *  File Location               : /algos_v3/src/main/avikodak/sites/geeksforgeeks/dp/page15/kadanealgo.h
 *  Created on                  : May 6, 2017 :: 12:11:33 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : TODO
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

#ifndef MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_DP_PAGE15_KADANEALGO_H_
#define MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_DP_PAGE15_KADANEALGO_H_

/****************************************************************************************************************************************************/
/*                                                           O(LOGN) Algorithm                                                                      */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                            O(N) Algorithm                                                                        */
/****************************************************************************************************************************************************/
int getMaxSumSubarray(vector<int> userInput) {
    int currentSum, maxSum = INT_MIN;
    for (unsigned int counter = 0; counter < userInput.size(); counter++) {
        currentSum = max(userInput[counter], currentSum + userInput[counter]);
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
}

/****************************************************************************************************************************************************/
/*                                                          O(N*LOGN) Algorithm                                                                     */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                           O(N^2) Algorithm                                                                       */
/****************************************************************************************************************************************************/
int getMaxSumSubarrayON2(vector<int> userInput) {
    int maxSum = INT_MIN;
    for (unsigned int outerCrawler = 0; outerCrawler < userInput.size(); outerCrawler++) {
        int currentSum = 0;
        for (unsigned int innerCrawler = outerCrawler; innerCrawler < userInput.size(); innerCrawler++) {
            currentSum += userInput[innerCrawler];
            maxSum = max(maxSum, currentSum);
        }
    }
    return maxSum;
}
/****************************************************************************************************************************************************/
/*                                                           O(C^N) Algorithm                                                                       */
/****************************************************************************************************************************************************/

#endif /* MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_DP_PAGE15_KADANEALGO_H_ */
