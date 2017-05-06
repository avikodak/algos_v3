/****************************************************************************************************************************************************
 *  File Name                   : getpairforsum.h
 *  File Location               : /algos_v3/src/main/avikodak/sites/geeksforgeeks/arrays/page21/getpairforsum.h
 *  Created on                  : May 6, 2017 :: 11:55:04 AM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : TODO
 ****************************************************************************************************************************************************/

#include <libv2/constants/constants.h>

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

#ifndef MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_ARRAYS_PAGE21_GETPAIRFORSUM_H_
#define MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_ARRAYS_PAGE21_GETPAIRFORSUM_H_

/****************************************************************************************************************************************************/
/*                                                           O(LOGN) Algorithm                                                                      */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                            O(N) Algorithm                                                                        */
/****************************************************************************************************************************************************/
iPair *getPairForSumON(vector<int> userInput, int targetSum) {
    if (userInput.size() < 2) {
        return null;
    }
    hash_map<int, bool> presenceMap;
    hash_map<int, bool>::iterator itToPresenceMap;
    for (unsigned int counter = 0; counter < userInput.size(); counter++) {
        if ((itToPresenceMap = presenceMap.find(targetSum - userInput[counter])) != presenceMap.end()) {
            return new iPair(userInput[counter], targetSum - userInput[counter]);
        }
    }
    return null;
}
/****************************************************************************************************************************************************/
/*                                                          O(N*LOGN) Algorithm                                                                     */
/****************************************************************************************************************************************************/
iPair *getPairForSumONLOGNSort(vector<int> userInput, int targetSum) {
    if (userInput.size() < 2) {
        return null;
    }
    sort(userInput.begin(), userInput.end());
    int frontCrawler = 0, rearCrawler = userInput.size() - 1;
    int currentSum;
    while (frontCrawler < rearCrawler) {
        currentSum = userInput[frontCrawler] + userInput[rearCrawler];
        if (currentSum == targetSum) {
            return new iPair(userInput[frontCrawler], userInput[rearCrawler]);
        } else if (currentSum < targetSum) {
            frontCrawler++;
        } else {
            rearCrawler++;
        }
    }
    return null;
}
/****************************************************************************************************************************************************/
/*                                                           O(N^2) Algorithm                                                                       */
/****************************************************************************************************************************************************/
iPair *getPairForSumON2(vector<int> userInput, int targetSum) {
    if (userInput.size() < 2) {
        return null;
    }
    for (unsigned int outerCrawler = 0; outerCrawler < userInput.size(); outerCrawler++) {
        for (unsigned int innerCrawler = outerCrawler + 1; innerCrawler < userInput.size(); innerCrawler++) {
            if (userInput[outerCrawler] + userInput[innerCrawler] == targetSum) {
                return new iPair(userInput[outerCrawler], userInput[innerCrawler]);
            }
        }
    }
    return null;
}
/****************************************************************************************************************************************************/
/*                                                           O(C^N) Algorithm                                                                       */
/****************************************************************************************************************************************************/

#endif /* MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_ARRAYS_PAGE21_GETPAIRFORSUM_H_ */
