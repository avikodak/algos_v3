/****************************************************************************************************************************************************
 *  File Name                   : insertionsort.h
 *  File Location               : /algos_v3/src/main/avikodak/sites/geeksforgeeks/sorting/insertionsort.h
 *  Created on                  : May 6, 2017 :: 12:19:05 PM
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

#ifndef MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_SORTING_INSERTIONSORT_H_
#define MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_SORTING_INSERTIONSORT_H_

/****************************************************************************************************************************************************/
/*                                                           O(N^2) Algorithm                                                                       */
/****************************************************************************************************************************************************/
void insertionSort(vector<int> &userInput) {
    if (userInput.size() < 2) {
        return;
    }
    int innerCrawler, key;
    for (unsigned int outerCrawler = 1; outerCrawler < userInput.size(); outerCrawler++) {
        innerCrawler = outerCrawler - 1;
        key = userInput[outerCrawler];
        while (innerCrawler >= 0 && userInput[innerCrawler] > userInput[innerCrawler + 1]) {
            userInput[innerCrawler + 1] = userInput[innerCrawler];
            innerCrawler--;
        }
        userInput[innerCrawler + 1] = key;
    }
}

#endif /* MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_SORTING_INSERTIONSORT_H_ */
