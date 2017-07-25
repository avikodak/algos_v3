/****************************************************************************************************************************************************
 *  File Name                   : cfrtest.h
 *  File Location               : /algos_v3/src/main/avikodak/sites/codechef/beginner/cfrtest.h
 *  Created on                  : Jul 25, 2017 :: 11:39:20 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : https://www.codechef.com/problems/CFRTEST
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

#ifndef MAIN_AVIKODAK_SITES_CODECHEF_BEGINNER_CFRTEST_H_
#define MAIN_AVIKODAK_SITES_CODECHEF_BEGINNER_CFRTEST_H_

void solveProblem() {
    unsigned int testCases, size;
    long long int input;
    map<long long int, bool> visitedValues;
    scanf("%u", &testCases);
    while (testCases--) {
        scanf("%u", &size);
        visitedValues.clear();
        for (unsigned int counter = 0; counter < size; counter++) {
            scanf("%lld", &input);
            visitedValues.insert(pair<long long int, bool>(input, true));
        }
        printf("%d\n", visitedValues.size());
    }
}

#endif /* MAIN_AVIKODAK_SITES_CODECHEF_BEGINNER_CFRTEST_H_ */
