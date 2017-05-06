/****************************************************************************************************************************************************
 *  File Name                   : treetraversals.h
 *  File Location               : /algos_v3/src/main/avikodak/sites/geeksforgeeks/trees/page06/treetraversals.h
 *  Created on                  : Apr 30, 2017 :: 11:40:44 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : TODO
 ****************************************************************************************************************************************************/

#include <libv2/constants/constants.h>

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

#ifndef MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_TREES_PAGE06_TREETRAVERSALS_H_
#define MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_TREES_PAGE06_TREETRAVERSALS_H_

/****************************************************************************************************************************************************/
/*                                                           O(LOGN) Algorithm                                                                      */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                            O(N) Algorithm                                                                        */
/****************************************************************************************************************************************************/

/*
 *
 * Algorithm
 * =========
 * - Traverses and prints the nodes of binary
 * tree in pre order fashion
 *
 * Input
 * =====
 * - Tree node
 *
 * Return
 * ======
 * - void
 *
 * Testing status
 * ==============
 * - Not yet done
 *
 */
void preOrderTraversal(itNode *ptr) {
    if (ptr == null) {
        return;
    }
    printf("%d\t", ptr->value);
    preOrderTraversal(ptr->left);
    preOrderTraversal(ptr->right);
}

/*
 *
 * Algorithm
 * =========
 * - Traverses and prints the nodes of binary
 * tree in pre order fashion with the help of
 * aux space and iteratively
 *
 * Input
 * =====
 * - Tree node
 *
 * Return
 * ======
 * - void
 *
 * Testing status
 * ==============
 * - Not yet done
 */
void preOrderTraversalIterative(itNode *ptr) {
    if (ptr == null) {
        return;
    }
    stack<itNode *> auxSpace;
    itNode *currentNode;
    auxSpace.push(ptr);
    while (!auxSpace.empty()) {
        currentNode = auxSpace.top();
        auxSpace.pop();
        printf("%d\t", currentNode->value);
        if (currentNode->right != null) {
            auxSpace.push(currentNode->right);
        }
        if (currentNode->left != null) {
            auxSpace.push(currentNode->left);
        }
    }
}

/*
 *
 * Algorithm
 * =========
 * - Traverses and prints the nodes of binary
 * tree in pre order fashion using an algorithm
 * devised by Morris
 *
 * Input
 * =====
 * - Tree node
 *
 * Return
 * ======
 * - void
 *
 * Testing status
 * ==============
 * - Not yet done
 */
void morrisPreOrderTraversal(itNode *ptr) {
    if (ptr == null) {
        return;
    }
    itNode *currentNode = ptr;
    itNode *temp;
    while (currentNode != null) {
        if (currentNode->left != null) {
            temp = currentNode->left;
            while (temp->right != null && temp->right != currentNode) {
                temp = temp->right;
            }
            if (temp->right == null) {
                printf("%d\t", temp->value);
                temp->right = currentNode;
            } else {
                temp->right = null;
            }
        } else {
            printf("%d\t", currentNode->value);
            currentNode = currentNode->right;
        }
    }
}

/*
 *
 * Algorithm
 * =========
 * - Traverses and prints the nodes of binary
 * tree in in order fashion
 *
 * Input
 * =====
 * - Tree node
 *
 * Return
 * ======
 * - void
 *
 * Testing status
 * ==============
 * - Not yet done
 */
void inOrderTraversal(itNode *ptr) {
    if (ptr == null) {
        return;
    }
    inOrderTraversal(ptr->left);
    printf("%d\t", ptr->value);
    inOrderTraversal(ptr->right);
}

void inOrderTraversalIterative(itNode *ptr) {
    if (ptr == null) {
        return;
    }
    stack<itNode *> auxSpace;
    itNode *currentNode;
    while (!auxSpace.empty() || currentNode != null) {
        if (currentNode != null) {
            auxSpace.push(currentNode);
            currentNode = currentNode->left;
        } else {
            currentNode = auxSpace.top();
            auxSpace.pop();
            printf("%d\t", currentNode->value);
            currentNode = currentNode->right;
        }
    }
}

void postOrderTraversal(itNode *ptr) {
    if (ptr == null) {
        return;
    }
    postOrderTraversal(ptr->left);
    postOrderTraversal(ptr->right);
    printf("%d\t", ptr->value);
}

void levelOrderTraversal(itNode *ptr) {
    if (ptr == null) {
        return;
    }
    queue<itNode *> auxSpace;
    itNode *currentNode;
    auxSpace.push(ptr);
    while (!auxSpace.empty()) {
        currentNode = auxSpace.front();
        auxSpace.pop();
        printf("%d\t", currentNode->value);
        if (currentNode->left != null) {
            auxSpace.push(currentNode->left);
        }
        if (currentNode->right != null) {
            auxSpace.push(currentNode->right);
        }
    }
}
/****************************************************************************************************************************************************/
/*                                                          O(N*LOGN) Algorithm                                                                     */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                           O(N^2) Algorithm                                                                       */
/****************************************************************************************************************************************************/
/*
 *
 * Algorithm
 * =========
 * - Prints the nodes present at the required level
 * for subtree from left to right
 *
 * Input
 * =====
 * - Tree node
 *
 * Return
 * ======
 * - void
 *
 * Testing status
 * ==============
 * - Not yet done
 */
void printLevel(itNode *ptr, int level) {
    if (ptr == null) {
        return;
    }
    if (level == 0) {
        printf("%d\t", ptr->value);
        return;
    }
    printLevel(ptr->left, level - 1);
    printLevel(ptr->right, level - 1);
}

/*
 *
 * Algorithm
 * =========
 * - Traverses and prints the nodes of binary
 * tree in pre order fashion
 *
 * Input
 * =====
 * - Tree node
 *
 * Return
 * ======
 * - void
 *
 * Testing status
 * ==============
 * - Not yet done
 */
int getHeightOfTree(itNode *ptr) {
    if (ptr == null) {
        return 0;
    }
    return max(getHeightOfTree(ptr->left), getHeightOfTree(ptr->right)) + 1;
}

/*
 *
 * Algorithm
 * =========
 * - Prints the nodes in the level order
 * from top to bottom
 *
 * Input
 * =====
 * - Tree node
 *
 * Return
 * ======
 * - void
 *
 * Testing status
 * ==============
 * - Not yet done
 */
void levelOrderTraversalON2(itNode *ptr) {
    if (ptr == null) {
        return;
    }
    int height = getHeightOfTree(ptr);
    for (unsigned int levelCounter = 0; levelCounter < height; levelCounter++) {
        printLevel(ptr, levelCounter);
    }
}

/****************************************************************************************************************************************************/
/*                                                           O(C^N) Algorithm                                                                       */
/****************************************************************************************************************************************************/

#endif /* MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_TREES_PAGE06_TREETRAVERSALS_H_ */
