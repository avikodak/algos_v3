/****************************************************************************************************************************************************
 *  File Name                   : sillutils.h
 *  File Location               : /algos_v3/src/libv3/utils/sillutils.h
 *  Created on                  : May 1, 2017 :: 12:07:01 AM
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
#include <libv2/common/commonincludes.h>
#include <libv2/constants/constants.h>
#include <libv2/ds/commonds.h>
#include <libv2/ds/graphds.h>
#include <libv2/ds/linkedlistds.h>
#include <libv2/ds/mathds.h>
#include <libv2/ds/treeds.h>
#include <libv2/utils/abtreeutil.h>
#include <libv2/utils/arrayutil.h>
#include <libv2/utils/avltreeutil.h>
#include <libv2/utils/bplustreeutil.h>
#include <libv2/utils/bstutil.h>
#include <libv2/utils/btreeutil.h>
#include <libv2/utils/commonutil.h>
#include <libv2/utils/dillutil.h>
#include <libv2/utils/graphutil.h>
#include <libv2/utils/ioutil.h>
#include <libv2/utils/mathutil.h>
#include <libv2/utils/redblacktreeutil.h>
#include <libv2/utils/sillutil.h>
#include <libv2/utils/treeutil.h>
#include <libv2/utils/trieutil.h>
#include <libv2/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/*                                                            USER DEFINED CONSTANTS                                                                */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef LIBV3_UTILS_SILLUTILS_H_
#define LIBV3_UTILS_SILLUTILS_H_

class sillUtil {
 private:
 public:
    sillNode *getSill(vector<int> userInput, int index = 0) {
        if (userInput.size() >= index) {
            return null;
        }
        sillNode *newNode = new sillNode(userInput[index]);
        newNode->next = getSill(userInput, index + 1);
        return newNode;
    }

    int getLengthOfSill(sillNode *head) {
        if (head == null) {
            return 0;
        }
        return 1 + getLengthOfSill(head->next);
    }

    sillNode *reverseSill(sillNode *head) {
        if (head != null && head->next != null) {
            reverseSill(head->next);
            head->next->next = head;
            head->next = null;
        }
        return head;
    }
};

#endif /* LIBV3_UTILS_SILLUTILS_H_ */
