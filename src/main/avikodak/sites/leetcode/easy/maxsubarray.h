/****************************************************************************************************************************************************
 *  File Name                   : maxsubarray.h
 *  File Location               : /algos_v3/src/main/avikodak/sites/leetcode/easy/maxsubarray.h
 *  Created on                  : Jul 26, 2017 :: 9:15:16 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://leetcode.com/problems/maximum-subarray/#/description
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

#ifndef MAIN_AVIKODAK_SITES_LEETCODE_EASY_MAXSUBARRAY_H_
#define MAIN_AVIKODAK_SITES_LEETCODE_EASY_MAXSUBARRAY_H_

/****************************************************************************************************************************************************/
/*                                                           O(LOGN) Algorithm                                                                      */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                            O(N) Algorithm                                                                        */
/****************************************************************************************************************************************************/
int maxSubArray(vector<int>& userInput) {
    int maxSum = INT_MIN, currentSum = 0;
    for (unsigned int counter = 0; counter < userInput.size(); counter++) {
        currentSum = max(currentSum + userInput[counter], userInput[counter]);
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

/****************************************************************************************************************************************************/
/*                                                           O(C^N) Algorithm                                                                       */
/****************************************************************************************************************************************************/

#endif /* MAIN_AVIKODAK_SITES_LEETCODE_EASY_MAXSUBARRAY_H_ */
