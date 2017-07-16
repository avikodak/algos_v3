/****************************************************************************************************************************************************
 *  File Name                   : mergesort.h
 *  File Location               : /algos_v3/src/main/avikodak/sites/geeksforgeeks/sorting/mergesort.h
 *  Created on                  : May 14, 2017 :: 10:30:45 PM
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

#ifndef MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_SORTING_MERGESORT_H_
#define MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_SORTING_MERGESORT_H_

/****************************************************************************************************************************************************/
/*                                                           O(LOGN) Algorithm                                                                      */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                            O(N) Algorithm                                                                        */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                          O(N*LOGN) Algorithm                                                                     */
/****************************************************************************************************************************************************/
void mergeArray(vector<int> &userInput, int startIndex, int middleIndex, int endIndex) {
    int fillIndex = startIndex;
    int firstCrawler = startIndex;
    int secondCrawler = middleIndex;
    while (firstCrawler < middleIndex || secondCrawler <= endIndex) {
        if (firstCrawler >= middleIndex) {
            userInput[fillIndex++] = userInput[secondCrawler++];
        } else if (secondCrawler > endIndex) {
            userInput[fillIndex++] = userInput[firstCrawler++];
        } else {
            if (userInput[firstCrawler] <= userInput[secondCrawler]) {
                userInput[fillIndex++] = userInput[firstCrawler++];
            } else {
                userInput[fillIndex++] = userInput[secondCrawler++];
            }
        }
    }
}

void mergeSort(vector<int> &userInput, int startIndex, int endIndex) {
    if (startIndex >= endIndex) {
        return;
    }
    int middleIndex = (startIndex + endIndex) / 2;
    mergeSort(userInput, startIndex, middleIndex - 1);
    mergeSort(userInput, middleIndex, endIndex);
    mergeArray(userInput, startIndex, middleIndex, endIndex);
}

/****************************************************************************************************************************************************/
/*                                                           O(N^2) Algorithm                                                                       */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                           O(C^N) Algorithm                                                                       */
/****************************************************************************************************************************************************/

#endif /* MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_SORTING_MERGESORT_H_ */
