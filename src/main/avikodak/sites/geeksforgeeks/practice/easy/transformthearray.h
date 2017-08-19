/****************************************************************************************************************************************************
 *  File Name                   : transformthearray.h
 *  File Location               : /algos_v3/src/main/avikodak/sites/geeksforgeeks/practice/easy/transformthearray.h
 *  Created on                  : Aug 19, 2017 :: 6:29:24 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : http://practice.geeksforgeeks.org/problems/transform-the-array/0
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

#ifndef MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_EASY_TRANSFORMTHEARRAY_H_
#define MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_EASY_TRANSFORMTHEARRAY_H_

void transformArray(vector<long long int> &userInput) {
    if(userInput.size() <= 1){
        return;
    }
    int frontCrawler = 0, rearCrawler = 1;
    while (frontCrawler < userInput.size()) {
        if (userInput[frontCrawler] != 0) {
            rearCrawler = frontCrawler+1;
            while (rearCrawler < userInput.size() && userInput[rearCrawler] == 0) {
                rearCrawler++;
            }
            if (rearCrawler < userInput.size() && userInput[rearCrawler] == userInput[frontCrawler]) {
                userInput[frontCrawler] *= 2;
                userInput[rearCrawler] = 0;
            }else{
                frontCrawler++;
            }
        }else{
            frontCrawler++;
        }
    }
    int fillCounter = -1;
    for (unsigned int counter = 0; counter < userInput.size(); counter++) {
        if(userInput[counter] != 0){
            userInput[++fillCounter] = userInput[counter];
        }
    }
    while(fillCounter < userInput.size()) {
        userInput[++fillCounter] = 0;
    }
}

void solveProblem() {
    unsigned int testCases, size;
    long long int input;
    vector<long long int> userInput;
    scanf("%u", &testCases);
    while (testCases--) {
        scanf("%u", &size);
        userInput.clear();
        for (unsigned int counter = 0; counter < size; counter++) {
            scanf("%lld", &input);
            userInput.push_back(input);
        }
        transformArray(userInput);
        for (unsigned int counter = 0; counter < size; counter++) {
            printf("%lld ", userInput[counter]);
        }
        printf("\n");
    }
}

#endif /* MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_EASY_TRANSFORMTHEARRAY_H_ */
