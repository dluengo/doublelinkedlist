#include "DLList.h"

#include <stdio.h>
#include <assert.h>

void print_int(void *int_to_print) {
    assert(int_to_print != NULL);
    printf("%8d", *(int *)int_to_print);
    return;
}

// Simple tests. We test for correct cases, but we are missing testing error
// cases. Again, very simple.
int main(int argc, char *argv[]) {
    DLList_t *list1, *list2, *empty_list, *one_elem_list, *two_elem_list;
    const unsigned int VEC_SIZE = 107;
    const unsigned int VAL_STEP = 7;
    const int BASE_VAL = -413;
    int vec[VEC_SIZE], idx, val;
    int *ptr_elem1, *ptr_elem2, err;

    list1 = DLList_Create();
    assert(list1 != NULL);
    list2 = DLList_Create();
    assert(list2 != NULL);
    empty_list = DLList_Create();
    assert(empty_list != NULL);
    one_elem_list = DLList_Create();
    assert(one_elem_list != NULL);
    two_elem_list = DLList_Create();
    assert(two_elem_list != NULL);

    // Fill the vec with values.
    for (idx = 0, val = BASE_VAL; idx < VEC_SIZE; idx++, val += VAL_STEP) {
        vec[idx] = val;
    }
    
    // Fill the lists with values.
    for (idx = 0; idx < VEC_SIZE; idx++) {
        err = DLList_Append(list1, &vec[idx]);
        assert(err == 0);

        err = DLList_Append(list2, &vec[VEC_SIZE - idx-1]);
        assert(err == 0);
    }

    err = DLList_Append(one_elem_list, &vec[0]);
    assert(err == 0);

    err = DLList_Append(two_elem_list, &vec[0]);
    assert(err == 0);
    err = DLList_Append(two_elem_list, &vec[1]);
    assert(err == 0);

    // Check lists sizes.
    assert(DLList_Size(list1) == VEC_SIZE);
    assert(DLList_Size(list2) == VEC_SIZE);
    assert(DLList_Size(empty_list) == 0);
    assert(DLList_Size(one_elem_list) == 1);
    assert(DLList_Size(two_elem_list) == 2);

    // Check the values in the list.
    for (idx = 0; idx < VEC_SIZE; idx++) {
        ptr_elem1 = (int *)DLList_Access(list1, idx);
        ptr_elem2 = (int *)DLList_Access(list2, VEC_SIZE - idx-1);

        assert(ptr_elem1 != NULL && ptr_elem2 != NULL);
        assert(*ptr_elem1 == *ptr_elem2);
    }

    // Print the lists.
    DLList_Print(list1, print_int);
    DLList_Print(list2, print_int);
    DLList_Print(empty_list, print_int);
    DLList_Print(one_elem_list, print_int);
    DLList_Print(two_elem_list, print_int);

    // Destroy the lists.
    DLList_Destroy(list1);
    DLList_Destroy(list2);
    DLList_Destroy(empty_list);
    DLList_Destroy(one_elem_list);
    DLList_Destroy(two_elem_list);

    return 0;
}
