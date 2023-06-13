#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <strings.h>
#include "unity.h"
#include "login.h"

void setUp() {
    // Set up any necessary test fixtures
}

void tearDown() {
    // Clean up any resources allocated in setUp()
}

void test_authenticate_validCredentials_shouldReturnTrue() {
    TEST_ASSERT_TRUE(authenticate("admin", "admin"));
}

void test_authenticate_invalidCredentials_shouldReturnFalse() {
    TEST_ASSERT_FALSE(authenticate("asdf", "asdf"));
}

void test_performLogin_validCredentials_shouldSetLoggedIn() {
    performLogin();
    TEST_ASSERT_TRUE(isLoggedIn());
}

void test_performLogin_invalidCredentials_shouldNotSetLoggedIn() {
    performLogin();
    TEST_ASSERT_FALSE(isLoggedIn());
}

void test_registerUser_validAdminCredentials_shouldRegisterUser() {
    // Assuming "admin" and "admin" are already registered in the users.csv file
    registerUser();
    // Check if the newly registered user exists in the users array
    TEST_ASSERT_TRUE(authenticate("newuser", "newpassword"));
}

void test_registerUser_invalidAdminCredentials_shouldNotRegisterUser() {
    registerUser();
    // Check if the newly registered user does not exist in the users array
    TEST_ASSERT_FALSE(authenticate("newuser", "newpassword"));
}

int main() {
    UNITY_BEGIN();

    RUN_TEST(test_authenticate_validCredentials_shouldReturnTrue);
    RUN_TEST(test_authenticate_invalidCredentials_shouldReturnFalse);
    RUN_TEST(test_performLogin_validCredentials_shouldSetLoggedIn);
    RUN_TEST(test_performLogin_invalidCredentials_shouldNotSetLoggedIn);
    RUN_TEST(test_registerUser_validAdminCredentials_shouldRegisterUser);
    RUN_TEST(test_registerUser_invalidAdminCredentials_shouldNotRegisterUser);

    UNITY_END();

    return 0;
}
