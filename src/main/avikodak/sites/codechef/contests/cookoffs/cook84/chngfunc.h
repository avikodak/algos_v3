/****************************************************************************************************************************************************
 *  File Name                   : chngfunc.h
 *  File Location               : /algos_v3/src/main/avikodak/sites/codechef/contests/cookoffs/cook84/chngfunc.h
 *  Created on                  : Jul 25, 2017 :: 5:04:46 PM
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

#ifndef MAIN_AVIKODAK_SITES_CODECHEF_CONTESTS_COOKOFFS_COOK84_CHNGFUNC_H_
#define MAIN_AVIKODAK_SITES_CODECHEF_CONTESTS_COOKOFFS_COOK84_CHNGFUNC_H_

void solveProblem() {
    long long int A, B, currentSum;
    scanf("%lld %lld", &A, &B);
    int result = 0;
    vector<int> squares;
    vector<int>::iterator itToSquares;
    for (long long int crawler = 1; crawler <= A; crawler++) {
        squares.push_back(crawler * crawler);
    }
    for(long long int outerCounter = 0;outerCounter < squares.size();outerCounter++){
        for(long long int innerCounter = outerCounter+1;innerCounter < squares.size();innerCounter++){
            if(squares[innerCounter] - squares[outerCounter] <= B){
                result++;
            }else{
                break;
            }
        }
    }
    printf("%d",result);
}
#endif /* MAIN_AVIKODAK_SITES_CODECHEF_CONTESTS_COOKOFFS_COOK84_CHNGFUNC_H_ */
