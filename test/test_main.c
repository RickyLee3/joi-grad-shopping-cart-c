#include <stdio.h>
#include <CUnit/Basic.h>
#include "./shopping_cart_test.h"

int main(int argc, char **argv) {
    CU_pSuite pSuite = NULL;

    if (CUE_SUCCESS != CU_initialize_registry()) {
        return CU_get_error();
    }

    pSuite = CU_add_suite("ShoppingCartTest", NULL, NULL);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (NULL ==
        CU_add_test(pSuite, "calculate price with no discount",
                    shopping_cart_test_should_calculate_price_with_no_discount) ||
        NULL == CU_add_test(pSuite, "calculate loyalty points with no discount",
                            shopping_cart_test_should_calculate_loyalty_points_with_no_discount) ||
        NULL == CU_add_test(pSuite, "calculate price for 10 percent discount",
                            shopping_cart_test_should_calculate_price_for_10_percent_discount) ||
        NULL == CU_add_test(pSuite, "calculate loyalty points for 10 percent discount",
                            shopping_cart_test_should_calculate_loyalty_points_for_10_percent_discount) ||
        NULL == CU_add_test(pSuite, "calculate price for 15 percent discount",
                            shopping_cart_test_should_calculate_price_for_15_percent_discount) ||
        NULL == CU_add_test(pSuite, "calculate loyalty points for 15 percent discount",
                            shopping_cart_test_should_calculate_loyalty_points_for_15_percent_discount)) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
