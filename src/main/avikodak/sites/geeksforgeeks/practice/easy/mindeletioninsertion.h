/****************************************************************************************************************************************************
 *  File Name                   : mindeletioninsertion.h
 *  File Location               : /algos_v3/src/main/avikodak/sites/geeksforgeeks/practice/easy/mindeletioninsertion.h
 *  Created on                  : Aug 19, 2017 :: 12:59:38 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions/0
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
#include <limits.h>
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

#ifndef MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_EASY_MINDELETIONINSERTION_H_
#define MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_EASY_MINDELETIONINSERTION_H_

long long lcs(string firstUserInput, string secondUserInput) {
    long long int auxSpace[firstUserInput.size() + 1][secondUserInput.size() + 1];
    for (unsigned int outerCrawler = 0; outerCrawler < firstUserInput.size() + 1; outerCrawler++) {
        for (unsigned int innerCrawler = 0; innerCrawler < secondUserInput.size() + 1; innerCrawler++) {
            if (outerCrawler == 0 || innerCrawler == 0) {
                auxSpace[outerCrawler][innerCrawler] = 0;
            } else if (firstUserInput[outerCrawler - 1] == secondUserInput[innerCrawler - 1]) {
                auxSpace[outerCrawler][innerCrawler] = 1 + auxSpace[outerCrawler - 1][innerCrawler - 1];
            } else {
                auxSpace[outerCrawler][innerCrawler] = max(auxSpace[outerCrawler - 1][innerCrawler], auxSpace[outerCrawler][innerCrawler - 1]);
            }
        }
    }
    return auxSpace[firstUserInput.size()][secondUserInput.size()];
}

void solveProblem() {
    unsigned int testCases, firstSize, secondSize;
    long long int lcsCount;
    string firstInput, secondInput;
    scanf("%u", &testCases);
    while (testCases--) {
        cin >> firstSize >> secondSize;
        cin >> firstInput >> secondInput;
        lcsCount = lcs(firstInput, secondInput);
        printf("%lld\n", (firstInput.size() + secondInput.size() - 2 * lcsCount));
    }
}

#endif /* MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_EASY_MINDELETIONINSERTION_H_ */
