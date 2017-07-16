/****************************************************************************************************************************************************
 *  File Name                   : quicksort.h
 *  File Location               : /algos_v3/src/main/avikodak/sites/geeksforgeeks/sorting/quicksort.h
 *  Created on                  : May 14, 2017 :: 6:58:23 PM
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

#ifndef MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_SORTING_QUICKSORT_H_
#define MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_SORTING_QUICKSORT_H_

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
int getDividingIndex(vector<int> &userInput, int startIndex, int endIndex) {
    if (startIndex >= endIndex) {
        return startIndex > endIndex ? INT_MIN : startIndex;
    }
    int key = userInput[endIndex];
    int fillIndex = startIndex;
    for (unsigned int counter = startIndex; counter < endIndex; counter++) {
        if (userInput[counter] <= key) {
            swap(userInput[counter], userInput[fillIndex]);
            fillIndex++;
        }
    }
    swap(userInput[fillIndex], userInput[endIndex]);
    return fillIndex;
}

void quickSort(vector<int> &userInput, int startIndex, int endIndex) {
    if (userInput.size() < 2) {
        return;
    }
    int dividingIndex = getDividingIndex(userInput, startIndex, endIndex);
    quickSort(userInput, startIndex, dividingIndex - 1);
    quickSort(userInput, dividingIndex + 1, endIndex);
}

/****************************************************************************************************************************************************/
/*                                                           O(C^N) Algorithm                                                                       */
/****************************************************************************************************************************************************/

#endif /* MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_SORTING_QUICKSORT_H_ */
