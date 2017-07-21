/****************************************************************************************************************************************************
 *  File Name                   : searchandinsert.h
 *  File Location               : /algos_v3/src/main/avikodak/sites/leetcode/easy/searchandinsert.h
 *  Created on                  : Jul 21, 2017 :: 7:06:45 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : https://leetcode.com/problems/search-insert-position/#/description
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

#ifndef MAIN_AVIKODAK_SITES_LEETCODE_EASY_SEARCHANDINSERT_H_
#define MAIN_AVIKODAK_SITES_LEETCODE_EASY_SEARCHANDINSERT_H_

/****************************************************************************************************************************************************/
/*                                                           O(LOGN) Algorithm                                                                      */
/****************************************************************************************************************************************************/
int getFloorIndex(vector<int> userInput, int key, int startIndex, int endIndex) {
    if (startIndex > endIndex) {
        return 0;
    }
    if (userInput[startIndex] > key) {
        return startIndex;
    }
    if (userInput[endIndex] < key) {
        return endIndex + 1;
    }
    int middleIndex = (startIndex + endIndex) / 2;
    if (userInput[middleIndex] == key) {
        return middleIndex;
    } else if (userInput[middleIndex] > key) {
        if (middleIndex - 1 >= startIndex && userInput[middleIndex - 1] < key) {
            return middleIndex;
        } else {
            return getFloorIndex(userInput, key, startIndex, middleIndex - 1);
        }
    } else {
        if (middleIndex + 1 <= endIndex && userInput[middleIndex + 1] > key) {
            return middleIndex + 1;
        } else {
            return getFloorIndex(userInput, key, middleIndex + 1, endIndex);
        }
    }
}

int searchInsert(vector<int> &userInput, int target) {
    return getFloorIndex(userInput, target, 0, userInput.size() - 1);
}

/****************************************************************************************************************************************************/
/*                                                            O(N) Algorithm                                                                        */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                          O(N*LOGN) Algorithm                                                                     */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                           O(N^2) Algorithm                                                                       */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                           O(C^N) Algorithm                                                                       */
/****************************************************************************************************************************************************/

#endif /* MAIN_AVIKODAK_SITES_LEETCODE_EASY_SEARCHANDINSERT_H_ */
