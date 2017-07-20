/****************************************************************************************************************************************************
 *  File Name                   : mergetwosortedlists.h
 *  File Location               : /algos_v3/src/main/avikodak/sites/leetcode/easy/mergetwosortedlists.h
 *  Created on                  : Jul 20, 2017 :: 12:42:55 AM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : https://leetcode.com/problems/merge-two-sorted-lists/#/description
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

#ifndef MAIN_AVIKODAK_SITES_LEETCODE_EASY_MERGETWOSORTEDLISTS_H_
#define MAIN_AVIKODAK_SITES_LEETCODE_EASY_MERGETWOSORTEDLISTS_H_

/****************************************************************************************************************************************************/
/*                                                           O(LOGN) Algorithm                                                                      */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                            O(N) Algorithm                                                                        */
/****************************************************************************************************************************************************/
struct ListNode {
    int val;
    ListNode *next;
 public:
    ListNode(int x) {
        this->val = x;
        this->next = NULL;
    }
};

ListNode* mergeTwoLists(ListNode* firstInput, ListNode* secondInput) {
    ListNode *mergedList = new ListNode(INT_MAX);
    ListNode *crawler = mergedList;
    while (firstInput != null && secondInput != null) {
        if (firstInput->val < secondInput->val) {
            crawler->next = firstInput;
            firstInput = firstInput->next;
            crawler = crawler->next;
        } else {
            crawler->next = secondInput;
            secondInput = secondInput->next;
            crawler = crawler->next;
        }
        crawler->next = null;
    }
    if (firstInput != null) {
        crawler->next = firstInput;
    }
    if (secondInput != null) {
        crawler->next = secondInput;
    }
    return mergedList->next;
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

#endif /* MAIN_AVIKODAK_SITES_LEETCODE_EASY_MERGETWOSORTEDLISTS_H_ */
