/****************************************************************************************************************************************************
 *  File Name                   : uglynumbers.h
 *  File Location               : /algos_v3/src/main/avikodak/sites/geeksforgeeks/practice/basic/uglynumbers.h
 *  Created on                  : Jul 27, 2017 :: 6:54:35 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://practice.geeksforgeeks.org/problems/ugly-numbers/0
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

#ifndef MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_BASIC_UGLYNUMBERS_H_
#define MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_BASIC_UGLYNUMBERS_H_

long long int getUglyNumber(long long int userInput) {
    if (userInput == 1) {
        return 1;
    }
    long long int result = 1;
    vector<long long int> computedValues;
    computedValues.push_back(1);
    long long int currentIndexOf2 = 0, currentIndexOf3 = 0, currrentIndexOf5 = 0;
    long long int prevResult;
    for (long long int counter = 0; counter < userInput - 1;) {
        result = min(computedValues[currentIndexOf2] * 2, min(computedValues[currentIndexOf3] * 3, computedValues[currrentIndexOf5] * 5));
        if (result == computedValues[currentIndexOf2] * 2) {
            currentIndexOf2++;
        } else if (result == computedValues[currentIndexOf3] * 3) {
            currentIndexOf3++;
        } else {
            currrentIndexOf5++;
        }
        if (computedValues[counter] != result) {
            computedValues.push_back(result);
            counter++;
        }
    }
    return result;
}

void solveProblem() {
    unsigned int testCases;
    long long int nValue;
    long long int input;
    scanf("%u", &testCases);
    while (testCases--) {
        scanf("%lld", &nValue);
        printf("%lld\n", getUglyNumber(nValue));
    }
}

#endif /* MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_BASIC_UGLYNUMBERS_H_ */
