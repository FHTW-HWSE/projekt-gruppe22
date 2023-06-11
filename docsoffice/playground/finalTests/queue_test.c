#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "unity.h"
#include "queue.h"

void setUp() {
    // Set up any resources if required
}

void tearDown() {
    // Clean up any resources if required
}

void test_loadQueue() {
    // Ensure that the queue is initially empty
    TEST_ASSERT_EQUAL(0, queueSize);

    // Load the queue from a file
    loadQueue();

    // Check the size of the loaded queue
    TEST_ASSERT_EQUAL(3, queueSize);

    // Check the elements in the loaded queue
    TEST_ASSERT_EQUAL_STRING("123456789", queue[0]);
    TEST_ASSERT_EQUAL_STRING("987654321", queue[1]);
    TEST_ASSERT_EQUAL_STRING("555555555", queue[2]);
}

void test_saveQueue() {
    // Clear the queue
    queueSize = 0;

    // Add some elements to the queue
    strcpy(queue[queueSize], "111111111");
    queueSize++;
    strcpy(queue[queueSize], "222222222");
    queueSize++;

    // Save the queue to a file
    saveQueue();

    // Load the saved queue from the file
    loadQueue();

    // Check the size of the loaded queue
    TEST_ASSERT_EQUAL(2, queueSize);

    // Check the elements in the loaded queue
    TEST_ASSERT_EQUAL_STRING("111111111", queue[0]);
    TEST_ASSERT_EQUAL_STRING("222222222", queue[1]);
}

void test_addPatientToQueue() {
    // Clear the queue
    queueSize = 0;

    // Add a patient to the empty queue
    addPatientToQueue();
    TEST_ASSERT_EQUAL(1, queueSize);
    TEST_ASSERT_EQUAL_STRING("123456789", queue[0]);

    // Add the same patient again
    addPatientToQueue();
    TEST_ASSERT_EQUAL(1, queueSize);  // Queue size should remain the same
    TEST_ASSERT_EQUAL_STRING("123456789", queue[0]);

    // Add a different patient
    strcpy(queue[queueSize], "987654321");
    queueSize++;
    addPatientToQueue();
    TEST_ASSERT_EQUAL(2, queueSize);
    TEST_ASSERT_EQUAL_STRING("123456789", queue[0]);
    TEST_ASSERT_EQUAL_STRING("987654321", queue[1]);
}

void test_dequeuePatient() {
    // Load the queue
    loadQueue();

    // Dequeue an existing patient
    bool result = dequeuePatient("123456789");
    TEST_ASSERT_TRUE(result);
    TEST_ASSERT_EQUAL(2, queueSize);
    TEST_ASSERT_EQUAL_STRING("987654321", queue[0]);
    TEST_ASSERT_EQUAL_STRING("555555555", queue[1]);

    // Dequeue a non-existent patient
    result = dequeuePatient("111111111");
    TEST_ASSERT_FALSE(result);
    TEST_ASSERT_EQUAL(2, queueSize);  // Queue size should remain the same
    TEST_ASSERT_EQUAL_STRING("987654321", queue[0]);
    TEST_ASSERT_EQUAL_STRING("555555555", queue[1]);
}

int main() {
    UNITY_BEGIN();

    RUN_TEST(test_loadQueue);
    RUN_TEST(test_saveQueue);
    RUN_TEST(test_addPatientToQueue);
    RUN_TEST(test_dequeuePatient);

    UNITY_END();
}
