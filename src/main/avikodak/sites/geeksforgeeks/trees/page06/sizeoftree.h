/****************************************************************************************************************************************************
 *  File Name                   : sizeoftree.h
 *  File Location               : /algos_v3/src/main/avikodak/sites/geeksforgeeks/trees/page06/sizeoftree.h
 *  Created on                  : May 1, 2017 :: 12:10:58 AM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : TODO
 ****************************************************************************************************************************************************/

#include <libv2/constants/constants.h>
#include <libv2/ds/treeds.h>

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

#ifndef MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_TREES_PAGE06_SIZEOFTREE_H_
#define MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_TREES_PAGE06_SIZEOFTREE_H_

/****************************************************************************************************************************************************/
/*                                                           O(LOGN) Algorithm                                                                      */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                            O(N) Algorithm                                                                        */
/****************************************************************************************************************************************************/
int getSizePreOrderTraversal(itNode *ptr) {
    if (ptr == null) {
        return 0;
    }
    return 1 + getSizePreOrderTraversal(ptr->left) + getSizePreOrderTraversal(ptr->right);
}

int getSizeInOrderTraversal(itNode *ptr) {
    if (ptr == null) {
        return 0;
    }
    return getSizeInOrderTraversal(ptr->left) + 1 + getSizeInOrderTraversal(ptr->right);
}

int getSizePostOrderTraversal(itNode *ptr) {
    if (ptr == null) {
        return 0;
    }
    return getSizePostOrderTraversal(ptr->left) + getSizePostOrderTraversal(ptr->right) + 1;
}

int getSizeOfTreeIterativePreOrder(itNode *ptr) {
    if (ptr == null) {
        return 0;
    }
    stack<itNode *> auxSpace;
    auxSpace.push(ptr);
    itNode *currentNode;
    int size = 0;
    while (!auxSpace.empty()) {
        currentNode = auxSpace.top();
        auxSpace.pop();
        size++;
        if (currentNode->right != null) {
            auxSpace.push(currentNode->right);
        }
        if (currentNode->left != null) {
            auxSpace.push(currentNode->left);
        }
    }
    return size;
}

int getSizeOfTreeMorrisPreOrder(itNode *ptr) {
    if (ptr == null) {
        return 0;
    }
    itNode *currentNode = ptr;
    itNode *temp;
    int size = 0;
    while (currentNode != null) {
        if (currentNode->left != null) {
            temp = currentNode->left;
            while (temp->right != null && temp->right != currentNode) {
                temp = temp->right;
            }
            if (temp->right == null) {
                size++;
                temp->right = currentNode;
                currentNode = currentNode->left;
            } else {
                temp->right = null;
                currentNode = currentNode->right;
            }
        } else {
            size++;
            currentNode = currentNode->right;
        }
    }
    return size;
}

int getSizeOfTreeInOrderTraversalIterative(itNode *ptr) {
    if (ptr == null) {
        return 0;
    }
    stack<itNode *> auxSpace;
    itNode *currentNode = ptr;
    int size = 0;
    while (!auxSpace.empty() || currentNode != null) {
        if (currentNode != null) {
            auxSpace.push(currentNode);
            currentNode = currentNode->left;
        } else {
            currentNode = auxSpace.top();
            auxSpace.pop();
            size++;
            currentNode = currentNode->right;
        }
    }
    return size;
}

int getSizeOfTreeMorrisInOrder(itNode *ptr) {
    if (ptr == null) {
        return 0;
    }
    int size = 0;
    itNode *currentNode = ptr;
    itNode *temp;
    while (currentNode != null) {
        if (currentNode->left != null) {
            temp = currentNode->left;
            while (temp->right != null && temp->right != currentNode) {
                temp = temp->right;
            }
            if (temp->right == null) {
                temp->right = currentNode;
                currentNode = currentNode->left;
            } else {
                size++;
                temp->right = null;
                currentNode = currentNode->right;
            }
        } else {
            size++;
            currentNode = currentNode->right;
        }
    }
    return size;
}

int getSizeOfTreePostOrderIterativeTwoStacks(itNode *ptr) {
    if (ptr == null) {
        return 0;
    }
    stack<itNode *> primaryAuxSpace, secondaryAuxSpace;
    primaryAuxSpace.push(ptr);
    itNode *currentNode;
    while (!primaryAuxSpace.empty()) {
        currentNode = primaryAuxSpace.top();
        primaryAuxSpace.pop();
        secondaryAuxSpace.push(currentNode);
        if (currentNode->left != null) {
            primaryAuxSpace.push(currentNode->left);
        }
        if (currentNode->right != null) {
            primaryAuxSpace.push(currentNode->right);
        }
    }
    return secondaryAuxSpace.size();
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

#endif /* MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_TREES_PAGE06_SIZEOFTREE_H_ */
