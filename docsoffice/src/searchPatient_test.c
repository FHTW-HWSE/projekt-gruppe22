#include <stdio.h>
#include <stdbool.h>
#include "unity.h"
#include "searchPatient.h"

void setUp(void) {
    // Empty setUp function
}

void tearDown(void) {
    // Empty tearDown function
}

void test_searchPatient() {
    // Test case 1: Search successful
    Patient patients[3];  // Assuming an array of 3 patients
    bool result = searchPatient(patients, 3);
    TEST_ASSERT_TRUE(result);

    // Test case 2: Search unsuccessful
    Patient emptyPatients[0];  // Assuming an empty array
    result = searchPatient(emptyPatients, 0);
    TEST_ASSERT_FALSE(result);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_searchPatient);
    UNITY_END();

    return 0;
}
