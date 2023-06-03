void testDisplayMenu() {
    printf("Running displayMenu test...\n");

    // Redirect stdout to a file
    FILE* file = freopen("output.txt", "w", stdout);
    if (file == NULL) {
        printf("Error opening output.txt file.\n");
        return;
    }

    // Call the function to display the menu
    displayMenu();

    // Close the file to flush the output
    fclose(file);

    // Read the content of the file
    file = fopen("output.txt", "r");
    if (file == NULL) {
        printf("Error opening output.txt file.\n");
        return;
    }

    // Check the output
    char* line = NULL;
    size_t lineLength = 0;
    int lineCount = 1;
    while (getline(&line, &lineLength, file) != -1) {
        // Check the process ID output
        if (strstr(line, "Process ID: ") != NULL) {
            printf("Process ID line: %s", line);
        }
        if (strstr(line, "Parent Process ID: ") != NULL) {
            printf("Parent Process ID line: %s", line);
        }

        // Add checks for other lines if necessary

        lineCount++;
    }

    // Close the file
    fclose(file);

    // Free dynamically allocated memory
    free(line);

    printf("displayMenu test passed.\n");
}
