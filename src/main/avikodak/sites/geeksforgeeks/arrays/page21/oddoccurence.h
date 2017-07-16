/****************************************************************************************************************************************************
 *  File Name                   : oddoccurence.h
 *  File Location               : /algos_v3/src/main/avikodak/sites/geeksforgeeks/arrays/page21/oddoccurence.h
 *  Created on                  : May 9, 2017 :: 10:52:43 PM
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

#ifndef MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_ARRAYS_PAGE21_ODDOCCURENCE_H_
#define MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_ARRAYS_PAGE21_ODDOCCURENCE_H_

/****************************************************************************************************************************************************/
/*                                                           O(LOGN) Algorithm                                                                      */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                            O(N) Algorithm                                                                        */
/****************************************************************************************************************************************************/
int getOddOccuringValue(vector<int> userInput) {
    int xorResult = 0;
    for (unsigned int counter = 0; counter < userInput.size(); counter++) {
        xorResult ^= userInput[counter];
    }
    return xorResult;
}

/****************************************************************************************************************************************************/
/*                                                          O(N*LOGN) Algorithm                                                                     */
/****************************************************************************************************************************************************/
int getOddOccuringValueSort(vector<int> userInput) {
    sort(userInput.begin(), userInput.end());
    int outerCrawler = 0;
    int innerCrawler, frequency;
    while (outerCrawler < userInput.size()) {
        innerCrawler = outerCrawler;
        frequency = 0;
        while (innerCrawler < userInput.size() && userInput[innerCrawler] == userInput[outerCrawler]) {
            frequency++;
            innerCrawler++;
        }
        if (frequency & 1) {
            return userInput[outerCrawler];
        }
        outerCrawler = innerCrawler;
    }
    return INT_MIN;
}

/****************************************************************************************************************************************************/
/*                                                           O(N^2) Algorithm                                                                       */
/****************************************************************************************************************************************************/
int getOddOccuringON2(vector<int> userInput) {
    int frequency = 0;
    for (unsigned int outerCrawler = 0; outerCrawler < userInput.size(); outerCrawler++) {
        frequency = 0;
        for (unsigned int innerCrawler = outerCrawler; innerCrawler < userInput.size(); innerCrawler++) {
            if (userInput[outerCrawler] == userInput[innerCrawler]) {
                frequency++;
            }
        }
        if (frequency & 1) {
            return userInput[outerCrawler];
        }
    }
    return INT_MIN;
}

#endif /* MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_ARRAYS_PAGE21_ODDOCCURENCE_H_ */
