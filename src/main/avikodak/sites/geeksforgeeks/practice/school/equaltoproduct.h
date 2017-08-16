/****************************************************************************************************************************************************
 *  File Name                   : equaltoproduct.h
 *  File Location               : /algos_v3/src/main/avikodak/sites/geeksforgeeks/practice/school/equaltoproduct.h
 *  Created on                  : Aug 16, 2017 :: 9:20:59 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : http://practice.geeksforgeeks.org/problems/equal-to-product/0
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

#ifndef MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_SCHOOL_EQUALTOPRODUCT_H_
#define MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_SCHOOL_EQUALTOPRODUCT_H_

bool doesProductExists(vector<long long int> userInput, long long int product) {
    if (userInput.size() < 2) {
        return false;
    }
    long long int currentProduct;
    sort(userInput.begin(), userInput.end());
    unsigned int frontCrawler = 0, rearCrawler = userInput.size() - 1;
    while (frontCrawler < rearCrawler) {
        currentProduct = userInput[frontCrawler] * userInput[rearCrawler];
        if (currentProduct == product) {
            return true;
        } else if (currentProduct < product) {
            frontCrawler++;
        } else {
            rearCrawler--;
        }
    }
    return false;
}

void solveProblem() {
    unsigned int testCases, size;
    long long int input, product;
    vector<long long int> userInput;
    scanf("%u", &testCases);
    while (testCases--) {
        scanf("%u", &size);
        scanf("%lld", &product);
        userInput.clear();
        for (unsigned int counter = 0; counter < size; counter++) {
            scanf("%lld", &input);
            userInput.push_back(input);
        }
        printf("%s\n", doesProductExists(userInput, product) ? "Yes" : "No");
    }
}

#endif /* MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_SCHOOL_EQUALTOPRODUCT_H_ */
