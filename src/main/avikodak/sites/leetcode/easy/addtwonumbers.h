/****************************************************************************************************************************************************
 *  File Name                   : addtwonumbers.h
 *  File Location               : /algos_v3/src/main/avikodak/sites/leetcode/easy/addtwonumbers.h
 *  Created on                  : Jul 16, 2017 :: 10:22:26 PM
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

#ifndef MAIN_AVIKODAK_SITES_LEETCODE_EASY_ADDTWONUMBERS_H_
#define MAIN_AVIKODAK_SITES_LEETCODE_EASY_ADDTWONUMBERS_H_

struct ListNode {
    int val;
    ListNode *next;
 public:
    ListNode(int val) {
        this->val = val;
        this->next = null;
    }
};

/****************************************************************************************************************************************************/
/*                                                           O(LOGN) Algorithm                                                                      */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                            O(N) Algorithm                                                                        */
/****************************************************************************************************************************************************/
ListNode *addTwoNumbers(ListNode *firstPtr, ListNode *secondPtr) {
    if (firstPtr == null) {
        return secondPtr;
    }
    if (secondPtr == null) {
        return firstPtr;
    }
    ListNode *result = null, *resultTailPtr;
    resultTailPtr = null;
    int currentSum = firstPtr->val + secondPtr->val;
    firstPtr = firstPtr->next;
    secondPtr = secondPtr->next;
    result = new ListNode((currentSum) % 10);
    resultTailPtr = result;
    int carry = currentSum / 10;
    while (firstPtr != null || secondPtr != null) {
        if (secondPtr == null) {
            currentSum = firstPtr->val + carry;
            firstPtr = firstPtr->next;
        } else if (firstPtr == null) {
            currentSum = secondPtr->val + carry;
            secondPtr = secondPtr->next;
        } else {
            currentSum = firstPtr->val + secondPtr->val + carry;
            firstPtr = firstPtr->next;
            secondPtr = secondPtr->next;
        }
        resultTailPtr->next = new ListNode(currentSum % 10);
        carry = currentSum / 10;
        resultTailPtr = resultTailPtr->next;
    }
    while (carry > 0) {
        resultTailPtr->next = new ListNode(carry % 10);
        resultTailPtr = resultTailPtr->next;
        carry /= 10;
    }
    return result;
}

/****************************************************************************************************************************************************/
/*                                                          O(N*LOGN) Algorithm                                                                     */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                           O(N^2) Algorithm                                                                       */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                           O(C^N) Algorithm                                                                       */
/****************************************************************************************************************************************************/

#endif /* MAIN_AVIKODAK_SITES_LEETCODE_EASY_ADDTWONUMBERS_H_ */
